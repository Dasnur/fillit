/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:53:54 by atote             #+#    #+#             */
/*   Updated: 2019/10/19 15:02:43 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(char **map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(map[i]);
		i++;
	}
}
