# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: juvan-de <juvan-de@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/27 11:29:28 by juvan-de      #+#    #+#                  #
#    Updated: 2020/06/17 17:14:18 by juvan-de      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = minirt

OBJ_DIR = ./obj/
OBJ_FILES = test.o \
			maths.o \
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
			free.o \
			main.o \
			projecting.o \
			sphere_collision.o \
			plane_collision.o \
			square_collision.o \
			triangle_collision.o \
			cylinder_collision.o \
			light.o \
			mlx.o \
			keys.o \
			vector.o \
			matrix.o \
				
OBJECTS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

SRC_DIR = ./src/

INC_DIR = ./includes/
INC_FILES = 
INCLUDES = $(addprefix $(INC_DIR), $(INC_FILES))

LIBFT = -L./libft -lft

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C libft
	@cp libft/libft.a .
	make -C mlx
	$(CC) -Lmlx/ -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJECTS) $(LIBFT) $(CFLAGS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@gcc -Imlx -Ilibft -c $< -o $@

bonus:
	$(MAKE) WITH_BONUS=1 all

clean:
	/bin/rm -f $(OBJECTS) main.o
	$(MAKE) -C libft clean

fclean: clean
	/bin/rm -f $(NAME) execute
	/bin/rm -f libft/libft.a

re: fclean all

libft:
	$(MAKE) -C libft bonus

.PHONY: all $(NAME) clean fclean re libft exe
