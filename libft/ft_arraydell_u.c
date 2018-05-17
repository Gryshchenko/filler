/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydell_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:02:14 by vgryshch          #+#    #+#             */
/*   Updated: 2018/03/22 15:02:32 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arraydell_u(unsigned char **array)
{
	int	t;

	t = -1;
	while (array[++t])
		free(array[t]);
	free(array);
}
