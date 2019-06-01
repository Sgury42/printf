/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:29:00 by sgury             #+#    #+#             */
/*   Updated: 2019/05/30 14:05:56 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			float_len(long double nbr)
{
	int	len;

	len = 0;
	while (nbr > 1)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

static void			str_bfr_coma(long double nbr, char *str,
									int neg, int nbrlen)
{
	int	i;

	i = nbrlen - 1 + neg;
	while (nbr > 1)
	{
		str[i--] = (int)nbr % 10 + '0';
		nbr /= 10;
	}
	if (neg)
		str[i] = '-';
}

static char			*get_floatstr(long double nbr, int prec)
{
	char	*str;
	int		i;
	int		neg;
	int		nbrlen;

	neg = 0;
	if (nbr < 0)
	{
		neg = 1;
		nbr *= -1;
	}
	nbrlen = float_len(nbr);
	if ((str = ft_strnew(nbrlen + prec + neg + 1)) == NULL)
		return (NULL);
	str_bfr_coma(nbr, str, neg, nbrlen);
	i = nbrlen + neg;
	if (prec)
		str[i++] = '.';
	while (prec > 0)
	{
		nbr *= 10;
		str[i++] = (int)nbr % 10 + '0';
		prec--;
	}
	str[i] = '\0';
	return (str);
}

static int			check_prec(t_data_tab *data)
{
	int	prec;

	prec = data->flags[precision];
	if (prec == 0)
		prec = 6;
	if (prec == 'z')
		prec = 0;
	return (prec);
}

int					pf_f(va_list ap, t_data_tab *data, t_buff *buff)
{
	long double	nbr;
	char		*str;
	int			prec;
	int			neg;

	neg = 0;
	if (data->flags[L])
		nbr = va_arg(ap, long double);
	else
		nbr = (double)va_arg(ap, double);
	if (nbr < 0)
		neg = 1;
	prec = check_prec(data);
	if ((str = get_floatstr(nbr, prec)) == NULL)
		return (-1);
	ft_flags_display(neg, data, buff);
	if (data->flags[width] && (data->flags[width] > (int)ft_strlen(str)))
		ft_width(str + neg, data, buff);
	else
	{
		if (data->flags[sign] && neg == 0)
			ft_buffer('+', buff);
		ft_str_to_buff(str, buff);
	}
	ft_strdel(&str);
	return (0);
}
