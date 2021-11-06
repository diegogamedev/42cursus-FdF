CC = clang

NAME = fdf

LIBFT = libft/

MLX = mlx_linux/

FLAGS = -Wall -Wextra -Werror

LIBS = -lm -lbsd -lmlx -lXext -lX11

INCLUDE_PATH = includes

SRCS = srcs/color.c srcs/fdf.c \
	srcs/free.c srcs/ft_atoi_base.c \
	srcs/get_next_line.c srcs/inputs.c \
	srcs/map_aux.c srcs/map.c srcs/math_extensions.c \
	srcs/project.c srcs/render.c srcs/vector_aux.c

OBJ = color.o fdf.o free.o ft_atoi_base.o get_next_line.o inputs.o map_aux.o\
 map.o math_extensions.o project.o render.o vector_aux.o

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIBFT)
		make -C $(MLX)
		$(CC) $(FLAGS) -o $(NAME) $(OBJ) -L $(LIBFT) -L $(MLX) -lft $(LIBS)

$(OBJ): $(SRCS)
		$(CC) $(FLAGS) -c -I $(INCLUDE_PATH) $(SRCS)

clean:
		$(RM) $(OBJ)
		make -C $(LIBFT) clean

fclean: clean
		$(RM) $(NAME)
		make -C $(MLX) clean
		make -C $(LIBFT) fclean

re: fclean all
