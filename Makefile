NAME		=	cub3D

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -fsanitize=address -g
 
GLFW		=	$(shell brew --prefix glfw)

FRAMEWORKS = MLX42/build/libmlx42.a -Iinclude -lglfw -L $(GLFW)/lib/ -framework Cocoa -framework OpenGL -framework IOKit


OBJS		=	$(SRCS:.c=.o)
HFS			=	cube.h
SRCS		=	main.c \
				parsing/validMap.c \
				parsing/validMap_2.c \
				parsing/store_textures.c \
				parsing/tools.c \
				parsing/init.c \
				raycasting/close_game.c\
				raycasting/drawing.c\
				raycasting/create_mlx_window.c\
				raycasting/draw_map.c \
				raycasting/move_the_player.c \
				raycasting/the_moves.c \
				raycasting/player_calculation.c\
				raycasting/can_move_to.c\
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \
				libft/ft_atoi.c \
				libft/ft_bzero.c \
				libft/ft_calloc.c \
				libft/ft_isalnum.c \
				libft/ft_isalpha.c \
				libft/ft_isascii.c \
				libft/ft_isdigit.c \
				libft/ft_isprint.c \
				libft/ft_itoa.c \
				libft/ft_memchr.c \
				libft/ft_memcmp.c \
				libft/ft_memcpy.c \
				libft/ft_memmove.c \
				libft/ft_memset.c \
				libft/ft_putchar_fd.c \
				libft/ft_putendl_fd.c \
				libft/ft_putnbr_fd.c \
				libft/ft_putstr_fd.c \
				libft/ft_split.c \
				libft/ft_strchr.c \
				libft/ft_strdup.c \
				libft/ft_striteri.c \
				libft/ft_strjoin.c \
				libft/ft_strlcat.c \
				libft/ft_strlcpy.c \
				libft/ft_strlen.c \
				libft/ft_strmapi.c \
				libft/ft_strncmp.c \
				libft/ft_strnstr.c \
				libft/ft_strrchr.c \
				libft/ft_strtrim.c \
				libft/ft_substr.c \
				libft/ft_tolower.c \
				libft/ft_toupper.c \


%.o			:	%.c $(HFS)
				$(CC) $(MLX) $(CFLAGS) -c $< -o $@

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HFS)
				$(CC) $(MLX) $(CFLAGS) $(OBJS) $(FRAMEWORKS) -o $(NAME)

clean		:
				rm -f $(OBJS)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean all

.PHONY		:	clean fclean all re