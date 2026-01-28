CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC_DIR = src
INC_DIR = includes

SRCS =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
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

SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS = $(SRCS:.c=.o)

# Colors
GREEN = \033[0;32m
CYAN = \033[0;36m
YELLOW = \033[0;33m
PURPLE = \033[0;35m
RESET = \033[0m
BOLD = \033[1m

TOTAL = $(words $(SRCS))

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(NAME): $(OBJS)
	@echo "$(YELLOW)Compiling libft...$(RESET)\n"
	@for file in $(OBJS); do \
		total=$(TOTAL); \
		current=$$(echo "$(OBJS)" | tr ' ' '\n' | grep -n "$$file" | cut -d: -f1); \
		percent=$$((current * 100 / total)); \
		filled=$$((current * 30 / total)); \
		empty=$$((30 - filled)); \
		bar=""; \
		for i in $$(seq 1 $$filled); do bar="$$bar#"; done; \
		for i in $$(seq 1 $$empty); do bar="$$bar-"; done; \
		name=$$(basename $$file .o); \
		printf "\r  $(CYAN)[$(GREEN)$$bar$(CYAN)] $(YELLOW)%3d%% $(PURPLE)$$name$(RESET)        " $$percent; \
	done
	@printf "\r  $(CYAN)[$(GREEN)##############################$(CYAN)] $(YELLOW)100%% $(GREEN)Done!$(RESET)                    \n\n"
	@ar -rsc $(NAME) $(OBJS)
	@echo "$(GREEN)$(BOLD)$(NAME) created successfully!$(RESET)\n"

all: $(NAME)

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@rm -f $(OBJS)
	@echo "$(GREEN)Clean complete!$(RESET)"

fclean: clean
	@echo "$(YELLOW)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)Full clean complete!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
