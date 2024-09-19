# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 16:23:21 by ducnguye          #+#    #+#              #
#    Updated: 2024/09/16 15:02:29 by ducnguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = srcs
INCLUDE_DIR = includes
SRC = $(SRC_DIR)/ft_putchar.c $(SRC_DIR)/ft_swap.c $(SRC_DIR)/ft_putstr.c $(SRC_DIR)/ft_strlen.c $(SRC_DIR)/ft_strcmp.c
OBJ = $(SRC:.c=.o)
NAME = libft.a
MAKEFLAGS = --no-print-directory
# Default target
all: $(NAME)

# Compile object files
# %.o will be created in the same dir as the corresponding %.c
# -I tells where to find the header files
# $< is the source file (%.c)
# $@ is the target file (%.o)
%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Create the library
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Clean object files
clean:
	rm -f $(OBJ)

# Clean object files and the library
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
