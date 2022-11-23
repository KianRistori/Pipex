# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kristori <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 10:29:34 by kristori          #+#    #+#              #
#    Updated: 2022/11/23 11:54:51 by kristori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SRC = main.c pipex.c parsing.c
OBJ = $(SRC:.c=.o)

LIBFT = @libft/Makefile
FLAGS =
LIB = libft/libft.a

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(OBJ) $(LIB) $(LINKS) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)
	@rm $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     Deleted object files" $(NONE)

$(LIBFT):
	@echo $(CURSIVE)$(GRAY) "     - Compiling Libft ..."
	@make -s -C libft
	@echo $(GREEN)"- Libft ready -"


$(OBJ): $(SRC)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@gcc $(FLAGS) -c $(SRC)

exe: all
	@echo "     - Executing $(NAME)... \n"
	@./$(NAME)
	@echo "\n     - Done -"

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJ)
	@make -s -C libft clean

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)
	@make -s -C libft fclean

re: fclean all
