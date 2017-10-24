# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proso <proso@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/27 13:41:20 by proso             #+#    #+#              #
#    Updated: 2017/10/25 00:21:36 by caroleroso       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = naval_battle

SRC = Sources/add_ia_cross.c\
			Sources/add_player_cross.c\
			Sources/check_boats.c\
			Sources/checker.c\
			Sources/game.c\
 			Sources/ia_checker.c\
			Sources/ia_shoot.c\
			Sources/is_victory.c\
			Sources/main.c\
			Sources/placement_ia_boats.c\
			Sources/placement_player_boats.c\
			Sources/player_shoot.c\
			Sources/print_map.c\
			Sources/put_boats.c

CC = gcc

FLAGS = -Wall -Werror -Wextra

INCLUDE = Includes/battle.h

LIB = Libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o:%.c $(INCLUDE)
	@$(CC) $(FLAGS) -I./$(INCLUDE) -o $@ -c $<
	@Progress_bar/p_bar_21sh $<
	@sleep 0.05

clr:
	@clear

make_lib:
	@make -C Libft/
	@clear
	@echo "\x1b[33m\x1b[1mMaking executable... ⏳\x1b[0m"
	@sleep 1

$(NAME): clr make_lib $(OBJ) $(INCLUDE)
	@$(CC) $(FLAGS) -o $(NAME) $(LIB) $(OBJ) -ltermcap
	@sleep 1
	@clear
	@echo "\x1b[32m\x1b[1mExecutable sucessfully created ✓\x1b[0m"

clean:
	@make clean -C Libft/
	@rm -f $(OBJ)
	@echo "\x1b[31m\x1b[1mAll objects deleted ✖\x1b[0m"

fclean: clean
	@make fclean -C Libft/
	@rm -f $(NAME)
	@echo "\x1b[31m\x1b[1mExecutable deleted ✖\x1b[0m"

re: fclean all
