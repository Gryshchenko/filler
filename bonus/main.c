/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:58:17 by vgryshch          #+#    #+#             */
/*   Updated: 2018/06/22 11:54:31 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "header.h"
#include <sys/wait.h>
#include <fcntl.h>

/*
** gcc main.c ../libft/libft.a libftprintf.a
*/

void	ft_read_from_gnl(int fd, char *line, t_iter *i)
{
	if (get_next_line(fd, &line) != -1)
	{
		if (!ft_strcmp(line, "../vgryshch.filler won"))
			i->res++;
		free(line);
	}
}

char	**ft_argv_init(void)
{
	char	**new;

	new = (char**)malloc(sizeof(char*) * 12);
	new[0] = ft_strdup("../resources/filler_vm");
	new[1] = ft_strdup("-f");
	new[2] = ft_strdup("../resources/maps/map02");
	new[3] = ft_strdup("-p1");
	new[4] = ft_strdup("../vgryshch.filler");
	new[5] = ft_strdup("-p2");
	new[6] = ft_strdup("../resources/players/carli.filler");
	new[7] = ft_strdup("| visualization.c");
	new[8] = NULL;
	return (new);
}

int		main(void)
{
	t_iter	iter;
	int		fd;
	char	*line;
	int		pid;
	char	**argv;

	iter.i = 0;
	iter.j = -1;
	iter.res = 0;
	iter.pid = 0;
	argv = ft_argv_init();
	while (++(iter.i) < 2)
	{
		iter.j = -1;
		if ((iter.pid = fork()) == 0)
			execv("../resources/filler_vm", argv);
		wait(NULL);
		fd = open("filler.trace", O_RDONLY);
		while (++(iter.j) < 3)
			ft_read_from_gnl(fd, line, &iter);
		close(fd);
		ft_printf("step: %d | won: %d\n", iter.i, iter.res);
	}
	ft_printf("vgrysh won: %d times\n", iter.res);
	return (0);
}
