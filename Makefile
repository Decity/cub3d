NAME		= cub3D

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= inc
MLX_DIR		= lib/minilibx-linux
LIBFT_DIR	= lib/libft

SRCS		= $(SRC_DIR)/main.c \
			  $(SRC_DIR)/run.c \
			  $(SRC_DIR)/error.c \
			  $(SRC_DIR)/clean_up.c \
			  $(SRC_DIR)/helpers/checker.c \
			  $(SRC_DIR)/helpers/cub_split.c \
			  $(SRC_DIR)/helpers/mlx_helper.c \
			  $(SRC_DIR)/hooks/controls.c \
			  $(SRC_DIR)/hooks/esc.c \
			  $(SRC_DIR)/init/init_data.c \
			  $(SRC_DIR)/init/init_mlx.c \
			  $(SRC_DIR)/movement/movement.c \
			  $(SRC_DIR)/parsing/map_bounds.c \
			  $(SRC_DIR)/parsing/parse.c \
			  $(SRC_DIR)/parsing/parse_chars.c \
			  $(SRC_DIR)/parsing/parse_cub_params.c \
			  $(SRC_DIR)/parsing/parse_map_data.c \
			  $(SRC_DIR)/parsing/read_file.c \
			  $(SRC_DIR)/parsing/set_color.c \
			  $(SRC_DIR)/parsing/set_player_coords.c \
			  $(SRC_DIR)/parsing/set_texture.c \
			  $(SRC_DIR)/parsing/validate_map.c \
			  $(SRC_DIR)/parsing/validate_texture_paths.c \
			  $(SRC_DIR)/parsing/validate_walls.c \
			  $(SRC_DIR)/raycast/dda.c \
			  $(SRC_DIR)/raycast/raycast.c \
			  $(SRC_DIR)/render/draw_line.c \
			  $(SRC_DIR)/render/draw_wall.c \
			  $(SRC_DIR)/render/fps.c \
			  $(SRC_DIR)/render/render.c \
			  $(SRC_DIR)/textures/textures.c
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

MLX			= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_FLAGS	= -L$(LIBFT_DIR) -lft

INCLUDES	= -I$(INC_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR)/include

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
