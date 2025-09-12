NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

# Colors
GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
YELLOW = \033[0;33m
RESET = \033[0m

# ================================== SOURCES ================================= #

# Libft mandatory functions
LIBFT_SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

# Libft bonus functions (linked lists)
LIBFT_BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

# Get Next Line BONUS - SEMPRE (múltiplos file descriptors)
GNL_SRC = get_next_line_bonus.c

# Printf functions
PRINTF_SRC = ft_printf.c ft_printpointer.c ft_printchar.c ft_printdecimal.c \
			ft_printstr.c ft_printunsigned.c ft_printhexa.c

# ================================== OBJECTS ================================= #

LIBFT_OBJ = $(LIBFT_SRC:.c=.o)
LIBFT_BONUS_OBJ = $(LIBFT_BONUS_SRC:.c=.o)  
GNL_OBJ = $(GNL_SRC:.c=.o)
PRINTF_OBJ = $(PRINTF_SRC:.c=.o)

# Objetos mandatórios - inclui GNL BONUS por padrão
MANDATORY_OBJ = $(LIBFT_OBJ) $(GNL_OBJ) $(PRINTF_OBJ)

# Todos os objetos incluindo bonus da libft
ALL_OBJ = $(MANDATORY_OBJ) $(LIBFT_BONUS_OBJ)

# Headers - usando get_next_line_bonus.h
HEADERS = libft.h

# ================================== RULES =================================== #

all: $(NAME)

$(NAME): $(MANDATORY_OBJ)
	@echo "$(BLUE)Creating library $(NAME)...$(RESET)"
	@$(AR) $(NAME) $(MANDATORY_OBJ)
	@echo "$(GREEN)✓ $(NAME) created successfully!$(RESET)"
	@echo "$(YELLOW)✓ Includes: libft + GNL BONUS (multi-FD) + ft_printf$(RESET)"

%.o: %.c $(HEADERS)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(ALL_OBJ)
	@echo "$(BLUE)Creating library $(NAME) with libft bonus...$(RESET)"
	@$(AR) $(NAME) $(ALL_OBJ)
	@echo "$(GREEN)✓ $(NAME) with libft bonus created successfully!$(RESET)"
	@echo "$(YELLOW)✓ Includes: libft + libft bonus (lists) + GNL BONUS + ft_printf$(RESET)"

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@$(RM) $(ALL_OBJ)
	@echo "$(GREEN)✓ Clean completed!$(RESET)"

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(GREEN)✓ Full clean completed!$(RESET)"

re: fclean all

# Test rule
test: $(NAME)
	@echo "$(BLUE)Compiling test...$(RESET)"
	@$(CC) $(CFLAGS) -L. -lft test/main.c -o test_program
	@echo "$(GREEN)✓ Test compiled! Run with ./test_program$(RESET)"

# Debug version
debug: CFLAGS += -g -fsanitize=address
debug: re

# Show what will be compiled
show:
	@echo "$(BLUE)Files that will be compiled:$(RESET)"
	@echo "$(GREEN)LIBFT:$(RESET) $(LIBFT_SRC)"
	@echo "$(GREEN)GNL BONUS:$(RESET) $(GNL_SRC)"
	@echo "$(GREEN)PRINTF:$(RESET) $(PRINTF_SRC)"
	@echo "$(GREEN)LIBFT BONUS:$(RESET) $(LIBFT_BONUS_SRC)"

# Show help
help:
	@echo "$(BLUE)Available targets:$(RESET)"
	@echo "  $(GREEN)all$(RESET)     - Build library (libft + GNL bonus + printf)"
	@echo "  $(GREEN)bonus$(RESET)   - Build with libft bonus (linked lists)"
	@echo "  $(GREEN)clean$(RESET)   - Remove object files"
	@echo "  $(GREEN)fclean$(RESET)  - Remove objects and library"
	@echo "  $(GREEN)re$(RESET)      - Rebuild everything"
	@echo "  $(GREEN)show$(RESET)    - Show which files will be compiled"
	@echo "  $(GREEN)test$(RESET)    - Compile test program"
	@echo "  $(GREEN)debug$(RESET)   - Build with debug flags"

.PHONY: all bonus clean fclean re test debug help show
