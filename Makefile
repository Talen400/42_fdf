# Colors for output
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
RESET = \033[0m

# Configuration
NAME := fdf
CC := cc
CFLAGS	:= -g -Wextra -Wall -Werror -Wunreachable-code -Ofast

# Directories
SRC_DIR := ./srcs
SRC_BONUS_DIR := ./srcs_bonus
OBJ_DIR := ./objs
OBJ_BONUS_DIR := ./objs_bonus
LIBFT_DIR := ./libft
MLX42	:= ./MLX42

# Headears
HEADERS	:= -I ./includes -I $(MLX42)/include

# Libraries
LIBFT	 := $(LIBFT_DIR)/libft.a
LIBMLX_A := $(MLX42)/build/libmlx42.a
LIBS	:= $(LIBMLX_A) $(LIBFT) -ldl -lglfw -pthread -lm

# Mandatory sources
SRCS := $(SRC_DIR)/main.c \
		$(SRC_DIR)/ft_bresenham.c \
		$(SRC_DIR)/ft_calibrate.c \
		$(SRC_DIR)/ft_colors.c \
		$(SRC_DIR)/ft_hex.c \
		$(SRC_DIR)/ft_keyboard.c \
		$(SRC_DIR)/ft_map.c \
		$(SRC_DIR)/ft_mlx_utils.c \
		$(SRC_DIR)/ft_read.c \
		$(SRC_DIR)/ft_read_utils.c \
		$(SRC_DIR)/ft_vectors.c

OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Bonus sources
SRCS_BONUS := $(SRC_BONUS_DIR)/main_bonus.c \
			  $(SRC_BONUS_DIR)/ft_axis_bonus.c \
			  $(SRC_BONUS_DIR)/ft_axis_utils_bonus.c \
			  $(SRC_BONUS_DIR)/ft_bresenham_bonus.c \
			  $(SRC_BONUS_DIR)/ft_calibrate_bonus.c \
			  $(SRC_BONUS_DIR)/ft_colors_bonus.c \
			  $(SRC_BONUS_DIR)/ft_hex_bonus.c \
			  $(SRC_BONUS_DIR)/ft_hud_bonus.c \
			  $(SRC_BONUS_DIR)/ft_hud_utils_bonus.c \
			  $(SRC_BONUS_DIR)/ft_keyboard_bonus.c \
			  $(SRC_BONUS_DIR)/ft_map_bonus.c \
			  $(SRC_BONUS_DIR)/ft_math_bonus.c \
			  $(SRC_BONUS_DIR)/ft_mlx_utils_bonus.c \
			  $(SRC_BONUS_DIR)/ft_projections_bonus.c \
			  $(SRC_BONUS_DIR)/ft_read_bonus.c \
			  $(SRC_BONUS_DIR)/ft_read_utils_bonus.c \
			  $(SRC_BONUS_DIR)/ft_vectors_bonus.c \
			  $(SRC_BONUS_DIR)/ft_vectors_utils_bonus.c

OBJS_BONUS := $(SRCS_BONUS:$(SRC_BONUS_DIR)/%.c=$(OBJ_BONUS_DIR)/%.o)

MANDATORY_MARK := .mandatory
BONUS_MARK := .bonus

# Default target
all: $(NAME)

# Mandatory part
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(BLUE)Created objects directory$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo "$(CYAN)Compiled: $(notdir $<)$(RESET)"

$(NAME): $(MANDATORY_MARK)

$(MANDATORY_MARK): $(LIBFT) $(LIBMLX_A) $(OBJS)
	@rm -f $(BONUS_MARK)
	@echo "$(YELLOW)Linking $(NAME)...$(RESET)"
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	@touch $(MANDATORY_MARK)
	@echo "$(GREEN)$(NAME) built successfully!$(RESET)"

# Bonus part
$(OBJ_BONUS_DIR):
	@mkdir -p $(OBJ_BONUS_DIR)
	@echo "$(BLUE)Created bonus objects directory$(RESET)"

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c | $(OBJ_BONUS_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo "$(MAGENTA)Compiled bonus: $(notdir $<)$(RESET)"

bonus: $(BONUS_MARK)

$(BONUS_MARK): $(LIBFT) $(LIBMLX_A) $(OBJS_BONUS)
	@rm -f $(MANDATORY_MARK)
	@echo "$(YELLOW)Linking $(NAME) (bonus)...$(RESET)"
	@$(CC) $(OBJS_BONUS) $(LIBS) $(HEADERS) -o $(NAME)
	@touch $(BONUS_MARK)
	@echo "$(GREEN)$(NAME) (bonus) built successfully!$(RESET)"

# Libraries
$(LIBFT):
	@echo "$(YELLOW)Building libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)Libft built successfully!$(RESET)"

$(LIBMLX_A):
	@echo "$(YELLOW)Building MLX42...$(RESET)"
	@cmake $(MLX42) -B $(MLX42)/build > /dev/null 2>&1
	@$(MAKE) -C $(MLX42)/build -j4 > /dev/null 2>&1
	@echo "$(GREEN)MLX42 built successfully!$(RESET)"

# Clean rules
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_BONUS_DIR)
	@rm -f $(MANDATORY_MARK)
	@rm -f $(BONUS_MARK)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(RED)Clean completed!$(RESET)"

fclean: clean
	@echo "$(RED)Full clean...$(RESET)"
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@rm -rf $(MLX42)/build
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(RED)Full clean completed!$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus
