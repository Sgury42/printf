/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 12:03:20 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/26 12:28:17 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     detect_base(long long nb)
{
    char    *str;

    if (!(str = ft_itoa(nb)))
        return (-1);
    if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
        return (16);
    else if (str[0] == '0')
        return (8);
    return (10);
}

int main()
{
    int nbr = 0x34;
    int nbr2 = 042;
    int nbr3 = 42;

    printf("%i\n", nbr);
    printf("%i\n", nbr2);
    printf("%i\n\n", nbr3);

    ft_putnbr(nbr);

    ft_printf("\n%d\n", nbr);
    ft_printf("%d\n", nbr2);
    ft_printf("%d\n", nbr3);
    return (0);
}
