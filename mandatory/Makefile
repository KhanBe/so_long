# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaewoo <jaewoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 01:17:20 by jaewoo            #+#    #+#              #
#    Updated: 2022/07/12 04:01:35 by jaewoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT = ../libft
LIBFT_LIB = libft.a

CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f

SRCS = so_long.c
OBJS = ${SRCS:.c=.o}

MLX_API = -L../minilibx -lmlx -framework OpenGl -framework AppKit

${NAME} : ${OBJS}
	make all -C ${LIBFT}/
	${CC} -o ${NAME} ${OBJS} -L../libft -lft ${MLX_API}

%.o : %.c
	${CC} ${FLAGS} -c $^ -I./ -o $@

all : ${NAME}

clean :
	${RM} ${OBJS}
	make clean -C ${LIBFT}
fclean : clean
	${RM} ${NAME}
	${RM} ${LIBFT_LIB}
	make fclean -C ${LIBFT}

re : fclean all

.PHONY : all clean fclean re
