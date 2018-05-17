/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 11:18:58 by vgryshch          #+#    #+#             */
/*   Updated: 2018/03/31 12:52:22 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void		ft_piece_save(t_filler *list, t_map *a, t_pie *a_p, char *str)
{
	if (ft_strncmp(str, "Piece", 4))
	{
		if (a_p->i == 0 && list->pie_found == 1)
			if (!(a_p->arr_p = (char **)malloc(sizeof(char*)
							* (list->p_index + 1))))
				return ;
		if (*str && list->p_index > a_p->i)
		{
			a_p->l = 0;
			ft_piece_trancate(&str);
			if (!(a_p->arr_p[a_p->i] = (char *)malloc(sizeof(char)
							* list->p_content + 1)))
				return ;
			while (ft_piece_if(*str) == 1 && a_p->l < list->p_content)
				a_p->arr_p[a_p->i][a_p->l++] = *str++;
			a_p->arr_p[a_p->i][a_p->l] = '\0';
			a_p->i++;
		}
		if (a_p->i > 0 && a_p->i == list->p_index)
		{
			a_p->arr_p[a_p->i] = (void*)0;
			ft_find_player_location(list, a, a_p);
			ft_piece_place(list, a_p, a);
		}
	}
}

void		ft_array_creat(t_filler *list, t_map *a, t_pie *a_p, char *str)
{
	if (a->i == 0)
	{
		if (!(a->arr = (unsigned char **)malloc(sizeof(unsigned char*) *
						(list->index + 1))))
			return ;
		list->pie_found = 0;
	}
	if (*str && list->index > a->i)
	{
		a->l = 0;
		ft_str_trancate(&str);
		if (!(a->arr[a->i] = (unsigned char *)malloc(sizeof(unsigned char) *
						list->content + 1)))
			return ;
		while (ft_str_if(*str) == 1)
			a->arr[a->i][a->l++] = *str++;
		a->arr[a->i][a->l] = '\0';
		a->i++;
	}
	if (a->i == list->index)
	{
		a->arr[a->i] = (void*)0;
		ft_piece_save(list, a, a_p, str);
	}
}

void		ft_read_from_terminal(t_filler *list, t_map *a, t_pie *a_p)
{
	char	*s;

	s = (void*)0;
	a->i = 0;
	a_p->i = 0;
	list->pie_found = 0;
	get_next_line(0, &s);
	if (!ft_strncmp(s, "$$$ exec p", 9) && (s[10] == '1' || s[10] == '2'))
		ft_players_detection(list, s);
	ft_strdel(&s);
	while (get_next_line(0, &s) == 1)
	{
		if (!ft_strncmp(s, "Piece", 5))
		{
			ft_array_piece_size(list, s);
			list->pie_found = 1;
		}
		else if (!ft_strncmp(s, "Plateau", 7))
			ft_array_size(list, s);
		else if (ft_strncmp(s, "Piece", 5) && ft_strncmp(s, "Plateau", 7)
				&& ft_strncmp(s, "    01", 6))
			ft_array_creat(list, a, a_p, s);
		free(s);
	}
}

int			main(void)
{
	t_filler	list;
	t_map		a;
	t_pie		a_p;

	list.counter = '1';
	ft_read_from_terminal(&list, &a, &a_p);
	return (0);
}
