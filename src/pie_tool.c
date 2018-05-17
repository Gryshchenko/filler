/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pie_tool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:13:35 by vgryshch          #+#    #+#             */
/*   Updated: 2018/03/29 17:26:07 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			ft_pie_size_i(t_filler *list, char **str, int i)
{
	i++;
	while ((*str)[i] >= '0' && (*str)[i] <= '9')
	{
		list->p_index = (list->p_index * 10) + (*str)[i] - '0';
		i++;
	}
	return (i);
}

int			ft_pie_size_c(t_filler *list, char **str, int i)
{
	i++;
	while ((*str)[i] >= '0' && (*str)[i] <= '9')
	{
		list->p_content = (list->p_content * 10) + (*str)[i] - '0';
		i++;
	}
	return (i);
}

void		ft_array_piece_size(t_filler *list, char *str)
{
	int		i;

	i = 0;
	if (ft_strncmp(str, "Piece", 5) == 0)
	{
		list->p_index = 0;
		list->p_content = 0;
		while (str[i])
		{
			if (str[i] == ' ')
				i = ft_pie_size_i(list, &str, i);
			if (str[i] == ' ')
			{
				i = ft_pie_size_c(list, &str, i);
				break ;
			}
			i++;
		}
	}
}

int			ft_piece_if(char s)
{
	if (s == '.' || s == '*')
		return (1);
	return (0);
}

void		ft_piece_trancate(char **str)
{
	while (ft_piece_if(**str) == 0 && **str)
		*str += 1;
}
