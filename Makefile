EXECUTABLE	= fdf
LIBFT	= libs/libft/libft.a
MLX = libs/mlx/libmlx_Linux.a
LIBFT_PATH = libs/libft
MLX_PATH = libs/mlx

INCLUDE = -I./ -I./$(LIBFT_PATH) -I./$(MLX_PATH)
CFLAGS = -Wall -Wextra -Werror  

SRCS_NAMES = main.c \
	parsing.c \
	parsing_utils.c \
	projection.c \
	offset_and_scale.c \
	rendering.c \
	rendering_utils.c 

SRCS = $(addprefix srcs/, $(SRCS_NAMES))
OBJS = $(SRCS_NAMES:.c=.o)

all		: $(EXECUTABLE)

$(EXECUTABLE): $(LIBFT) $(OBJS) $(MLX)
	cc $(OBJS) -L$(LIBFT_PATH) -lft -o $(EXECUTABLE) -L$(MLX_PATH) -lmlx_Linux -lXext -lX11 -lm -lz 

%.o: srcs/%.c
	cc -g $(CFLAGS) $(INCLUDE) -c $< -o $@
 
$(LIBFT): 
	make -C $(LIBFT_PATH)

$(MLX):
	make -C $(MLX_PATH)

fclean	: clean
	rm -f $(EXECUTABLE) 

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_PATH)
	make clean -C $(MLX_PATH)

re		: fclean all

.PHONY: clean fclean all re
