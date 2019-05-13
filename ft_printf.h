/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 09:28:29 by sgury             #+#    #+#             */
/*   Updated: 2019/05/13 21:59:49 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINT_H

#define FLAG_MAX
#define CONVERSION "sdiouxXfcp"

typedef struct	s_data_tab
{
	char flags[FLAG_MAX];
	char conv;
}				t_opt_tab

void			ft_printf(const char *format, ...);
int			ft_parse(char *str, t_data_tab *data);
int			ft_dispacher(va_list ap, t_data_tab *data);


#endif
