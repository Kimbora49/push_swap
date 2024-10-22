# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmazan <tmazan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 23:37:35 by ayman_marzo       #+#    #+#              #
#    Updated: 2024/10/22 23:06:52 by tmazan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= push_swap
BONUS_NAME			= checker

LIBFT				= ./my_library/libft.a
INC					= inc/
SRC_DIR				= srcs/
OBJ_DIR				= obj/

CC					= cc
CFLAGS				= -Wall -Werror -Wextra -I
RM					= rm -f

COMMANDS_DIR		=	$(SRC_DIR)commands/push.c \
						$(SRC_DIR)commands/rev_rotate.c \
						$(SRC_DIR)commands/rotate.c \
						$(SRC_DIR)commands/sort_list.c \
						$(SRC_DIR)commands/sort_three.c \
						$(SRC_DIR)commands/swap.c

PUSH_SWAP_DIR		=	$(SRC_DIR)push_swap/handle_errors.c \
						$(SRC_DIR)push_swap/init_a_to_b.c \
						$(SRC_DIR)push_swap/init_b_to_a.c \
						$(SRC_DIR)push_swap/split.c \
						$(SRC_DIR)push_swap/list_init.c \
						$(SRC_DIR)push_swap/list_utils.c \
						$(SRC_DIR)push_swap/strjoin_swap.c

PUSH_SWAP_SRCS		= $(COMMANDS_DIR) $(PUSH_SWAP_DIR) $(SRC_DIR)push_swap/push_swap.c
BONUS_SRCS			= $(COMMANDS_DIR) $(PUSH_SWAP_DIR) $(SRC_DIR)checker.c

PUSH_SWAP_OBJS		= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(PUSH_SWAP_SRCS))
BONUS_OBJS			= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(BONUS_SRCS))

# Colors
GREEN				= \033[0;32m
YELLOW				= \033[1;33m
BLUE				= \033[0;34m
RED					= \033[0;31m
NC					= \033[0m # No Color

start:				
					@echo "${BLUE}🔨 Starting build...${NC}"
					@make all

$(LIBFT):
					@echo "${YELLOW}📦 Building libft...${NC}"
					@make -C ./my_library

all: 				$(NAME)

$(NAME): 			$(PUSH_SWAP_OBJS) $(LIBFT)
					@echo "${GREEN}🚀 Compiling and linking $(NAME)...${NC}"
					@$(CC) $(CFLAGS) $(INC) $(PUSH_SWAP_OBJS) $(LIBFT) -o $(NAME)

$(BONUS_NAME): 		$(BONUS_OBJS) $(LIBFT)
					@echo "${GREEN}🚀 Compiling and linking $(BONUS_NAME)...${NC}"
					@$(CC) $(CFLAGS) $(INC) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@echo "${BLUE}🛠️  Compiling $<...${NC}"
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@echo "${RED}🧹 Cleaning object files...${NC}"
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./my_library

fclean: 			clean
					@echo "${RED}🔥 Removing binaries...${NC}"
					@$(RM) $(NAME) $(BONUS_NAME)
					@$(RM) $(LIBFT)

re: 				fclean all

bonus: 				$(BONUS_NAME)

.PHONY: 			start all clean fclean re bonus
