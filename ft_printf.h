/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 09:28:29 by sgury             #+#    #+#             */
/*   Updated: 2019/05/21 18:14:59 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>                   //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
# include <stdlib.h>
# include "./libft/libft.h"
# include <stdarg.h>

# define FLAGS_NB 8
# define NB_CONV 10
# define CONVERSION "sdiouxXfcp"
# define BUFF_SIZE 4096
# define NB_FUNC 1

#define FLAGS "-+ 0#Lhl"

typedef struct		s_buff
{
	char		buffer[BUFF_SIZE];
	int		len;
}			t_buff;

typedef enum 		e_data
{
	just_left,
	sign_plus,
	spaces,
	zero,
	hashtag,
	L,
	h,
	l,
	hh,
	ll,
	width,
	precision
}			t_data;

typedef struct		s_data_tab
{
	//index = fonction, 0 = just_left(-), 1 = sign(+), 2 = space(' '),
	//3 = zero, 4 = hashtag, 5 = L, 6 = h, 7 = l, 8 = hh, 9 = ll,
	//10 = width, 11 = precision
	int		flags[12];
	char		conv;
}			t_data_tab;

void			ft_printf(const char *format, ...);
int			ft_parse(const char *str, t_data_tab *data, int index, t_buff *buff);
int			ft_buffer(char c, t_buff *buff);
void			ft_str_to_buff(char *str, t_buff *buff);
int			pf_c(va_list ap, t_data_tab *data, t_buff *buff);
char			*ft_width(char *str, int width, int just_left);
void			ft_usage();
int			ft_dispatcher(va_list ap, t_data_tab *data, t_buff *buff);

#endif
