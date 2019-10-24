# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/19 21:34:35 by elhampto          #+#    #+#              #
#    Updated: 2019/10/24 11:44:44 by elhampto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

SRC = flags \
		hash \
		main \
		ft_md5 \
		sha256 \
		helper

INC = -I includes -I libft/includes

VPATH = code:

OBJ_DIR = obj

OBJ = $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(SRC)))

CC = gcc

CFLAGS = -Wall -Werror -Wextra $(INC) -g

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@echo "\033[31mCreating objects && folder...\033[0m"
	@make -C libft
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "\033[33mMaking libft...\033[0m"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L libft/ -lft

clean:
	@echo "\033[36mCleaning objects...\033[0m"
	@make clean -C libft
	@/bin/rm -rf $(OBJ)

fclean: clean
	@echo "\033[32mCleaning objects and library...\033[0m"
	@make fclean -C libft
	@/bin/rm -rf $(OBJ_DIR)
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
