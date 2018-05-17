/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:15:51 by vgryshch          #+#    #+#             */
/*   Updated: 2018/03/21 13:19:49 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cord	*ft_lstnew_fill(int y, int x)
{
	t_cord *newlist;

	if (!(newlist = (t_cord *)malloc(sizeof(t_cord))))
		return (NULL);
	newlist->x = x;
	newlist->y = y;
	newlist->next = NULL;
	return (newlist);
}
