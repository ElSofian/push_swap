# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/08 12:14:59 by utente            #+#    #+#              #
#    Updated: 2023/12/14 11:10:04 by soelalou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =	push_swap
CHECK		=	checker
LIBFT		=	libft/libft.a
CC          =	cc
CFLAGS      =	-Wall -Wextra -Werror
RM          =	rm -rf

SRCS		=	src/errors.c src/main.c src/push_swap_init.c src/push_swap.c \
				src/push.c src/reverse.c src/rotate.c src/sort.c \
				src/pile_utils.c src/swap.c src/utils.c
CHECK_SRCS	=	src/errors.c src/push_swap_init.c src/push_swap.c \
				src/push.c src/reverse.c src/rotate.c src/sort.c \
				src/pile_utils.c src/swap.c src/utils.c \
				checker.c
				
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
BROWN       =	\033[0;90m
END_COLOR   =	\033[0;39m


# **************************************************************************** #
# RULES

all: dependencies $(NAME) checker_linux

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

checker_linux:
	@curl -s -O https://raw.githubusercontent.com/ElSofian/checker_linux/main/checker_linux
	@chmod 777 checker_linux
	@echo "$(BROWN)[Git]$(END_COLOR) Checker_linux has been imported"

clean:
	@$(RM) $(OBJS_DIR)
	@make clean -s -C libft
	@echo "$(GREY)[Clean]$(END_COLOR) Objects have been deleted"

fclean: clean
	@$(RM) $(OBJS_DIR) $(NAME) $(CHECK) checker_linux
	@make fclean -s -C libft
	@echo "$(GREY)[Clean]$(END_COLOR) $(NAME) and executables have been deleted"

re: fclean all
	@echo "$(PURPLE)[Rebuild]$(END_COLOR) Done."

.PHONY: all clean fclean re