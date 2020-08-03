# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/03 13:54:25 by mhorpe            #+#    #+#              #
#    Updated: 2020/08/03 13:57:36 by mhorpe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = fdf
FLAGS       = -Wall -Wextra -Werror
SRC_DIR		= ./src
OBJ_DIR		= ./obj
CFILES		= main.c colors.c error.c graphics.c key_events.c read_from_file.c rotation.c support_functions.c support_functions_2.c
OFILES		= $(CFILES:.c=.o)
RAW_CFILES	= $(addprefix $(SRC_DIR)/,$(CFILES))
RAW_OFILES	= $(addprefix $(OBJ_DIR)/,$(OFILES))

all: $(OBJ_DIR) $(NAME)
$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(NAME): $(RAW_OFILES)
		make -C ./minilibx_macos
		make -C ./libft
		gcc $(RAW_OFILES) libft/libft.a minilibx_macos/libmlx.a -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit -I ./includes -I ./libft -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		gcc $(FLAGS) -I ./includes -I ./libft -c $< -o $@
clean:
		make clean -C ./minilibx_macos
		make clean -C ./libft
		rm -f $(RAW_OFILES)

fclean: clean 
		make clean -C ./minilibx_macos
		make fclean -C ./libft
		rm -rf $(NAME)

re: fclean all
