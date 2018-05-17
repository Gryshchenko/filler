/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 13:11:21 by vgryshch          #+#    #+#             */
/*   Updated: 2018/03/31 13:40:15 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

int				ft_printf(const char *format, ...);

typedef struct	s_iter
{
	int			i;
	int			j;
	int			pid;
	int			res;
}				t_iter;
#endif
