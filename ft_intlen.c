/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:22:15 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/03 03:47:19 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_intlen(long long nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		++count;
		nb /= 10;
	}
	return (count);
}
