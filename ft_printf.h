/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 09:28:29 by sgury             #+#    #+#             */
/*   Updated: 2019/05/13 09:46:46 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINT_H

#define CONVERSION "sdiouxXfcp"

typedef struct	s_conv_tab
{
	char *conv;
}				t_conv_tab

void			ft_printf(const char *str, ...);
int				ft_parseflags(const char *str);

#endif
