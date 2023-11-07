CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
MLX         =   -lmlx -framework OpenGL -framework AppKit
NAME		=	cub3D
SRCS		=	main.c cube.c
OBJS		=	$(SRCS:.c=.o)
HFS			=	cube.h

%.o			:	%.c $(HFS)
				$(CC) $(MLX) $(CFLAGS) -c $< -o $@

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HFS)
				$(CC) $(MLX) $(CFLAGS) $(OBJS) -o $(NAME)

clean		:
				rm -f $(OBJS)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean all

.PHONY		:	clean fclean all re