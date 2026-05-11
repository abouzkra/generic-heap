CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./includes
NAME = heap.a
SRCS = ./src/ft_memmove.c \
	   ./src/ft_memset.c  \
	   ./src/ft_putstr.c  \
	   ./src/ft_swap.c    \
	   ./src/heap.c

OBJS = $(SRCS:.c=.o)
RM = rm -rf

EXAMPLES_DIR = ./examples
EXAMPLES_SRC = $(wildcard $(EXAMPLES_DIR)/*.c)
EXAMPLES_BIN = $(basename $(EXAMPLES_SRC))

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

examples: $(NAME) $(EXAMPLES_BIN)

$(EXAMPLES_DIR)/%: $(EXAMPLES_DIR)/%.c
	$(CC) $(CFLAGS) $< $(NAME) -o $@
	@echo "compiled example: $@"
 
clean:
	$(RM) $(OBJS)
	$(RM) $(EXAMPLES_BIN)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re examples
