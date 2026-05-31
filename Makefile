NAME		= cub3D

CC			= cc
CFLAGS		= -g -Wall -Wextra #-Werror

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= inc
MLX_DIR		= lib/minilibx-linux
LIBFT_DIR	= lib/libft

SRCS		= $(shell find $(SRC_DIR) -name '*.c') # TODO: replace wildcard
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

MLX			= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_FLAGS	= -L$(LIBFT_DIR) -lft

INCLUDES	= -I$(INC_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

debug: fclean
	$(MAKE) all CFLAGS="$(CFLAGS) -g"

.PHONY: all clean fclean re debug
