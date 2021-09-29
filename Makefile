# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 10:31:30 by mmondell          #+#    #+#              #
#    Updated: 2021/09/29 08:57:47 by mmondell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program
NAME = fractol

# Flags used during compilation
FLAGS = -Wall -Wextra -Werror -O2

# Color
GREEN = \033[32m

# Folders
SRCS_DIR = ./srcs/
OBJ_DIR = ./obj/
INC_DIR = ./includes/
LIBFT_DIR = ./libft/

# Source files to compile
SRCS_FILES = 	main.c init_fractals.c error.c draw_fractals.c mandelbrot.c \
				julia.c mouse_hooks.c show_menu.c keyboard_hooks.c burning_ship.c

# .c files becomes .o object files
OBJ_FILES = $(SRCS_FILES:.c=.o)

# Folder Paths
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

LNK = -L $(LIBFT_DIR) -lft -Ofast -lmlx -framework OpenGL -framework AppKit

all: obj $(LIBFT) $(NAME)
	@echo "$(GREEN)Compilation Complete"

obj:
	@-mkdir -p $(OBJ_DIR) $(LIBFT_OBJ)
$(OBJ_DIR)%.o:$(SRCS_DIR)%.c
	@-gcc $(FLAGS) -I $(LIBFT_DIR) -I $(INC_DIR) -o $@ -c $< 
$(LIBFT):
	@-make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	@-gcc $(OBJ) $(LNK) -lm -lpthread -o $(NAME)

clean:
	@-rm -Rf $(OBJ_DIR)
	@-make -C $(LIBFT_DIR) clean

fclean: clean
	@-rm -f $(NAME)
	@-make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
