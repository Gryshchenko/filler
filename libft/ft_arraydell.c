/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:16:07 by vgryshch          #+#    #+#             */
/*   Updated: 2018/03/31 13:03:03 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arraydell(char **array)
{
	int	t;

	t = -1;
	while (array[++t])
		free(array[t]);
	free(array);
}
