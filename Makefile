# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 12:20:53 by ddifalla          #+#    #+#              #
#    Updated: 2024/08/25 12:57:19 by tmazan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Standard
NAME				= push_swap

# Directories
LIBFT				= ./libft/libft.a
HEADER				= header/
SRC_DIR				= sources/
OBJ_DIR				= obj/

# Compiler and CFlags
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -I
RM					= rm -f

# Source Files
MOVES_DIR		=		$(SRC_DIR)moves/push.c \
						$(SRC_DIR)moves/reverse_rotate.c \
						$(SRC_DIR)moves/rotate.c \
						$(SRC_DIR)moves/swap.c \

PUSH_SWAP_DIR		=	$(SRC_DIR)cleaner_postpush.c \
						$(SRC_DIR)helper_init.c \
						$(SRC_DIR)helper_prepush.c \
						$(SRC_DIR)init_a_to_b.c \
						$(SRC_DIR)init_b_to_a.c \
						$(SRC_DIR)init_list_a.c \
						$(SRC_DIR)push_swap.c \
						$(SRC_DIR)sort_list.c \
						$(SRC_DIR)split.c 

# Concatenate all source files
SRCS 				= $(MOVES_DIR) $(PUSH_SWAP_DIR)

# Apply the pattern substitution to each source file in sources and produce a corresponding list of object files in the OBJ_DIR
OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules
start:				
					@make all

$(LIBFT):
					@make -C ./libft

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(HEADER) $(OBJ) $(LIBFT) -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re: 				fclean all

# Phony targets represent actions not files
.PHONY: 			start all clean fclean re