# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/23 12:59:31 by flbeaumo          #+#    #+#              #
#    Updated: 2019/05/31 15:01:44 by flbeaumo         ###   ########.fr        #
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
	ft_width.c \
	ft_intlen.c \
	ft_get_str.c \
	ft_get_nbr.c \
	ft_get_unbr.c \
	ft_flags_display.c \
	ft_usage.c \
	ft_itoa_base.c \
	pf_c.c \
	pf_s.c \
	pf_p.c \
	pf_d.c \
	pf_o.c \
	pf_u.c \
	pf_x.c \
	pf_i.c \
	pf_f.c \
	pf_b.c \
	./lib_utils/ft_atoi.c \
	./lib_utils/ft_itoa.c \
	./lib_utils/ft_bzero.c \
	./lib_utils/ft_isdigit.c \
	./lib_utils/ft_memset.c \
	./lib_utils/ft_putstr.c \
	./lib_utils/ft_strcmp.c \
	./lib_utils/ft_strdel.c \
	./lib_utils/ft_strdup.c \
	./lib_utils/ft_strlen.c \
	./lib_utils/ft_memdel.c \
	./lib_utils/ft_strnew.c \
	./lib_utils/ft_strrev.c \
	./lib_utils/ft_memalloc.c \
	./lib_utils/ft_putstr_fd.c \
	./lib_utils/ft_putchar_fd.c


OBJ = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CFLAGS_L = -fsanitize=address -fno-omit-frame-pointer 

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
	@gcc $(CFLAGS) main.c $(NAME)
	@./a.out

debug:
	@gcc $(CFLAGS) $(CFLAGS_L) main.c $(NAME)
	@./a.out

leak:
	@gcc $(CFLAGS) main.c $(NAME)
	@valgrind --leak-check=full ./a.out

norm:
	norminette $(SRCS_PATH) $(HEADER_PATH) $(LIB_C_PATH)

clean:
	@rm -rf $(OBJ)
	@echo "$(RED) Remove Object:$(NC)			$(GREEN) [OK] $(NC)" $<

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED) Remove Binary:$(NC)			$(GREEN) [OK] $(NC)"

re: fclean all
