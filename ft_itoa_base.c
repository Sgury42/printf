/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:44:35 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/31 10:40:35 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*reverse(char *str, int neg)
{
	char	tmp;
	int		i;
	int		j;

	i = ft_strlen(str);
	j = 0;
	if (neg)
		j = 1;
	--i;
	while (i > j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		--i;
		++j;
	}
	return (str);
}

static char	val(int nb)
{
	return (nb >= 0 && nb <= 9 ? nb + '0' : nb - 10 + 'a');
}

static char	*free_str(char *str, int neg)
{
	str = reverse(str, neg);
	return (str);
}

static int	size_after_convert(long long nb, int base, int neg)
{
	int	size;

	size = 0;
	while (nb)
	{
		if (neg)
		{
			++size;
			neg = 0;
		}
		++size;
		nb /= base;
	}
	return (size);
}

char		*ft_itoa_base(long long nb, int base)
{
	char	*str;
	int		i;
	int		neg;
	int		len;

	i = 0;
	neg = 0;
	len = size_after_convert(nb, base, neg);
	if (nb < 0)
	{
		neg = 1;
		nb *= -1;
		++i;
	}
	if ((str = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	if (neg)
		str[0] = '-';
	while (i < (len + neg))
	{
		str[i++] = val(nb % base);
		nb /= base;
	}
	str[i] = '\0';
	return (free_str(str, neg));
}

/*int     main()*/
/*{*/
    /*printf("%s\n", ft_itoa_base(14, 16));*/
    /*printf("%x\n", 14);*/
    /*return (0);*/
/*}*/
