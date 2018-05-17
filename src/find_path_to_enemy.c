/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path_to_enemy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:43:44 by vgryshch          #+#    #+#             */
/*   Updated: 2018/03/31 12:47:52 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static void			ft_find_and_replace(t_filler *l, t_map *a, int i, int c)
{
	if (i > -1 && (c + 1) < l->content && a->arr[i][c + 1] == '.')
		a->arr[i][c + 1] = l->counter;
	if (i > -1 && (c - 1) > -1 && a->arr[i][c - 1] == '.')
		a->arr[i][c - 1] = l->counter;
	if ((i - 1) > -1 && c < l->content && a->arr[i - 1][c] == '.')
		a->arr[i - 1][c] = l->counter;
	if ((i - 1) > -1 && (c - 1) > -1 && a->arr[i - 1][c - 1] == '.')
		a->arr[i - 1][c - 1] = l->counter;
	if ((i - 1) > -1 && (c + 1) < l->content && a->arr[i - 1][c + 1] == '.')
		a->arr[i - 1][c + 1] = l->counter;
	if ((i + 1) < l->index && c < l->content && a->arr[i + 1][c] == '.')
		a->arr[i + 1][c] = l->counter;
	if ((i + 1) < l->index && (c - 1) > -1 && a->arr[i + 1][c - 1] == '.')
		a->arr[i + 1][c - 1] = l->counter;
	if ((i + 1) < l->index && (c + 1) < l->content
			&& a->arr[i + 1][c + 1] == '.')
		a->arr[i + 1][c + 1] = l->counter;
}

static int			ft_find_left_dot(t_filler *l, t_map *a)
{
	int				i;
	int				c;

	i = 0;
	c = 0;
	while (a->arr[i])
	{
		c = 0;
		while (a->arr[i][c])
		{
			if (a->arr[i][c] == '.')
			{
				l->counter++;
				if (l->rec_i > 255)
					return (0);
				return (1);
			}
			c++;
		}
		i++;
	}
	return (0);
}

void				ft_finder_player_check(t_filler *l)
{
	if (l->counter == 'X' || l->counter == 'x' || l->counter == 'O'
			|| l->counter == 'o')
		l->counter++;
}

void				ft_find_player_recurs(t_filler *l, t_map *a, char tmp)
{
	int				i;
	int				c;
	int				counter;

	c = 0;
	i = 0;
	counter = -1;
	ft_finder_player_check(l);
	while (a->arr[i])
	{
		c = 0;
		while (a->arr[i][c])
		{
			if (a->arr[i][c] == l->enemy || a->arr[i][c] == tmp)
				ft_find_and_replace(l, a, i, c);
			c++;
		}
		i++;
	}
	l->rec_i++;
	l->enemy = l->counter;
	tmp = l->counter;
	if (ft_find_left_dot(l, a) == 1)
		ft_find_player_recurs(l, a, tmp);
}

void				ft_find_player_location(t_filler *l, t_map *a, t_pie *a_p)
{
	unsigned char	tmp;

	l->rec_i = 1;
	tmp = ft_valid_char(l);
	ft_find_player_recurs(l, a, tmp);
	ft_clip_piece(l, a_p);
}
