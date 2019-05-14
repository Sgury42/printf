/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:28:33 by sgury             #+#    #+#             */
/*   Updated: 2019/05/14 17:17:31 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_data(char *str, t_data_tab *data)
{
	char	conv[NB_CONV] = "sdiouxXfcp";
	int		i;
	int		j;
	int		ret;

	i = 0;
	j = 0;
	ret = 1;
	str++;
	if (*str == '%')
	{
		ft_putchar('%');
		return (2);
	}
	while (*str != conv[i] && ret <= FLAG_MAX)
	{
		while (i < NB_CONV && *str != conv[i])
			i++;
		if (i == NB_CONV && *str != conv[i])
		{
			data->flags[j++] = *str;
			i = 0;
			str++;
		}
		ret++;
	}
	if (ret > FLAG_MAX)
		return (-1);
	data->conv = *str;
	return (ret);
}

int		ft_parse(char *str, t_data_tab *data, int i)
{
	int	ret;

	ret = 0;
	while (str[i] != '\0' && str[i] != '%')
		ft_putchar(str[i++]);
	if (str[i] == '%')
	{
		if ((ret = ft_get_data(str + i, data)))
			return (ret + i);
	}
	return (0);
}
