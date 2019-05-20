/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:44:35 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/20 13:12:15 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include "stdlib.h"

static int  ft_count(int nb)
{
    int count;

    count = 0;
    while (nb)
    {
        ++count;
        nb /= 10;
    }
    return (count);
}

static char *reverse(char *str)
{
    char    tmp;
    int     i;
    int     j;

    i = ft_strlen(str);
    j = 0;
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

static char *free_str(char *str)
{
    char    *tmp;

    tmp = str;
    if ((tmp = reverse(str)) == NULL)
        return (NULL);
    free(str);
    str = tmp;
    return (str);
}

char        *ft_itoa_base(long int nb, int base)
{
    static char     hexa[6] = "ABCDEF";
    static char     replace[6] = ":;<=>?";
    char            *str;
    int             i;
    int             j;

    i = 0;
    if ((str = (char *)malloc(sizeof(char) * ft_count(nb))) == NULL)
        return (NULL);
    while (nb)
    {
        j = -1;
        str[i] = nb % base + '0';
        nb /= base;
        while (str[i] >= '9' && ++j < 6)
        {
            if (str[i] == replace[j])
            {
                str[i] = hexa[j];
                break ;
            }
        }
        ++i;
    }
    return (free_str(str));
}
