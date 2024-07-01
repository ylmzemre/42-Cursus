# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emreyilm <emreyilm@student.42kocaeli.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/06 14:29:31 by emreyilm          #+#    #+#              #
#    Updated: 2024/01/06 14:29:32 by emreyilm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc 

CFLAGS = -Wall -Werror -Wextra

CFILES	 = 	push_swap.c \
			function.c \
			function2.c \
			function3.c \
			rules_a.c \
			rules_b.c \
			utils.c \
			utils2.c

$(NAME):
	@$(CC) $(CFLAGS) $(CFILES) -o $(NAME)
	@echo "\n\033[33mPush_swap is ready ✅\033[0m\n"


all: $(NAME)
	@echo "\n\033[33mAll files compiled successfully ✅\033[0m\n"

clean:
		@echo "\n\033[33mObjects files deleted ✅\033[0m\n"

fclean: clean
		@rm -rf $(NAME)
		@echo "\n\033[33mArchive file deleted ✅\033[0m\n"

re: fclean all

.phony: re fclean clean all
