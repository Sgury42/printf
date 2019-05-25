/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:44:35 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/25 14:47:21 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char     *reverse(char *str, int neg)
{
    char    tmp;
    int     i;
    int     j;

    i = ft_strlen(str);
    if (neg)
        j = 1;
    else
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

static char val(int nb)
{
    return (nb >= 0 && nb <= 9 ? nb + '0' : nb - 10 + 'a');
}

static char     *free_str(char *str, int neg)
{
    char    *tmp;

    tmp = str;
    if ((tmp = reverse(str, neg)) == NULL)
        return (NULL);
    free(str);
    str = tmp;
    return (str);
}

char            *ft_itoa_base(long long nb, int base)
{
    char            *str;
    int             i;
    int             neg;
    int             len;

    i = 0;
    neg = 0;
    len = ft_intlen(nb);
    if ((str = (char *)malloc(sizeof(char) * len)) == NULL)
        return (NULL);
    if (nb < 0)
    {
        neg = 1;
        nb *= -1;
        str[0] = '-';
        ++i;
    }
    while (nb)
    {
        str[i++] = val(nb % base);
        nb /= base;
    }
    str[i] = '\0';
    return (free_str(str, neg));
}
