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

# List of architectures for macOS universal
ARCHS ?= arm64 x86_64

# Compile one arch
%.o: %.c
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Build lib for a single arch
lib-arch: clean $(OBJS)
	@echo "$(YELLOW)Compiling libft for $(ARCH)...$(RESET)"
	@ar -rsc libft_$(ARCH).a $(OBJS)
	@echo "$(GREEN)libft_$(ARCH).a built.$(RESET)"

# Build universal lib (macOS)
universal: clean
	@echo "$(YELLOW)Building universal libft for macOS...$(RESET)"
	@for ARCH in $(ARCHS); do \
		$(MAKE) lib-arch ARCH=$$ARCH; \
	done
	@lipo -create $(foreach a,$(ARCHS),libft_$(a).a) -output libft.a
	@rm -f $(foreach a,$(ARCHS),libft_$(a).a)
	@echo "$(GREEN)libft.a universal created!$(RESET)"

# Default all
all: universal

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@rm -f $(OBJS)
	@echo "$(GREEN)Clean complete.$(RESET)"

fclean: clean
	@echo "$(YELLOW)Removing static libraries...$(RESET)"
	@rm -f libft.a libft_*.a
	@echo "$(GREEN)Full clean complete.$(RESET)"

re: fclean all

.PHONY: all clean fclean re universal lib-arch
