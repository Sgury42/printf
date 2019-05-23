# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/23 12:59:31 by flbeaumo          #+#    #+#              #
#    Updated: 2019/05/23 13:01:55 by flbeaumo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf 

SRCS =	ft_printf.c \
	ft_dispatcher.c \
	ft_itoa_base.c \
	ft_convert_base.c \
	ft_parse.c \
	pf_d.c \
	pf_p.c \
	pf_s.c \
	pf_c.c \

OBJ = $(SRCS:.c=.o)

LIB_C_PATH = ./libft/

LIBFT = libft/libft.a 

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address -fno-omit-frame-pointer

NC = 	 \033[0m
RED =	 \033[0;31m
BLUE =	 \033[1;34m
GREEN =  \033[0;32m
YELLOW = \033[1;33m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(SRCS) $(LIBFT) -o $@ $(CFLAGS)
	@clear
	@echo "\033[2A $(GREEN) [ Compile status ]		 [OK] $(NC)"

%.o: %.c $(LIBFT)
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo "\033[1A $(YELLOW)Compiling:$(BLUE) $< \033[K 	$(GREEN) [OK] $(NC)"

$(LIBFT):
	@make -C ./libft/

debug: $(OBJ)
	@$(CC) $(SRCS) -fsanitize=address -fno-omit-frame-pointer \
	$(LIBFT) -o $@ $(CFLAGS)
	@clear
	@echo "\033[2A $(GREEN) [ Compile status ]		 [OK] $(NC)"
	@./printf

leak: $(OBJ)
	@$(CC) $(SRCS) $(LIBFT) -o $@ $(CFLAGS)
	@clear
	@echo "\033[2A $(GREEN) [ Compile status ]		 [OK] $(NC)"
	@valgrind --leak-check=yes ./printf

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
