/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 09:28:29 by sgury             #+#    #+#             */
/*   Updated: 2019/06/03 05:41:22 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>                   //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
# include <stdlib.h>
# include <stdarg.h>
# include "./lib_utils/lib_utils.h"

# define FLAGS_NB 9
# define NB_CONV 12
# define CONVERSION "sdiouxXfcp"
# define BUFF_SIZE 4096
# define NB_FUNC 12
#define FLAGS "-+ 0#Lhl"

typedef enum 	e_flags
{
	just_left,
	sign,
	space,
	zero,
	hashtag,
	L,
	h,
	l,
	hh,
	ll,
	width,
	precision
}		t_flags;

typedef struct	s_buff
{
	char	buffer[BUFF_SIZE];
	int		len;
	int		ret;
}		t_buff;

typedef struct	s_data_tab
{
	//index = fonction, 0 = just_left(-), 1 = sign(+), 2 = space(' '),
	//3 = zero, 4 = hashtag, 5 = L, 6 = h, 7 = l, 8 = hh, 9 = ll,
	//10 = width, 11 = precision
	int	flags[12];
	char	conv;
}		t_data_tab;

void			ft_bzero(void *s, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_isdigit(int c);
int			ft_printf(const char *format, ...);
int			ft_parse(const char *str, t_data_tab *data, int index, t_buff *buff);
void			ft_buffer(char c, t_buff *buff);
void			ft_str_to_buff(char *str, t_buff *buff);
char			*ft_itoa_base(long long int nb, int base);
int			ft_intlen(long long nb);
void			ft_putstr(char *str);
void			ft_flags_display(int neg, t_data_tab *data, t_buff *buff);
int			pf_c(va_list ap, t_data_tab *data, t_buff *buff);
int			pf_s(va_list ap, t_data_tab *data, t_buff *buff);
int  			pf_p(va_list ap, t_data_tab *data, t_buff *buff);
int			pf_d(va_list ap, t_data_tab *data, t_buff *buff);
int  			pf_i(va_list ap, t_data_tab *data, t_buff *buff);
int			pf_o(va_list ap, t_data_tab *data, t_buff *buff);
int  			pf_u(va_list ap, t_data_tab *data, t_buff *buff);
int  			pf_x(va_list ap, t_data_tab *data, t_buff *buff);
int				pf_upperx(va_list ap, t_data_tab *data, t_buff *buff);
int				pf_percentage(va_list ap, t_data_tab *data, t_buff *buff);
int  			pf_f(va_list ap, t_data_tab *data, t_buff *buff);
int  			pf_b(va_list ap, t_data_tab *data, t_buff *buff);
void			ft_width(char *str, t_data_tab *data, t_buff *buff);
void			ft_usage(char conv);                                          //!!!!!! to delete !!!!!!!!
int			ft_dispatcher(va_list ap, t_data_tab *data, t_buff *buff);
void			ft_check_flags(t_data_tab *data);
char			*ft_get_str(va_list ap, t_data_tab *data);
long long int		ft_get_nbr(va_list ap, t_data_tab *data);
int			ft_get_unbr(va_list ap, t_data_tab *data);
void			ft_size_error(t_data_tab *data);

#endif
