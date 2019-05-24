/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:44:35 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/24 15:35:44 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include "stdlib.h"
#include <stdio.h>


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
    return (nb >= 0 && nb <= 9 ? nb + '0' : nb - 10 + 'A');
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

char            *ft_itoa_base(long int nb, int base)
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

int     main(int ac, char **av)
{
    if (ac != 3)
    {
        printf("ERROR -> usage ./[a.out] [NUMBER] [BASE]\n");
        return (0);
    }
    printf("\033[1m\033[34mNumber:\033[0m %s \033[1m\033[35m Base: \033[0m%s\
            \n\033[1m\033[32mResult: \033[0m%s\n", av[1], av[2],
            ft_itoa_base(atoi(av[1]), atoi(av[2])));
    return (0);
}
