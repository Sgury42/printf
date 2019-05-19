/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 09:28:29 by sgury             #+#    #+#             */
/*   Updated: 2019/05/19 14:51:51 by sgury            ###   ########.fr       */
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

typedef struct	s_buff
{
	char	buffer[BUFF_SIZE];
	int		len;
}				t_buff;

typedef struct	s_data_tab
{
	int		just_left;			// - : justify on left side
	int		sign;				// + : + sign if positive int
	int		space;				// ' ' : single space before positive int
	int		zero;				// 0 : replace spaces with 0
	int		hashtag;			// #
	int		hh;					
	int		h;
	int		ll;
	int		l;
	int		L;
	int		width;
	int		precision;
	char	conv;
}				t_data_tab;

void			ft_printf(const char *format, ...);
int				ft_parse(char *str, t_data_tab *data, int index, t_buff *buff);
int				ft_dispacher(va_list ap, t_data_tab *data);
int				ft_buffer(char c, t_buff *buff);
void			ft_str_to_buff(char *str, t_buff *buff);

#endif
