# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 15:52:48 by vgryshch          #+#    #+#              #
#    Updated: 2018/03/30 12:11:08 by vgryshch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = vgryshch.filler

OBJECTS_FILLER_PATH = ./src/

SRC_FILLER = filler.c \
			find_path_to_enemy.c \
			place_piece.c \
			map_tool.c \
			pie_tool.c \
			pie_clip.c \
			tools.c \

LIBFT = -L ./libft -lft

INCLUDE = -I ./includes

OBJECTS_FILLER = $(addprefix $(OBJECTS_FILLER_PATH), $(SRC_FILLER:.c=.o))

CFLAGS = -Wall -Wextra -Werror -g

.PHONY: all
all: $(NAME)

$(NAME): $(OBJECTS_FILLER)
	@make -C ./libft all
	@echo libft made
	@gcc $(CFLAGS) $(OBJECTS_FILLER) $(INCLUDE) $(LIBFT) -o $(NAME)
	@echo filler made

.c.o:
	@gcc $(CFLAGS) -c $< -o $@ $(INCLUDE)

.PHONY: clean
clean:
	@echo cleaned
	@make -C ./libft clean
	@/bin/rm -f $(OBJECTS_FILLER)

.PHONY: fclean
fclean: clean
	@echo fcleaned
	@make -C ./libft fclean
	@/bin/rm -f $(NAME)

.PHONY: re
re: fclean all
