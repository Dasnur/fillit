/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:39:30 by atote             #+#    #+#             */
/*   Updated: 2019/10/07 15:48:11 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*swap_bufs(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	free(s1);
	s1 = tmp;
	return (s1);
}

static int			mread_buf(char **tmp, char *buf, char **buffres, char **line)
{
	int		i;

	i = 0;
	if (*tmp != NULL)
	{
		*buffres = swap_bufs(*buffres, *tmp);
		free(*tmp);
		*tmp = NULL;
	}
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
		{
			*tmp = ft_strsub(&buf[0], 0, i);
			*buffres = swap_bufs(*buffres, *tmp);
			*line = *buffres;
			free(*tmp);
			*tmp = ft_strdup(&buf[i + 1]);
			return (1);
		}
		i++;
	}
	*buffres = swap_bufs(*buffres, &buf[0]);
	return (0);
}

static int			mtmp_buf(char **tmp, char **line)
{
	char	*buffres;
	int		i;

	if (*tmp != NULL)
	{
		i = 0;
		while ((*tmp)[i] != '\0')
		{
			if ((*tmp)[i] == '\n')
			{
				*line = ft_strsub(&((*tmp)[0]), 0, i);
				buffres = *tmp;
				*tmp = ft_strdup(&((*tmp)[i + 1]));
				free(buffres);
				buffres = NULL;
				return (1);
			}
			i++;
		}
	}
	return (0);
}

static int			last_string(char **tmp, char **buffres, char **line)
{
	if ((*buffres)[0] != '\0')
	{
		*line = *buffres;
		return (1);
	}
	if (*tmp != NULL)
	{
		if ((*tmp)[0] != '\0')
		{
			free(*buffres);
			*buffres = ft_strdup(*tmp);
			*line = *buffres;
			free(*tmp);
			*tmp = NULL;
			return (1);
		}
	}
	return (0);
}

int			        get_next_line(const int fd, char **line)
{
	int				ret;
	static char		*tmp[2147483648];
	char			buf[BUFF_SIZE + 1];
	char			*buffres;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (!(buffres = ft_strnew(1)))
		return (-1);
	*line = NULL;
	if (mtmp_buf(&(tmp[fd]), line))
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (mread_buf(&(tmp[fd]), &buf[0], &buffres, line))
			return (1);
	}
	if (last_string(&(tmp[fd]), &buffres, line))
		return (1);
	if (ret < 0)
		return (-1);
	return (0);
}
