/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarray_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:00:22 by vgryshch          #+#    #+#             */
/*   Updated: 2018/03/31 13:02:38 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putarray_u(unsigned char **array)
{
	int	t;
	int	z;

	t = 0;
	z = 0;
	while (array[t])
	{
		z = 0;
		while (array[t][z])
		{
			ft_putchar_u(array[t][z]);
			z++;
		}
		ft_putchar_u('\n');
		t++;
	}
}
