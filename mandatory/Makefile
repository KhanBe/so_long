# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaewoo <jaewoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 01:17:20 by jaewoo            #+#    #+#              #
#    Updated: 2022/07/12 01:33:26 by jaewoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f

LIB = ../libft/libft.a

SRCS = so_long.c parser.c tools.c tools2.c
OBJS = ${SRCS:.c=.o}

MLX_API = -lmlx -framework OpenGl -framework AppKit

all : ${NAME}

clean :
	${RM} ${OBJS}
fclean : clean
	${RM} ${NAME}

re : fclean all

${NAME} : ${OBJS}
	@cc ${CFLAGS} ${MLX_API} ${OBJS} ${LIB} -o ${NAME}

%.o : %.c
	${CC} ${CFLAGS} -Imlx -c $< -o $@

.PHONY : all clean fclean re
