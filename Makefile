# ===============================
# Makefile libft linux build
# ===============================

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

SRC_DIR = src
INC_DIR = includes

SRCS = stdlib/ft_atoi.c memory/ft_bzero.c stdlib/ft_calloc.c \
       ctype/ft_isalnum.c ctype/ft_isalpha.c ctype/ft_isascii.c \
       ctype/ft_isdigit.c ctype/ft_isprint.c ctype/ft_isspace.c \
       memory/ft_memchr.c memory/ft_memcmp.c memory/ft_memcpy.c \
       memory/ft_memmove.c memory/ft_memset.c string/ft_strchr.c \
       string/ft_strdup.c string/ft_strlcat.c string/ft_strlcpy.c \
       string/ft_strlen.c string/ft_strncmp.c string/ft_strnstr.c \
       string/ft_strrchr.c ctype/ft_tolower.c ctype/ft_toupper.c \
       string/ft_substr.c string/ft_strjoin.c string/ft_strtrim.c \
       string/ft_split.c stdlib/ft_itoa.c string/ft_strmapi.c \
       string/ft_striteri.c io/ft_putchar_fd.c io/ft_putstr_fd.c \
       io/ft_putendl_fd.c io/ft_putnbr_fd.c io/write_console.c list/ft_lstnew.c \
       list/ft_lstadd_front.c list/ft_lstsize.c list/ft_lstlast.c \
       list/ft_lstadd_back.c list/ft_lstdelone.c list/ft_lstclear.c \
       list/ft_lstiter.c list/ft_lstmap.c io/ft_gnl.c \
       printf/ft_printf.c printf/ft_putchar.c printf/ft_puthexa.c \
       printf/ft_putnbr.c printf/ft_putpointer.c printf/ft_putstr.c \
       printf/ft_putunsigned.c \
       extra/ft_get_bit.c

SRCS := $(addprefix $(SRC_DIR)/,$(SRCS))
OBJS = $(SRCS:.c=.o)

# Colors
GREEN = \033[0;32m
CYAN = \033[0;36m
YELLOW = \033[0;33m
PURPLE = \033[0;35m
RESET = \033[0m
BOLD = \033[1m

# Compile sources
%.o: %.c
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Default build
all: linux

# Linux build: standard static library
linux: $(OBJS)
	@echo "$(YELLOW)Building libft for Linux...$(RESET)"
	@ar -rsc $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) built for Linux.$(RESET)"

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@rm -f $(OBJS)
	@echo "$(GREEN)Clean complete.$(RESET)"

fclean: clean
	@echo "$(YELLOW)Removing static library...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)Full clean complete.$(RESET)"

re: fclean all

.PHONY: all clean fclean re linux
