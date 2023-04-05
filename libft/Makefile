# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadettin <sadettin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 12:54:28 by sfidan            #+#    #+#              #
#    Updated: 2023/03/29 10:39:01 by sadettin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	$(shell ls *.c)
OBJS	=	$(SRCS:.c=.o)
CFLAGS	=	-Werror -Wextra -Wall
NAME	=	libft.a

RED		=	\033[1;31m
GREEN	=	\033[1;32m
YELLOW	=	\033[1;33m
CYAN	=	\033[1;36m
END		=	\033[0m

all: $(OBJS) $(NAME)

$(NAME): $(SRCS)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c
	@printf "$(GREEN)█ "
	@gcc -c $(CFLAGS) $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "$(RED)libft clean$(END)"

fclean:
	rm -f $(NAME)

.PHONY: all clean
