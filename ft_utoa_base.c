/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 02:58:40 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/06 00:50:54 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_after_convert(unsigned long long nb, int base)
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

char	*ft_utoa_base(unsigned long long nb, int base)
{
	char	*str;
	int	len;
	char	*data_base;

	data_base = "0123456789abcdef";
	len = size_after_convert(nb, base);
	printf("LEN UTOA: %d\n", len);
	if (!(str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	str[len--] = '\0';
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[len--] = data_base[nb % base];
		printf("STATE OF STR --> %c\n", str[len]);
		nb /= base;
	}
	printf("INSIDE FUNC 2: %s\n", str);
	return (str);
}
