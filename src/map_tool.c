/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:11:30 by vgryshch          #+#    #+#             */
/*   Updated: 2018/03/30 12:08:05 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int			ft_array_size_i(t_filler *list, char **str, int i)
{
	i++;
	while ((*str)[i] >= '0' && (*str)[i] <= '9')
	{
		list->index = (list->index * 10) + (*str)[i] - '0';
		i++;
	}
	return (i);
}

int			ft_array_size_c(t_filler *list, char **str, int i)
{
	i++;
	while ((*str)[i] >= '0' && (*str)[i] <= '9')
	{
		list->content = (list->content * 10) + (*str)[i] - '0';
		i++;
	}
	return (i);
}

void		ft_array_size(t_filler *list, char *str)
{
	int		i;

	i = 0;
	if (ft_strncmp(str, "Plateau", 6) == 0)
	{
		list->index = 0;
		list->content = 0;
		while (str[i])
		{
			if (str[i] == ' ')
				i = ft_array_size_i(list, &str, i);
			if (str[i] == ' ')
			{
				i = ft_array_size_c(list, &str, i);
				break ;
			}
			i++;
		}
	}
}

int			ft_str_if(char s)
{
	if (s == '.' || s == 'x' || s == 'X' || s == 'o' || s == 'O')
		return (1);
	return (0);
}

void		ft_str_trancate(char **str)
{
	while (ft_str_if(**str) == 0 && **str)
		*str += 1;
}
