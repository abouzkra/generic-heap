CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIC -I./includes
LDFLAGS = -shared
NAME = heap
SRCS = ./src/ft_memmove.c \
	   ./src/ft_memset.c  \
	   ./src/ft_swap.c    \
	   ./src/heap.c

STATIC_LIB = $(NAME).a
SHARED_LIB = $(NAME).so

OBJS = $(SRCS:.c=.o)
RM = rm -rf

EXAMPLES_DIR = ./examples
EXAMPLES_SRC = $(wildcard $(EXAMPLES_DIR)/*.c)
EXAMPLES_BIN = $(basename $(EXAMPLES_SRC))

all: $(STATIC_LIB) $(SHARED_LIB)

$(STATIC_LIB): $(OBJS)
	ar rcs $@ $^

$(SHARED_LIB): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

examples: $(STATIC_LIB) $(EXAMPLES_BIN)

$(EXAMPLES_DIR)/%: $(EXAMPLES_DIR)/%.c
	$(CC) $(CFLAGS) $< $(STATIC_LIB) -o $@
 
clean:
	$(RM) $(OBJS)
	$(RM) $(EXAMPLES_BIN)

fclean: clean
	$(RM) $(STATIC_LIB) $(SHARED_LIB)

re: fclean all

.PHONY: all clean fclean re examples
