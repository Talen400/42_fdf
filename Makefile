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
OBJ_DIR := ./objs
LIBFT_DIR := ./libft
MLX42	:= ./MLX42

# Headears
HEADERS	:= -I ./includes -I $(MLX42)/include

# Libraries

LIBFT	 := $(LIBFT_DIR)/libft.a
LIBMLX_A := $(MLX42)/build/libmlx42.a
LIBS	:= $(LIBMLX_A) $(LIBFT) -ldl -lglfw -pthread -lm

# Sources

SRCS	:= $(shell find $(SRC_DIR) -name "*.c")
OBJS	:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Default target
all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(BLUE)Created objects directory$(RESET)"

$(LIBFT):
	@echo "$(YELLOW)Building libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)Libft built successfully!$(RESET)"

$(LIBMLX_A):
	@echo "$(YELLOW)Building MLX42...$(RESET)"
	@cmake $(MLX42) -B $(MLX42)/build > /dev/null 2>&1
	@$(MAKE) -C $(MLX42)/build -j4 > /dev/null 2>&1
	@echo "$(GREEN)MLX42 built successfully!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo "$(CYAN)Compiled: $(notdir $<)$(RESET)"

$(NAME): $(LIBFT) $(LIBMLX_A) $(OBJS)
	@echo "$(YELLOW)Linking $(NAME)...$(RESET)"
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "$(GREEN)$(NAME) built successfully!$(RESET)"

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(RED)Clean completed!$(RESET)"

fclean: clean
	@echo "$(RED)Full clean...$(RESET)"
	@rm -rf $(NAME)
	@rm -rf $(MLX42)/build
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(RED)Full clean completed!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
