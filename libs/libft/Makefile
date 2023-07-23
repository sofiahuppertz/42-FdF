# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 18:35:09 by shuppert          #+#    #+#              #
#    Updated: 2023/07/22 15:26:32 by shuppert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_NAME = libft.a

SRCS_NAMES = ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strlen.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_striteri.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
	get_next_line.c \
	get_next_line_utils.c \
	ft_printf.c \
	check_format.c \
	display_adress.c \
	display_char.c \
	display_hexadecimals.c \
	display_integer.c \
	display_text.c \
	display_unsigned_integer.c \
	str_array_length.c 

SRCS_DIR	= srcs/
OBJECTS_DIR	= objects/

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NAMES))

OBJS = $(addprefix $(OBJECTS_DIR), ${SRCS_NAMES:.c=.o})

all			: $(LIB_NAME)

$(LIB_NAME)	: $(OBJS)
	ar rcs $(LIB_NAME) $(OBJS)

objects/%.o	: $(SRCS_DIR)%.c $(OBJECTS_DIR)
	cc -Wall -Wextra -Werror -I. -c $< -o $@

$(OBJECTS_DIR)	:
	mkdir -p objects

clean		: fclean
	rm -f $(LIB_NAME)

fclean		:
	rm -f $(OBJS)

re			:	fclean all

.PHONY: all clean fclean re