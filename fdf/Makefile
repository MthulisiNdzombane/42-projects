# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mndzomb <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/30 23:21:13 by mndzomb           #+#    #+#              #
#    Updated: 2018/08/17 08:42:49 by mndzomb          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SOURCES = 	main.c \
			get_next_line.c \
			drawline.c hooks.c \
			plot_lines.c  \

LIBRARY = ./libft/libft.a

OBJECTS = $(SOURCES:.c=.o)
CC = gcc
# FLAGC = -Wall -Werror -Wextra

.SILENT:
all: $(NAME)

$(NAME): $(OBJECTS)
		@make -C ./libft/
		@$(CC) $(FLAGC) -c $(SOURCES)
		@$(CC) $(FLAGC) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJECTS) libft/libft.a

clean:
		make -C libft/ clean
		rm -f $(OBJECTS)
fclean: clean
		make -C libft/ fclean
		rm -f $(NAME)
re: 	fclean all
