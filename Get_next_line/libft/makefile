
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mndzomb <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/29 13:42:52 by mndzomb           #+#    #+#              #
#    Updated: 2018/05/29 14:11:45 by mndzomb          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc -c
CFLAGS = -Wall -Wextra -Werror

SRCS = *.c
OBJS = *.o
HEADER = libft.h
ARC = ar rc

all: $(NAME)

$(NAME):
	@$(CC) $(SRCS) $(CFLAGS) -I ./
	@$(ARC) $(NAME) $(OBJS)
	@ranlib $(NAME)
	

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
