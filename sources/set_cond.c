/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cond.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:01:02 by atote             #+#    #+#             */
/*   Updated: 2019/10/26 16:44:01 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			new_recursive_fill(t_tetro *t, t_options *m, int *k)
{
	if (t[*k].si == m->s)
	{
		t[*k].sj = 0;
		t[*k].si = 0;
		if (*k == 0)
		{
			ft_free_array(m->sq, m->s);
			m->s = m->s + 1;
			m->sq = new_map(m->s);
			return (1);
		}
		*k = *k - 1;
		t[*k].sj = t[*k].sj + 1;
		m->ch = m->ch - 1;
		free_last_tetro(m->sq, m->s, m->ch);
	}
	return (0);
}

int			mem_clear(char ***map, int i, int flag)
{
	ft_free_array(*map, i);
	free(*map);
	if (flag == 0)
		return (-1);
	return (0);
}

void		next_step(t_tetro *t, int k)
{
	t[k].sj = 0;
	t[k].si = t[k].si + 1;
}

int			set_cond(t_tetro *t, t_options *m, int *k)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (t[*k].si + t[*k].pt[i][0] >= m->s || DIFF)
		{
			if (t[*k].sj < m->s - 1)
				t[*k].sj = t[*k].sj + 1;
			else
				next_step(t, *k);
			if (new_recursive_fill(t, m, k))
				return (1);
			i = 0;
		}
		else if (D1)
		{
			t[*k].sj = t[*k].sj + 1;
			i = 0;
		}
		else
			i++;
	}
	return (0);
}
