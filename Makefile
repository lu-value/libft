# ===============================
# Makefile libft multi-build
# ===============================

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

SRC_DIR = src
INC_DIR = includes
BUILD_DIR = build

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
       ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c ft_memchr.c \
       ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
       ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
       ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c \
       ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
       ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
       ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
       ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
       ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
       ft_gnl.c

SRCS := $(addprefix $(SRC_DIR)/,$(SRCS))
OBJS = $(SRCS:.c=.o)

# Colors
GREEN = \033[0;32m
CYAN = \033[0;36m
YELLOW = \033[0;33m
PURPLE = \033[0;35m
RESET = \033[0m
BOLD = \033[1m

# List of architectures for macOS universal
ARCHS ?= arm64 x86_64

# Arch-specific object paths (evaluated lazily so ARCH can be set per invocation)
ARCH_OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/$(ARCH)/%.o,$(SRCS))

# Default: portable single-arch build
%.o: %.c
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Creating $(NAME)...$(RESET)"
	@ar -rsc $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) created successfully!$(RESET)"

# macOS-only: arch-specific object rule (uses -arch flag, separate build directory per arch)
$(BUILD_DIR)/$(ARCH)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)/$(ARCH)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -arch $(ARCH) -c $< -o $@

# macOS-only: build static lib for a single arch; requires ARCH to be set
lib-arch: $(ARCH_OBJS)
	@echo "$(YELLOW)Compiling libft for $(ARCH)...$(RESET)"
	@ar -rsc libft_$(ARCH).a $(ARCH_OBJS)
	@echo "$(GREEN)libft_$(ARCH).a built.$(RESET)"

# Build universal lib (macOS only)
universal:
	@echo "$(YELLOW)Building universal libft for macOS...$(RESET)"
	@for ARCH in $(ARCHS); do \
		$(MAKE) lib-arch ARCH=$$ARCH; \
	done
	@lipo -create $(foreach a,$(ARCHS),libft_$(a).a) -output libft.a
	@rm -f $(foreach a,$(ARCHS),libft_$(a).a)
	@rm -rf $(BUILD_DIR)
	@echo "$(GREEN)libft.a universal created!$(RESET)"

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@rm -f $(OBJS)
	@rm -rf $(BUILD_DIR)
	@echo "$(GREEN)Clean complete.$(RESET)"

fclean: clean
	@echo "$(YELLOW)Removing static libraries...$(RESET)"
	@rm -f libft.a libft_*.a
	@echo "$(GREEN)Full clean complete.$(RESET)"

re: fclean all

.PHONY: all clean fclean re universal lib-arch