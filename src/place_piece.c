/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:23:41 by vgryshch          #+#    #+#             */
/*   Updated: 2018/03/31 12:47:59 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void		ft_piece_addition(t_filler *l, t_pie *a_p, int *s, int *b)
{
	*s = 0;
	*b = 0;
	l->player_c = 0;
	l->enemy_c = 0;
	l->player_x = ft_valid_player(l);
	l->enemy_x = ft_valid_char(l);
	l->arr_width = *b;
	l->arr_hight = *s;
	a_p->min_step = 0;
}

void		ft_piece_cord_return(t_filler *l, t_map *a, t_pie *a_p)
{
	if (l->player_c == 1 && l->enemy_c == 0)
	{
		if (a_p->min_step < a_p->min_temp)
		{
			a_p->min_temp = a_p->min_step;
			a_p->r_y = a->i;
			a_p->r_x = a->l;
		}
	}
}

void		ft_piece_check_posit(t_filler *l, t_map *a, int i, int c)
{
	if (a->arr[i][c] == l->player || a->arr[i][c] == l->player_x)
		l->player_c++;
	if (a->arr[i][c] == l->enemy_copy || a->arr[i][c] == l->enemy_x)
		l->enemy_c++;
}

void		ft_piece_find_all(t_filler *l, t_map *a, t_pie *a_p)
{
	int		s;
	int		b;
	int		i;
	int		c;

	i = a->i;
	c = a->l;
	ft_piece_addition(l, a_p, &s, &b);
	while (a_p->arr_p[s] && a->arr[i])
	{
		while (a_p->arr_p[s][b] && a->arr[i][c])
		{
			if (a_p->arr_p[s][b] == '*')
				ft_piece_check_posit(l, a, i, c);
			a_p->min_step += a->arr[i][c];
			b++;
			c++;
		}
		b = 0;
		c = a->l;
		s++;
		i++;
	}
	ft_piece_cord_return(l, a, a_p);
}

void		ft_piece_place(t_filler *list, t_pie *a_p, t_map *a)
{
	a->i = 0;
	a->l = 0;
	a_p->r_x = -1;
	a_p->r_y = -1;
	a_p->min_temp = 2147483647;
	while (a->arr[a->i] && (a->i + a_p->max_y) < list->index)
	{
		a->l = 0;
		while (a->arr[a->i][a->l] && (a->l + a_p->max_x) < list->content)
		{
			ft_piece_find_all(list, a, a_p);
			a->l++;
		}
		a->i++;
	}
	ft_putnbr(a_p->r_y);
	ft_putchar(' ');
	ft_putnbr(a_p->r_x);
	ft_putchar('\n');
	ft_arraydell_u(a->arr);
	ft_arraydell(a_p->arr_p);
	ft_all_to_zero(list, a_p, a);
}
