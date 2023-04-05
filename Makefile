MAKEFLAGS	+=	--no-print-directory

SRCS		=	utils.c
OBJS		=	$(SRCS:.c=.o)
NAME		=	libft/libft.a
CFLAGS		=	-Werror -Wextra -Wall

RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
BLUE		=	\033[1;34m
CYAN		=	\033[1;36m
WHITE		=	\033[1;37m
END			=	\033[0m

all: $(NAME) env

$(NAME):
	@echo
	@echo "$(WHITE)===> Compiling $(BLUE)libft$(END)\n"
	@make -C libft
	@echo "$(CYAN) libft is done$(END)"

env: env.c
	@gcc $(CFLAGS) env.c utils.c $(NAME) $(NAME2) -o env

clean:
	@make -C libft clean
	@echo "$(RED)env clean$(END)"

fclean: clean
	@rm -f $(NAME) env
	@echo "$(RED)all clean$(END)"

re: fclean all

.PHONY: all bonus clean fclean re re_bonus
