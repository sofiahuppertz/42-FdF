EXECUTABLE	= fdf
LIBFT	= libs/libft/libft.a
MINILIB = libs/minilibx-linux/libmlx.a

INCLUDE = -I. -I/libs/libft/ -I./libs/minilibx-linux
CFLAGS = -Wall -Wextra -Werror
LIBS_AND_PATH = -L libs/libft -lft -L libs/minilibx-linux -lmlx

SRCS_NAMES = main.c \
	parsing.c \
	parsing_utils.c \
	projection.c \
	rendering.c 

SRCS = $(addprefix srcs/, $(SRCS_NAMES))
OBJS = $(SRCS_NAMES:.c=.o)

$(EXECUTABLE): $(LIBFT) $(MINILIB) $(OBJS)
	gcc -g  $(INCLUDE) $(OBJS) $(LIBS_AND_PATH) -o $(EXECUTABLE)
 
$(LIBFT): 
	make -C libs/libft/

$(MINILIB):
	make -C libs/minilibx-linux/

%.o: srcs/%.c
	cc $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C libs/libft/
	make clean -C libs/minilibx-linux/

re: clean
	rm -f $(EXECUTABLE)

.PHONY: clean re