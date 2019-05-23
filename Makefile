# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/23 12:59:31 by flbeaumo          #+#    #+#              #
#    Updated: 2019/05/23 15:27:09 by flbeaumo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a 

SRCS =	ft_buffer.c \
	ft_check_flags.c \
	ft_dispatcher.c \
	ft_get_str.c \
	ft_parse.c \
	ft_printf.c \
	ft_str_to_buff.c \
	ft_usage.c \
	ft_width.c \
	pf_c.c \
	pf_d.c \
	pf_s.c \
	./libft/ft_atoi.c \
	./libft/ft_bzero.c \
	./libft/ft_isdigit.c \
	./libft/ft_itoa.c \
	./libft/ft_memset.c \
	./libft/ft_putstr.c \
	./libft/ft_strcmp.c \
	./libft/ft_strdel.c \
	./libft/ft_strdup.c \
	./libft/ft_strlen.c \
	./libft/ft_memdel.c \
	./libft/ft_strnew.c \
	./libft/ft_strrev.c \
	./libft/ft_memalloc.c \


OBJ = $(SRCS:.c=.o)

LIB = ./libft/

LIBFT = libft/libft.a 

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

NC = 	 \033[0m
RED =	 \033[0;31m
BLUE =	 \033[1;34m
GREEN =  \033[0;32m
YELLOW = \033[1;33m

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $^
	@ranlib $(NAME)
	@clear
	@echo "\033[2A $(GREEN) [ Compile status ]		 [OK] $(NC)"

%.o: %.c 
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo "\033[1A $(YELLOW)Compiling:$(BLUE) $< \033[K 	$(GREEN) [OK] $(NC)"

test:
	@gcc -Wall -Wextra -Werror main.c ft_printf.a
	@./a.out


norm:
	norminette $(SRCS_PATH) $(HEADER_PATH) $(LIB_C_PATH)

clean:
	@rm -rf $(OBJ)
	@make clean -C ./libft/
	@echo "$(RED) Remove Object:$(NC)			$(GREEN) [OK] $(NC)" $<

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C ./libft/ 
	@echo "$(RED) Remove Binary:$(NC)			$(GREEN) [OK] $(NC)"

re: fclean all
