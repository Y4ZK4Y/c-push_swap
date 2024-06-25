# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ykarimi <ykarimi@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2024/05/22 13:55:25 by ykarimi       #+#    #+#                  #
#    Updated: 2024/06/25 10:22:49 by yasamankari   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror
LIBFT = lib/libft/libft.a
INCLUDES = -I./include -I./lib/libft/include
BUILD = ./build

SRCS = src/big_sort.c src/error_cleanup.c src/indexer_utils.c \
src/indexer.c src/main.c src/medium_sort.c src/node_utils.c src/ops_a.c \
src/ops_b.c src/ops_ab.c src/parsing.c src/small_sort.c src/sort_engine.c \
src/stack_utils.c src/stack_ops.c src/stack_ops_ii.c


OBJS = $(patsubst src/%.c,$(BUILD)/%.o,$(SRCS))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "Push_swap YAAAAY!"

$(LIBFT):
	@make -C lib/libft > /dev/null

$(BUILD)/%.o: src/%.c
	@mkdir -p $(BUILD) > /dev/null
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@ > /dev/null

clean:
	@make -C lib/libft clean > /dev/null
	@rm -f $(OBJS) > /dev/null && echo "Object files went poof!"

fclean: clean
	@make -C lib/libft fclean > /dev/null
	@rm -f $(NAME) > /dev/null && echo "Executables went poof!"
	@rm -rf $(BUILD) > /dev/null && echo "Build directory went poof!"

re: fclean all

.PHONY: all clean fclean re