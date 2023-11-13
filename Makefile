# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omakran <omakran@student.1337.ma >         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 17:13:53 by omakran           #+#    #+#              #
#    Updated: 2023/11/13 17:40:50 by omakran          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

LIBFT       =   libft/libft.a

GET_NEXT_SRC = 	get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c 

GLFW = $(shell brew --prefix glfw)

FRAMEWORKS = /Users/omakran/MLX42/build/libmlx42.a -Iinclude -lglfw -L $(GLFW)/lib/ -framework Cocoa -framework OpenGL -framework IOKit
#MLX         =   -lmlx -framework OpenGL -framework AppKit

HFS			=	parsing/cube.h

SRCS		=	parsing/main.c \
				parsing/validMap.c \
				parsing/validMap_2.c \
				parsing/store_textures.c \
				parsing/tools.c \
				$(GET_NEXT_SRC) \

CC = cc

CFLAGS =  -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all: $(NAME)

%.o: %.c $(HFS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS) $(HFS)
	@make -C libft
	$(CC)  $(CFLAGS) $(OBJS) $(FRAMEWORKS) $(LIBFT) -o $(NAME)

clean:
	@make -C libft/ clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	@make -C libft/ fclean

re: fclean all
	@make -C libft fclean

.PHONY: all clean fclean re