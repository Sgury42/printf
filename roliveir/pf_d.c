/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 11:28:16 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/08 21:44:51 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*min_ll_int(unsigned long long nbr)
{
	char	*s1;
	char	*s2;

	if ((s1 = ft_utoa(nbr)) == NULL)
		return (NULL);
	s2 = ft_strjoin("-", s1);
	ft_strdel(&s1);
	return (s2);
}

int			pf_d(va_list ap, t_data_tab *data, t_buff *buff)
{
	long long int	nbr;
	char		*str;

	nbr = ft_get_nbr(ap, data);
	if ((unsigned long long)nbr - 1 == 9223372036854775807)
		str = min_ll_int(nbr);
	else
	{
		if ((str = ft_itoa(nbr)) == NULL)
			return (-1);
	}
	if (nbr == 0 && data->flags[precision] == 'z')
		str[0] = ' ';
	if (data->flags[width] <= (int)ft_strlen(str))
		data->flags[width] = 0;
	if (data->flags[precision] != 'z'
			&& data->flags[precision] >= (int)ft_strlen(str))
		ft_precision(str, data, buff);
	else if (data->flags[width])
		ft_width(str, data, buff);
	else
	{
		if (data->flags[sign] && str[0] != '-')
			ft_buffer('+', buff);
		else if (data->flags[space] && str[0] != '-')
			ft_buffer(' ', buff);
		if (data->flags[precision] == 'z' && nbr == 0)
		{
			ft_strdel(&str);
			return (0);
		}
		ft_str_to_buff(str, buff);
	}
	ft_strdel(&str);
	return (0);
}
