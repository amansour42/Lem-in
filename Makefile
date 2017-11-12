# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amansour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 10:28:05 by amansour          #+#    #+#              #
#    Updated: 2017/11/10 12:27:58 by amansour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

LDFLAGS_LIB = -L libft
LDLIBS = -lft
FLAGS = -Werror -Wall -Wextra

SRC_PATH = ./src
OBJ_PATH = ./obj
INCLUD  = ./include
LIB = libft/libft.a

SRC = main.c checking.c map.c error.c delete_room.c add_room.c\
	  add_tube.c print_ants.c\

OBJ = $(addprefix $(OBJ_PATH)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	gcc $(OBJ) $(LDFLAGS_LIB) $(LDLIBS)  -o $(NAME)
	@echo "\033[1;34mLEM_IN\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

$(LIB):
	@make -C libft

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	gcc $(FLAGS) -I $(INCLUD) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_PATH)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME) $(LIB)

re: fclean all
