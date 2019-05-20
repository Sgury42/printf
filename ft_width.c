/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 09:51:48 by sgury             #+#    #+#             */
/*   Updated: 2019/05/20 15:19:44 by sgury            ###   ########.fr       */
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
		printf("*str = %c\n", *str);
		while (spaces > 0)
		{
			tmp[i++] = ' ';
			spaces--;
		}
		printf("*str = %c\n", *str);
		while (i < width)
		{
			printf("test\n");
			tmp[i] = *str;
			str++;
			i++;
		}
	}
	tmp[i] = '\0';
	ret = tmp;
	free(tmp);
	return (ret);
}
