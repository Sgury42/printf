/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 08:35:31 by sgury             #+#    #+#             */
/*   Updated: 2019/05/20 14:42:52 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_c(va_list ap, t_data_tab *data)
{
	char	*str;
	char	*tmp;
	int		c;
	int		i;
	int		just_left;

	i = 0;
	just_left = 0;
	if ((tmp = (char *)malloc(sizeof(char) * 2)) == NULL)
		exit (2);
	while (++i < 10)
		if (data->flags[i] || data->flags[11])
			ft_usage();
	c = va_arg(ap, int);
	tmp[0] = c;
	tmp[1] = '\0';
	str = tmp;
	free(tmp);
	if (data->flags[10])
	{
		if (data->flags[0])
			just_left = 1;
		str = ft_width(str, data->flags[10], just_left);
	}
	return (str);
}
