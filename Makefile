# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 09:27:25 by zakdim            #+#    #+#              #
#    Updated: 2021/01/09 19:54:03 by zakdim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

LIB = cub.a

SRC = 	./cub_utilise/cub_utils.c ./cubsprite/cub_sprite.c ./cubsprite/sprite_utilise.c ./cub_utilise/cub_initial.c \
		./cub_pars/ft_atoi.c ./cub_pars/get_next_line.c \
		./cub_pars/get_nex_line_util.c ./cub_pars/cub_pars.c \
		./cub_pars/table_manag.c cub.c keypress.c ./cub_pars/util_pars.c \
		raycasting.c ./saveimage/bmp_image.c ./cub_pars/inial_pars.c \
		./cub_pars/ceill_floor.c build_screen.c ./saveimage/image_util.c \
		./cub_pars/util2_pars.c ./cub_pars/util3_pars.c raycasting_util.c \
		

OBJ=$(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(LIB) $(OBJ)
	@gcc $(CFLAGS) $(LIB) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo 'SUCCESS!'

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIB)

re: fclean all
