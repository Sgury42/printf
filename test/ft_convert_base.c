/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:32:14 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/22 14:34:11 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

static int      is_spaces(char c)
{
    return ((c >= 9 && c <= 13) || c == 32);
}

static int      val_check(char c)
{
    if (c >= '0' && c <= '9')
        return ((int)c - '0');
    else
        return ((int)c - 'A' + 10);
}

int     ft_convert_base(char *str, int base)
{
    int len;
    int result;
    int power;
    int i;

    len = ft_strlen(str);
    result = 0;
    power = 1;
    i = len;
    while (--i >= 0)
    {
        if (val_check(str[i]) >= base)
            return (-1);    // Base or Number are invalid
        printf(YELLOW"STR = %c --> "MAGENTA" true val: %d\n"RESET, str[i], val_check(str[i]));
        printf(BLUE"Power = %d\n"RESET, power);
        result += val_check(str[i]) * power;
        power *= base;
    }
    return (result);
}


#include <stdlib.h>

int     main(int ac, char **av)
{
    if (ac != 3)
    {
        printf("[ERROR]: USAGE -> [./a.out] [NUMBER]");
        return (0);
    }
    printf(GREEN"\nRESULT IN BASE 10: "RED" --> %d <--\n"RESET, ft_convert_base(av[1], atoi(av[2])));
    /*printf("Value: %c\nBase: %d\nResult in base: 10 -> %d\n", 'F', 16, val_check('F'));*/
    return (0);
}
