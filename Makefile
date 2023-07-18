NAME = fdf

LIBFT = ./libft/libft.a
MLX = libmlx_Linux.a
GNL = ./gnl/get_next_line.a

SRC = 	parsing.c \
		./gnl/get_next_line.c \
		./gnl/get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

all: $(NAME) 

$(GNL):
	make all -C ./gnl

$(LIBFT):
	make all -C ./libft

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 

%.o: %.c $(GNL) $(LIBFT) fdf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./gnl
	make fclean -C ./libft
	rm -f $(NAME) $(OBJ)

re: fclean all

PHONY: all clean fclean re	
