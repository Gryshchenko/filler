/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 17:09:23 by vgryshch          #+#    #+#             */
/*   Updated: 2018/03/31 12:36:35 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

flag1=$(printf "\x1B[31m☭\x1B[0m")
flag2=$(printf "\x1B[33m⚘\x1B[0m")
light_flag1=$(printf "\x1B[31m☭\x1B[0m")
light_flag2=$(printf "\x1B[33m⚘\x1B[0m")
yellow=$(printf "\e[33mplayer\e[0m")

sed "s|O|$flag1|g" |
sed "s|X|$flag2|g" |
sed "s|x|$light_flag2|g" |
sed "s|o|$light_flag1|g" |
sed "s|fin|$yellow|g"
