# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laballea <laballea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 12:07:35 by laballea          #+#    #+#              #
#    Updated: 2019/11/18 13:39:35 by laballea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFLAGS = -Wall -Wextra -Werror

SRC = ft_printflags.c ft_getflags.c ft_flags.c ft_putfd2.c ft_putfd.c ft_utils.c ft_printf.c


SRCLIB = libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c \
		libft/ft_isprint.c libft/ft_itoa.c libft/ft_memcpy.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memccpy.c libft/ft_memmove.c \
		libft/ft_memset.c libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_split.c \
		libft/ft_strchr.c libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c \
		libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c \
		libft/ft_strcat.c libft/ft_itoaunsigned.c  libft/ft_putnbr_base_uns.c \
		libft/ft_putnbr_base.c libft/ft_intlen.c libft/ft_unslen.c libft/ft_abs.c

INCLUDE = /ft_printf.h ./libft/libft.h

NAME = ft_printf
NAMELIB = libftprintf.a
OBJ = $(subst .c,.o,$(SRC))
OBJLIB = $(subst .c,.o, $(SRCLIB))

all: $(NAME)

$(NAME): $(OBJ)
		cd libft && make
		gcc $(CFLAGS) -c -I$(INCLUDE) $(SRC)
		ar rc $(NAMELIB) $(OBJ) $(OBJLIB)
		ranlib $(NAMELIB)
	
bonus:
	all
	
clean:
	rm -f $(OBJ)
	cd libft && make fclean

fclean: clean
	rm -f $(NAMELIB)

re: fclean all

.PHONY : $(NAME) fclean re clean