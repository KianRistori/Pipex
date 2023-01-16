# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kristori <kristori@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 10:29:34 by kristori          #+#    #+#              #
#    Updated: 2023/01/16 15:35:05 by kristori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus
SRC = pipex.c parsing.c utils.c check.c get_next_line.c get_next_line_utils.c
SRC_BONUS = pipex_bonus.c utils_bonus.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

LIBFT = @libft/Makefile
FLAGS = -Wall -Werror -Wextra
LIB = libft/libft.a

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(LIBFT) $(NAME) $(NAME_BONUS)

$(NAME): $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(OBJ) $(LIB) $(LINKS) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)
	@rm $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     Deleted object files" $(NONE)

$(NAME_BONUS): $(OBJ_BONUS)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME_BONUS)..." $(NONE)
	@gcc $(FLAGS) $(OBJ_BONUS) $(LIB) $(LINKS) -o $(NAME_BONUS)
	@echo $(GREEN)"- Compiled -"$(NONE)
	@rm $(OBJ_BONUS)
	@echo $(CURSIVE)$(GRAY) "     Deleted object files" $(NONE)

$(LIBFT):
	@echo $(CURSIVE)$(GRAY) "     - Compiling Libft ..."
	@make -s -C libft
	@echo $(GREEN)"- Libft ready -"

$(OBJ): $(SRC)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@gcc $(FLAGS) -c $(SRC)

$(OBJ_BONUS): $(SRC_BONUS)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@gcc $(FLAGS) -c $(SRC_BONUS)

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_BONUS)
	@make -s -C libft clean

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@make -s -C libft fclean

bonus: all $(NAME_BONUS)

re: fclean all
