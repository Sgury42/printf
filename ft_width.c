/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 09:51:48 by sgury             #+#    #+#             */
/*   Updated: 2019/05/20 10:39:21 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_width(char *str, int width, int just_left)
{
	int		spaces;
	char	*ret;
	int		i;

	spaces = width - ft_strlen(str);
	i = 0;
	ret = NULL;
	if (spaces <= 0)
		return (str);
	if (just_left)
	{
		while (*str)
			ret[i++] = *str++;
		while (spaces > 0)
		{
			ret[i++] = ' ';
			spaces--;
		}
	}
	else
	{
		while (spaces > 0)
		{
			ret[i++] = ' ';
			spaces--;
		}
		while (*str)
			ret[i++] = *str++;
	}
	return (ret);
}
