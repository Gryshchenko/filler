/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:26:35 by vgryshch          #+#    #+#             */
/*   Updated: 2018/03/31 13:01:53 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct		s_filler
{
	int				rec_i;
	int				exit;
	int				size;
	int				index;
	int				content;
	int				p_index;
	int				p_content;
	int				player_c;
	int				enemy_c;
	int				arr_width;
	int				arr_hight;
	char			player_x;
	char			enemy_x;
	char			player;
	unsigned char	enemy;
	int				pie_found;
	char			enemy_copy;
	unsigned char	counter;
}					t_filler;

typedef struct		s_tmp
{
	int				s;
	int				b;
	int				i;
	int				c;
	int				return_y;
	int				return_x;
	int				start_from;
}					t_tmp;

typedef struct		s_map
{
	int				i;
	int				l;
	unsigned char	**arr;
}					t_map;

typedef struct		s_pie
{
	int				i;
	int				l;
	char			**arr_p;
	int				min_x;
	int				min_y;
	int				max_x;
	int				max_y;
	int				r_x;
	int				r_y;
	int				min_temp;
	int				min_step;
}					t_pie;

void				ft_piece_trancate(char **str);
void				ft_players_detection(t_filler *list, char *line);
void				ft_players_detection(t_filler *list, char *line);
int					ft_piece_if(char s);
void				ft_str_trancate(char **str);
int					ft_str_if(char s);
void				ft_piece_save(t_filler *list, t_map *a,
					t_pie *a_p, char *str);
void				ft_piece_place(t_filler *list, t_pie *a_p, t_map *a);
void				ft_array_creat(t_filler *list, t_map *a,
					t_pie *a_p, char *str);
void				ft_read_from_terminal(t_filler *list, t_map *arr,
					t_pie *arr_p);
void				ft_find_player_location(t_filler *list, t_map *a,
					t_pie *a_p);
char				ft_valid_char(t_filler *list);
char				ft_valid_player(t_filler *list);
void				ft_clip_piece(t_filler *list, t_pie *a_p);
void				ft_piece_clip_x(t_filler *list, t_pie *a_p);
void				ft_piece_clip_y(t_filler *list, t_pie *a_p);
void				ft_array_piece_size(t_filler *list, char *str);
void				ft_array_size(t_filler *list, char *str);
void				ft_all_to_zero(t_filler *list, t_pie *a_p, t_map *a);
#endif
