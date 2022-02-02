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

NAME_BONUS		=	checker

SRCS			=   indexing_a.c \
					init.c \
					operations.c \
					operations1.c \
					operations2.c \
					push_swap.c \
					sorting.c \
					sorting1.c \
					sorting2.c \
					utils.c

SRCS_BONUS		=   indexing_a.c \
					init.c \
					operations.c \
					operations1.c \
					operations2.c \
					checker.c \
					sorting.c \
					sorting1.c \
					sorting2.c \
					utils.c
					
LIBFT			=	${LIBFTDIR}libft.a

LIBFTDIR		=	libft/

OBJS			=	${SRCS:.c=.o}

OBJS_BONUS		=	${SRCS_BONUS:.c=.o}

HEADER			=	push_swap.h

CFLAGS			=	-Wall -Wextra -Werror

GCC				=	gcc

CLEAN			=	rm -f

# The flag TEST is taken from the command line, for example:
# make re TEST="-D DEBAG_MODE=TRUE"
# make re TEST="-D SORTING_MODE=DSCNDNG"

%.o:			%.c ${HEADER}
				${GCC} ${CFLAGS} ${TEST} -I${LIBFTDIR} -c $< -o ${<:.c=.o}

all:			${NAME}

bonus:			${NAME_BONUS}

${NAME}:		${LIBFT} ${OBJS}
				${GCC} ${CFLAGS} $(TEST) ${OBJS} -L${LIBFTDIR} -lft -o ${NAME}
				@echo "\033[2mMake done\033[0m"

${NAME_BONUS}:	${LIBFT} ${OBJS_BONUS}
				${GCC} ${CFLAGS} $(TEST) ${OBJS_BONUS} -L${LIBFTDIR} -lft -o ${NAME_BONUS}
				@echo "\033[2mMake bonus done\033[0m"

${LIBFT}:
				@make -C ${LIBFTDIR}

clean:
				@${CLEAN} ${OBJS} ${OBJS_BONUS}
				@make -C ${LIBFTDIR} clean
				@echo "\033[2mMake clean done\033[0m"

fclean:			clean
				@${CLEAN} ${NAME} ${NAME_BONUS} ${LIBFT}
				@echo "\033[2mMake fclean done\033[0m"

re:				fclean all

norm:
				norminette
				
help:
				@echo "\033[2;1mThe flag TEST is taken from the command line, for example:\033[0m"
				@echo "\033[2;1mmake re TEST=\"-D DEBAG_MODE=TRUE\"\033[0m"
				@echo "\033[2;1mmake re TEST=\"-D SORTING_MODE=DSCNDNG\"\033[0m"

.PHONY:			all clean fclean re libft bonus
