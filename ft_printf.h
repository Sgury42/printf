/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 09:28:29 by sgury             #+#    #+#             */
/*   Updated: 2019/05/17 14:09:24 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

# define FLAG_MAX 6
# define NB_CONV 10
# define CONVERSION "sdiouxXfcp"
# define NB_FUNC 3

typedef struct	s_data_tab
{
	char 	flags[FLAG_MAX];
	char 	conv[1];
}		t_data_tab;

void		ft_printf(const char *format, ...);
int		ft_parse(char *str, t_data_tab *data, int index);


char		*ft_dispacher(va_list ap, t_data_tab *data);
char		*pf_s(va_list ap, t_data_tab *datas);
char		*pf_d(va_list ap, t_data_tab *datas);
char		*pf_c(va_list ap, t_data_tab *datas);

#endif
