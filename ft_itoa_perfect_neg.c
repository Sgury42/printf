/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_perfect_neg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 16:53:19 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/22 18:13:37 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define BINARY base == 2
#define DECIMAL base == 10
#define HEXA base == 16

static char val(int nb)
{
    return (nb >= 0 && nb <= 9 ? nb + 48 : nb - 10 + 'A');
}

static void binary(long int nb, char **str, int *i)
{
    *i = 1;
    if (nb < 0)
        *str[0] = '1';
    else
        *str[0] = '0';
}

static void negative(long int nb, int base, char **str, int *i)
{
    if (nb < 0)
    {
        if (DECIMAL)
        {
            *str[0] = '-';
            ++(*i);
        }
        nb *= -1;
    }
}

static char    *ft_strrev_neg(char *str, int *neg)
{
    int     tmp;
    int     len;
    int     beg;

    if (neg)
        beg = 1;
    else
        beg = 0;
    len = ft_strlen(str);

    while (beg < --len)
    {
        tmp = str[beg];
        str[beg++] = str[len];
        str[len] = tmp;
    }
    return (str);
}

char    *ft_itoa_base(long int nb, int base)
{
    char    *result;
    int     len;
    int     neg;
    int     i;

    len = ft_intlen(nb);                                                // MA LIB !!! HERE
    neg = 0;
    i = 0;
    if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
    {
        free(result);
        return (NULL);
    }
    if (BINARY)
        binary(nb, &result, &i);
    negative(nb, base, &result, &i);
    while (nb)
    {
        result[i++] += val(nb % base);
        nb /= base;
    }
    return (ft_strrev_neg(result, &neg));
}

#include <stdio.h>

int     main(int ac, char **av)
{
    printf("NB=%d\tBASE=%d\nRESULT= %s\n", atoi(av[1]), atoi(av[2]), ft_itoa_base(atoi(av[1]), atoi(av[2])));
    return (0);
}
