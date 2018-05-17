/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:47:58 by vgryshch          #+#    #+#             */
/*   Updated: 2018/03/31 13:01:43 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../pflib/libftprintf.h"

void	ft_putarray(char **array)
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
			ft_printf("%c", array[t][z]);
			z++;
		}
		ft_printf("\n");
		t++;
	}
}
