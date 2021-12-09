# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 04:11:39 by rcorenti          #+#    #+#              #
#    Updated: 2021/12/09 05:19:15 by rcorenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = clang

FLAGS = -Wall -Wextra -Werror

HEADER = -I includes

srcs =	main.c\
	big.c\
	operations.c\
	parser.c\
	put_hold_top.c\
	put_in_stacks.c\
	scan_index.c\
	small.c\
	utils.c\
	utils_chunks.c

OBJS = ${addprefix srcs/,${srcs:.c=.o}}

.c.o :
	${CC} ${FLAGS} ${HEADER} -c $< -o ${<:.c=.o}

all: $(NAME)

${NAME}: $(OBJS)
	${CC} ${FLAGS} ${OBJS} -o ${NAME}

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
