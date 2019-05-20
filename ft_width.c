/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 09:51:48 by sgury             #+#    #+#             */
/*   Updated: 2019/05/20 14:01:21 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_width(char *str, int width, int just_left)
{
	char	*ret;
	char	*tmp;
	int		spaces;
	int		i;

	spaces = width - ft_strlen(str);
	i = 0;
	if (spaces <= 0)
		return (str);
	if ((tmp = (char *)malloc(sizeof(char) * (width + 1))) == NULL)
		exit (2);
	if (just_left)
	{
		while (*str)
			tmp[i++] = *str++;
		while (spaces > 0)
		{
			tmp[i++] = ' ';
			spaces--;
		}
	}
	else
	{
		while (spaces > 0)
		{
			tmp[i++] = ' ';
			spaces--;
		}
		while (*str)
			tmp[i++] = *str++;
	}
	tmp[i] = '\0';
	ret = tmp;
	free(tmp);
	return (ret);
}
