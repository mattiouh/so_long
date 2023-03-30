# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpalombi <mpalombi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 11:44:42 by mpalombi          #+#    #+#              #
#    Updated: 2023/03/28 18:54:29 by mpalombi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
MINILIBX_PATH = ./mlx
MINILIBX = $(MINILIBX_PATH)/libmlx.a

HEADER = ${NAME:.a=.h}

SOURCES = main.c	\
		start.c \
		start2.c \
		control_map.c \
		checks.c \
		draw_map.c \
		sprite.c \
		movement.c \
		death.c \
		collectables.c \
		trw_master.c \
		rand_n.c \
		animation.c \
		side_anim.c \
		idle_anim.c \


OBJECTS = ${SOURCES:.c=.o}

MLX = ./libmlx.dylib
CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra -g

.o:.c
		${CC} ${CFLAGS} -Imlx -c $< -o $@

all: 	${NAME}

${NAME}: ${OBJECTS} $(LIBFT)
		${CC} ${OBJECTS} $(LIBFT) -Lmlx -lmlx -framework OpenGl -framework AppKit -o ${NAME}

$(MINILIBX):
			make -C $(MINILIBX_PATH)

$(LIBFT) :
			make -C $(LIBFT_PATH)

clean:
		${RM} ${OBJECTS}
		make clean -C $(LIBFT_PATH)
		make clean -C $(MINILIBX_PATH)

fclean: clean
		${RM} $(LIBFT)
		${RM} ${NAME}
		${RM} $(MINILIBX)

re: fclean all
