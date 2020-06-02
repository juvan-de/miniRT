# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: juvan-de <juvan-de@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/27 11:29:28 by juvan-de       #+#    #+#                 #
#    Updated: 2020/03/12 16:47:50 by juvan-de      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = minirt

OBJ_DIR = ./obj/
OBJ_FILES = test.o \
			maths.o \
			pars.o \
			pars_amb.o \
			get_next_line.o \
			get_next_line_utils.o \
			utils.o \
			free.o \
			pars_cam.o \

OBJECTS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

SRC_DIR = ./src/

INC_DIR = ./includes/
INC_FILES = 
INCLUDES = $(addprefix $(INC_DIR), $(INC_FILES))

LIBFT = -L./libft -lft

CFLAGS = -Wall -Werror -Wextra

MAIN = 

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C libft
	@cp libft/libft.a .
	make -C mlx
	$(CC) -Lmlx/ -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJECTS) $(LIBFT)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@gcc -Wall -Werror -Wextra -Imlx  -Ilibft -c $< -o $@

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
