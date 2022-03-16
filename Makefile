NAME		= so_long

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g -fsanitize=address
MLXFLAGS	= -framework OpenGL -framework Appkit

LIBFT		= ./libft/libft.a
FT_PRINTF	= ./ft_printf/libftprintf.a
MLX			= ./mlx/libmlx.a

SRCS		= src/main.c \
			src/initialize_game.c \
			src/hook_events.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c \
			src/map_parsing.c \
			


OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(LIBFT):
		$(MAKE) -C ./libft
$(FT_PRINTF):
		$(MAKE) -C ./ft_printf
$(MLX):
		$(MAKE) -C ./mlx

$(NAME): 	$(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX) -o $(NAME)
	@echo "\033[92mDone\033[0m"

clean:
	rm -f $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX)
	$(MAKE) -C libft/ clean
	$(MAKE) -C ft_printf/ clean
	$(MAKE) -C mlx/ clean
	@echo "\033[92mClean\033[0m"
	
fclean:		clean
	rm -f $(NAME)
	@$(MAKE) -C libft/ clean
	@$(MAKE) -C ft_printf/ clean
	@echo "\033[92mFclean\033[0m"

re:			fclean all

.PHONY:		all clean fclean re