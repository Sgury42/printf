/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:44:35 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/08 21:33:09 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*static int	size_after_convert(long long nb, int base)*/
/*{*/
	/*int len;*/

	/*len = 0;*/
	/*if (nb == 0)*/
		/*return (1);*/
	/*while (nb > 0)*/
	/*{*/
		/*++len;*/
		/*nb /= base;*/
	/*}*/
	/*return (len);*/
/*}*/

/*static char	*get_base(long long nb, char *str, int base, int neg)*/
/*{*/
	/*int 	len;*/
	/*char	*data_base;*/

	/*len = size_after_convert(nb, base) - 1;*/
	/*str[len] = '\0';*/
	/*data_base = "0123456789abcdef";*/
	/*if (neg)*/
		/*str[0] = '-';*/
	/*while (nb > 0)*/
	/*{*/
		/*str[len--] = data_base[nb % base];*/
		/*nb /= base;*/
	/*}*/
	/*return (str);*/
/*}*/

/*char		*ft_itoa_base(long long nb, int base)*/
/*{*/
	/*char	*str;*/
	/*int	neg;*/
	/*int	len;*/

	/*neg = 0;*/
	/*len = size_after_convert(nb, base);*/
	/*if (nb < 0 && base == 10)*/
	/*{*/
		/*neg = 1;*/
		/*nb *= -1;*/
	/*}*/
	/*else if (nb < 0 && base != 10)*/
		/*return (ft_utoa_base(nb, base));*/
	/*if ((str = (char *)malloc(sizeof(char) * (len + 1))) == NULL)*/
		/*return (NULL);*/
	/*if (nb == 0)*/
	/*{*/
		/*str[0] = '0';*/
		/*return (str);*/
	/*}*/
	/*return (str = get_base(nb, str, base, neg));*/
/*}*/

static char	*b_neg(char *str, int size)
{
	int i;

	i = size;
	while (i)
	{
		printf("VALUE %d --> %c\n", i, str[i]);
		str[i] == '1' ? (str[i] = '0') : (str[i] = '1');
		--i;
	}
		printf("VALUE %d --> %s\n", i, str);
	return (str);
}

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

static int	size_after_convert(long long nb, int base, int neg)
{
	int len;

	len = 0;
	if (nb == 0)
		return (1);
	if (neg)
		++len;		
	while (nb > 0)
	{
		++len;
		nb /= base;
	}
	return (len);
}

char		*ft_itoa_base(long long nb, int base)
{
	char	*str;
	int	i;
	int	neg;
	int	len;

	i = 0;
	neg = 0;
	if (nb < 0)
	{
		neg = 1;
		nb *= -1;
		++i;
	}
	len = size_after_convert(nb, base, neg);
	if ((str = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	if (neg && base == 10)
		str[0] = '-';
	while (i < (len + neg))
	{
		str[i++] = val(nb % base);
		nb /= base;
	}
	if (neg)
		return (b_neg(str, len));
	str[i] = '\0';
	return (str = reverse(str, neg));
}
