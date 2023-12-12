# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 19:46:45 by soelalou          #+#    #+#              #
#    Updated: 2023/12/12 18:13:38 by soelalou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# VARIABLES

NAME        =	push_swap
CHECK		=	checker
LIBFT		=	libft/libft.a
CC          =	cc
CFLAGS      =	-Wall -Wextra -Werror
RM          =	rm -rf

SRCS		=	src/main.c src/complex.c src/simple.c \
				src/swap.c src/push.c src/reverse.c src/rotate.c \
				src/errors.c src/pos.c src/lists.c src/utils.c

CHECK_SRCS	=	src/swap.c src/push.c src/reverse.c src/rotate.c \
				src/errors.c src/pos.c src/lists.c src/utils.c \
				checker.c

# SRCS		=	src/complex.c src/errors.c src/errors2.c src/lists.c \
# 				src/main.c src/push.c src/reverse.c src/rotate.c src/simple.c src/swap.c \
# 				src/utils.c src/utils2.c
				
OBJS_DIR    =	bin
OBJS        =	$(patsubst src/%.c, $(OBJS_DIR)/%.o, $(SRCS))
CHECK_OBJS	=	$(patsubst src/%.c, $(OBJS_DIR)/%.o, $(CHECK_SRCS))

# **************************************************************************** #
# COLORS

GREEN       =	\033[0;32m
GREY        =	\033[1;30m
PURPLE      =	\033[0;35m
BLUE        =	\033[0;94m
CYAN        =	\033[0;36m
PINK        =	\033[1;35m
END_COLOR   =	\033[0;39m


# **************************************************************************** #
# RULES

all: dependencies $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)[Success]$(END_COLOR) Push_swap is ready !"

$(CHECK): $(CHECK_OBJS)
	@$(CC) $(CFLAGS) $(CHECK_OBJS) $(LIBFT) -o $(CHECK)
	@echo "$(GREEN)[Success]$(END_COLOR) Checker is ready !"

$(OBJS_DIR)/%.o: src/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

dependencies:
	@make -s -C libft

clean:
	@$(RM) $(OBJS_DIR)
	@make clean -s -C libft
	@echo "$(GREY)[Clean]$(END_COLOR) Objects have been deleted"

fclean: clean
	@$(RM) $(OBJS_DIR) $(NAME) $(CHECK) check_linux
	@make fclean -s -C libft
	@echo "$(GREY)[Clean]$(END_COLOR) $(NAME) and executables have been deleted"

re: fclean all
	@echo "$(PURPLE)[Rebuild]$(END_COLOR) Done."

.PHONY: all clean fclean re