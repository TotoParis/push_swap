# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 16:40:58 by tbarret           #+#    #+#              #
#    Updated: 2024/03/03 10:55:48 by tbarret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/function/args/check.c \
 	  src/function/args/create.c \
	  src/function/push_swap.c \
	  src/function/stack/stuct.c \
	  src/function/stack/rotate.c \
	  src/function/stack/swap.c \
	  src/function/stack/push.c \
	  src/function/stack/reverse.c \
	  src/function/calcul/max.c \
	  src/function/calcul/min.c \
	  src/function/calcul/median.c \
	  src/function/calcul/sort.c \
	  src/function/calcul/sort_three.c \
	  src/function/calcul/sort_five.c \
	  src/function/calcul/push_swap.c \
	  src/function/calcul/id.c \
	  src/function/calcul/cost.c \
	  src/function/calcul/mouvement.c 
	  
OBJ = ${SRC:.c=.o}
NAME = push_swap
HEADER  = src/header
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
FT_PRINTF = src/header/ft_printf/
LIBFT = src/header/libft/

all: ${NAME}

%.o: %.c
	$(CC) ${CFLAGS} -c $< -o $@

${NAME}: ${OBJ}
	@make -C ${FT_PRINTF}
	@make -C ${LIBFT}
	${CC} ${CFLAGS} ${OBJ} -I ${HEADER} ${LIBFT}libft.a ${FT_PRINTF}libftprintf.a -o ${NAME}

clean:
	@make clean -C ${FT_PRINTF}
	@make clean -C ${LIBFT}
	${RM} ${OBJ}

fclean: clean
	@make fclean -C ${FT_PRINTF}
	@make fclean -C ${LIBFT}
	${RM} ${NAME}

bonus: all

re: fclean all

.PHONY : all clean fclean re
