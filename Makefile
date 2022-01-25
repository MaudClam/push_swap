#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2022/01/25 16:09:09 by mclam             #+#    #+#             *#
#*   Updated: 2022/01/25 16:09:09 by mclam            ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME			=	push_swap

SRCS			=   indexing_a.c \
					operations.c \
					operations1.c \
					operations2.c \
					push_swap.c \
					sorting.c \
					sorting1.c \
					utils.c \

LIBFT			=	${LIBFTDIR}libft.a
LIBFTDIR		=	libft/

OBJS			=	${SRCS:.c=.o}

INCLUDE			=	push_swap.h

CFLAGS			=	-Wall -Wextra -Werror

GCC				=	gcc

CLEAN			=	rm -f

.c.o:
				${GCC} ${CFLAGS} -I${LIBFTDIR} -c $< -o ${<:.c=.o}

${NAME}:		${LIBFT} ${OBJS} ${INCLUDE}
				${GCC} ${OBJS} \
				-L${LIBFTDIR} -lft \
				-I${LIBFTDIR} -Iinclude \
				-o ${NAME}

${LIBFT}:
				make -C ${LIBFTDIR} libft.a

all:			${NAME}

clean:
				${CLEAN} ${OBJS}
				make -C ${LIBFTDIR} clean

fclean:			clean
				${CLEAN} ${NAME}
				make -C ${LIBFTDIR} fclean

re:				fclean all

.PHONY:			all clean fclean re libft
