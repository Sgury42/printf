/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:44:35 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/03 21:16:38 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_after_convert(long long nb, int base)
{
	int len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		++len;
		nb /= base;
	}
	return (len);
}

static char	*get_base(long long nb, char *str, int base, int neg)
{
	int 	len;
	char	*data_base;

	len = size_after_convert(nb, base) - 1;
	data_base = "0123456789abcdef";
	if (neg)
		str[0] = '-';
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (nb > 0)
	{
		str[len--] = data_base[nb % base];
		nb /= base;
	}
	str[len] = '\0';
	return (str);
}

char		*ft_itoa_base(long long nb, int base)
{
	char	*str;
	int		i;
	int		neg;
	int		len;

	i = 0;
	neg = 0;
	len = size_after_convert(nb, base);
	if (nb < 0 && base == 10)
	{
		neg = 1;
		nb *= -1;
		++i;
	}
	else if (nb < 0 && base != 10)
		return (ft_utoa_base(nb, base));
	if ((str = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	return (str = get_base(nb, str, base, neg));
}
