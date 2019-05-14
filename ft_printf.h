/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 09:28:29 by sgury             #+#    #+#             */
/*   Updated: 2019/05/14 17:25:22 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"

# define FLAG_MAX 6
# define NB_CONV 10
# define CONVERSION "sdiouxXfcp"

typedef struct	s_data_tab
{
	char flags[FLAG_MAX];
	char conv;
}				t_data_tab;

void			ft_printf(const char *format, ...);
int				ft_parse(char *str, t_data_tab *data, int index);
//int				ft_dispacher(va_list ap, t_data_tab *data);


#endif
