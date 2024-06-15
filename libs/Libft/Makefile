# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 13:28:56 by ybarbot           #+#    #+#              #
#    Updated: 2024/01/16 12:00:41 by ybarbot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -fPIE

NAME = libft.a

CC = cc

SOURCES = ft_atoi.c ft_isdigit.c ft_memcpy.c ft_strlcpy.c ft_toupper.c \
ft_bzero.c ft_isprint.c ft_memmove.c ft_strlen.c ft_isalnum.c \
ft_memchr.c ft_memset.c ft_strncmp.c ft_isalpha.c ft_strchr.c \
ft_strrchr.c ft_isascii.c ft_memcmp.c ft_strlcat.c ft_tolower.c\
ft_strnstr.c ft_strdup.c ft_calloc.c ft_strtrim.c ft_strjoin.c \
ft_substr.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strcpy.c \
ft_strndup.c \
\
ft_printf/ft_printf.c ft_printf/ft_putlnbr_ulongbase.c \
ft_printf/nbr_utils.c ft_printf/printf_utils.c \
\
get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
\
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstadd_back.c \
ft_lstdelone.c ft_lstclear.c ft_lstmap.c ft_lstiter.c ft_lstlast.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
