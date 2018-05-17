/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:28:47 by vgryshch          #+#    #+#             */
/*   Updated: 2018/03/30 12:08:22 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

char	ft_valid_char(t_filler *list)
{
	if (list->enemy_copy == 'X')
		return ('x');
	else if (list->enemy_copy == 'O')
		return ('o');
	return (0);
}

char	ft_valid_player(t_filler *list)
{
	if (list->player == 'X')
		return ('x');
	else if (list->player == 'O')
		return ('o');
	return (0);
}

void	ft_players_detection(t_filler *list, char *line)
{
	list->player = (line[10] == '1' ? 'O' : 'X');
	if (list->player == 'X')
	{
		list->enemy = 'O';
		list->enemy_copy = 'O';
	}
	else if (list->player == 'O')
	{
		list->enemy = 'X';
		list->enemy_copy = 'X';
	}
}

void	ft_clip_piece(t_filler *list, t_pie *a_p)
{
	ft_piece_clip_x(list, a_p);
	ft_piece_clip_y(list, a_p);
}

void	ft_all_to_zero(t_filler *list, t_pie *a_p, t_map *a)
{
	a_p->i = 0;
	a->i = 0;
	a_p->l = 0;
	a->l = 0;
	a_p->min_x = 0;
	a_p->max_x = 0;
	a_p->min_y = 0;
	a_p->max_y = 0;
	list->index = 0;
	list->p_index = 0;
	list->content = 0;
	list->p_content = 0;
	list->arr_width = 0;
	list->arr_hight = 0;
	list->counter = '1';
	list->enemy = (list->player == 'X' ? 'O' : 'X');
}
