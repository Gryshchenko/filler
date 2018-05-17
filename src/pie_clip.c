/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pie_clip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:42:34 by vgryshch          #+#    #+#             */
/*   Updated: 2018/03/30 12:07:51 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void		ft_piece_clip_x(t_filler *list, t_pie *a_p)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	a_p->max_x = 0;
	a_p->min_x = list->p_content;
	while (a_p->arr_p[i])
	{
		c = 0;
		while (a_p->arr_p[i][c])
		{
			if (a_p->arr_p[i][c] == '*')
			{
				if (c < a_p->min_x)
					a_p->min_x = c;
				if (c > a_p->max_x)
					a_p->max_x = c;
			}
			c++;
		}
		i++;
	}
}

void		ft_piece_clip_y(t_filler *list, t_pie *a_p)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	a_p->max_y = 0;
	a_p->min_y = list->p_index;
	while (a_p->arr_p[i])
	{
		c = 0;
		while (a_p->arr_p[i][c])
		{
			if (a_p->arr_p[i][c] == '*')
			{
				if (i < a_p->min_y)
					a_p->min_y = i;
				if (i > a_p->max_y)
					a_p->max_y = i;
			}
			c++;
		}
		i++;
	}
}
