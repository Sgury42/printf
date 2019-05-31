/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:16:23 by sgury             #+#    #+#             */
/*   Updated: 2019/05/31 17:26:42 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "pf_color.h"

int		ft_get_color(const char *str, int index, t_buff *buff)
{
	char	*tmp;
	int		color_len;
	int		i;
	int		x;

	i = 0;
	x = index + 1;
	color_len = x;
	while (str[color_len] != '\0' && str[color_len] != '}')
		color_len++;
	if ((tmp = ft_strnew(color_len)) == NULL)
		exit (1);
	while (str[x] != '\0' && str[x] != '}')
		tmp[i++] = str[x++];
	tmp[i] = '\0';
	i = 0;
	while (i < NB_COLOR && ft_strcmp(tmp, g_pf_color[i]) != 0)
		i++;
	if (i < NB_COLOR)
	{
		ft_str_to_buff((char *)g_pf_color_define[i], buff);
		ft_strdel(&tmp);
		return (++x);
	}
	else
	{
		ft_buffer(str[index++], buff);
		ft_strdel(&tmp);
		return (index);
	}
}
