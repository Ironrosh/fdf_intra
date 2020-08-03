# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/07 16:23:01 by mhorpe            #+#    #+#              #
#    Updated: 2020/07/30 22:40:23 by mhorpe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCE = 	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
			ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c\
			ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c\
			ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c\
			ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c\
			ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
			ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c\
			ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_free2darr.c\
			ft_range.c ft_swap.c ft_recursive_factorial.c ft_count_whitespaces.c get_next_line.c ft_count_words.c ft_strndup.c\

OBJ_FILES = $(SOURCE:.c=.o)

HEADER = libft.h

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rc $(NAME) $(OBJ_FILES)
	ranlib $(NAME)
clean:
	rm -f $(OBJ_FILES)
fclean: clean
	rm -f $(NAME)
re: fclean all

%.o: %.c $(HEADER)
	gcc -Wall -Wextra -Werror -c $< -o $@
