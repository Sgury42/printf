/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:44:35 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/30 13:30:25 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char     *reverse(char *str, int neg)
{
    char    tmp;
    int     i;
    int     j;

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

static char val(int nb)
{
    return (nb >= 0 && nb <= 9 ? nb + '0' : nb - 10 + 'A');
}

static char     *free_str(char *str, int neg)
{
    /*char    *tmp;*/

    /*tmp = str;*/
    str = reverse(str, neg);
    /*free(str);*/
    /*str = tmp;*/
    return (str);
}

static int size_after_convert(long long nb, int base, int len)
{
    int     size;

    size = 0;
    while (nb)
    {
        ++size;
        nb /= base;
    }
    return (size);
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
    if (nb < 0)
    {
        neg = 1;
        nb *= -1;
        ++i;
    }
    if ((str = (char *)malloc(sizeof(char) * (size_after_convert(nb, ))) == NULL)
        return (NULL);
    if (neg)
        str[0] = '-';
    while (i < (len + neg))
    {
        str[i] = val(nb % base);
        i++;
        nb /= base;
    }
    str[i] = '\0';
    return (free_str(str, neg));
}


int     main()
{
    int askip = 15;

    printf("%s\n", ft_itoa_base(15, 10));
    return (0);
}
