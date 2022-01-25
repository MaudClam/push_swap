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

HEADER			=	push_swap.h

CFLAGS			=	-Wall -Wextra -Werror

GCC				=	gcc

CLEAN			=	rm -f

# The test TEST is taken from the command line, for example:
# make re TEST="-D DEBAG_MODE=TRUE"
# make re TEST="-D SORTING_MODE=DSCNDNG"

%.o:			%.c ${HEADER}
				${GCC} ${CFLAGS} -I${LIBFTDIR} -c $< -o ${<:.c=.o}

all:			${NAME}

${NAME}:		${LIBFT} ${OBJS}
				${GCC} ${CFLAGS} $(TEST) ${OBJS} -L${LIBFTDIR} -lft -o ${NAME}
				@echo "Make done"

${LIBFT}:
				@make -C ${LIBFTDIR} libft.a

clean:
				@${CLEAN} ${OBJS}
				@make -C ${LIBFTDIR} clean
				@echo "Make clean done"

fclean:			clean
				@${CLEAN} ${NAME}
				@make -C ${LIBFTDIR} fclean
				@echo "Make fclean done"

re:				fclean all

norm:
				norminette

.PHONY:			all clean fclean re libft
