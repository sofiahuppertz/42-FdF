EXECUTABLE	= fdf
LIBFT	= libs/libft/libft.a
MINILIB = libs/minilibx-linux/libmlx_Linux.a

INCLUDE = -I./ -I/libs/libft/ -I./libs/minilibx-linux
CFLAGS = -Wall -Wextra -Werror
LIBS_AND_PATH = -L libs/libft -lft -L libs/minilibx-linux -lmlx_Linux  -lXext -lX11 -lm -lz

SRCS_NAMES = main.c \
	parsing.c \
	parsing_utils.c \
	projection.c \
	rendering.c 

SRCS = $(addprefix srcs/, $(SRCS_NAMES))
OBJS = $(SRCS_NAMES:.c=.o)

all		: $(EXECUTABLE)

$(EXECUTABLE): $(LIBFT) $(MINILIB) $(OBJS)
	cc $(OBJS) -o $(EXECUTABLE) $(LIBS_AND_PATH)

%.o: srcs/%.c
	cc $(INCLUDE) $(CFLAGS) -c $< -o $@
 
$(LIBFT): 
	make -C libs/libft/

$(MINILIB):
	make -C libs/minilibx-linux/

fclean	: clean
	rm -f $(EXECUTABLE) $(LIBFT) $(MINILIB)

clean:
	rm -f $(OBJS)
	make clean -C libs/libft/
	make clean -C libs/minilibx-linux/


re		: fclean all

.PHONY: clean fclean all re