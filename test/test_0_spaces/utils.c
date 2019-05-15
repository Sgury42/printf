/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:15:28 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/15 14:51:41 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_zero(char *str, int size)
{
    int len;

    len = (size - ft_strlen(str));
    ft_putstr(str);
    if (len < 0)
        return (0);
    while (len)
    {
        ft_putchar('0');
        --len;
    }
    return (1);
}

int ft_print_spaces(char *str,int size)
{
    int len;

    len = (size - ft_strlen(str));
    ft_putstr(str);
    if (len < 0)
        return (0);
    while (len)
    {
        ft_putchar(' ');
        --len;
    }
    return (1);
}

#include <unistd.h>
int     main()
{
    char test[255] = "Hello World!";

    ft_print_zero(test, 17);
    write(1, "\n", 1);
    ft_print_spaces(test, 17);
    return (0);
}
