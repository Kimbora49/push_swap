# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddifalla <ddifalla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/08 17:43:29 by ddifalla          #+#    #+#              #
#    Updated: 2024/06/18 15:07:39 by ddifalla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_helpers.c ft_printf.c
					

HEADER=ft_printf.h

OBJS			= $(SRCS:.c=.o)

%.c%.o:
	${CC} ${CFLAGS} -c ${HEADER} $< -o ${<:.c=.o}

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS) ${HEADER}
				ar rc $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:         all clean fclean re bonus