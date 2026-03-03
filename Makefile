# ===============================
# Makefile libft multi-build
# ===============================

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

SRC_DIR = src
INC_DIR = includes

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

# Detect OS
OS := $(shell uname -s)

# List of architectures for macOS universal
ARCHS ?= arm64 x86_64

# Compile one arch
%.o: %.c
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Default all: auto-detect OS
all:
ifeq ($(OS),Darwin)
	@$(MAKE) universal
else
	@$(MAKE) linux
endif

# Linux build: standard static library
linux: $(OBJS)
	@echo "$(YELLOW)Building libft for Linux...$(RESET)"
	@ar -rsc $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) built for Linux.$(RESET)"

# Build universal lib (macOS) with proper per-arch compilation
universal: fclean
	@echo "$(YELLOW)Building universal libft for macOS...$(RESET)"
	@for arch in $(ARCHS); do \
		$(MAKE) $(OBJS) CFLAGS="$(CFLAGS) -arch $$arch"; \
		ar -rsc libft_$$arch.a $(OBJS); \
		rm -f $(OBJS); \
	done
	@lipo -create $(foreach a,$(ARCHS),libft_$(a).a) -output $(NAME)
	@rm -f $(foreach a,$(ARCHS),libft_$(a).a)
	@echo "$(GREEN)$(NAME) universal created!$(RESET)"

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@rm -f $(OBJS)
	@echo "$(GREEN)Clean complete.$(RESET)"

fclean: clean
	@echo "$(YELLOW)Removing static libraries...$(RESET)"
	@rm -f libft.a libft_*.a
	@echo "$(GREEN)Full clean complete.$(RESET)"

re: fclean all

.PHONY: all clean fclean re universal linux
