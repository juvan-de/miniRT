# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: juvan-de <juvan-de@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/27 11:29:28 by juvan-de      #+#    #+#                  #
#    Updated: 2020/07/30 23:38:58 by julesvander   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

OBJ_DIR = ./obj/
OBJ_FILES =	maths.o \
			pars.o \
			pars_cam.o \
			pars_amb.o \
			pars_light.o \
			pars_sphere.o \
			pars_triangle.o \
			pars_plane.o \
			pars_square.o \
			pars_cylinder.o \
			get_next_line.o \
			get_next_line_utils.o \
			utils.o \
			more_utils.o \
			free.o \
			main.o \
			projecting.o \
			pixel.o \
			sphere_collision.o \
			plane_collision.o \
			square_collision.o \
			triangle_collision.o \
			cylinder_collision.o \
			light.o \
			mlx.o \
			keys.o \
			vector.o \
			vector_two.o \
			matrix.o \
			make_bmp.o

OBJECTS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

SRC_DIR = ./src/


LIBFT = -L./libft -lft
MLX = -Lmlx/ -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C libft
	@cp libft/libft.a .
	make -C mlx
	@cp mlx/libmlx.dylib .
	$(CC) $(MLX) -o $(NAME) $(OBJECTS) $(LIBFT) $(CFLAGS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p obj
	@gcc -Imlx -Ilibft -c $< -o $@ $(CFLAGS)

bonus:
	$(MAKE) WITH_BONUS=1 all

clean:
	/bin/rm -f $(OBJECTS) main.o
	$(MAKE) -C libft clean

fclean: clean
	$(MAKE) -C mlx clean
	/bin/rm -f $(NAME) execute
	/bin/rm -f libft/libft.a
	/bin/rm -f libft.a libmlx.dylib

re: fclean all

libft:
	$(MAKE) -C libft bonus

.PHONY: all clean fclean re libft
