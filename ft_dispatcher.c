/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 21:03:20 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/13 21:59:41 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*ft_dispacher(va_list ap, t_data_tab *data)*/
/*{*/

/*}*/
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int     ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        ++i;
    return (i);
}

int     ft_putstr(char *s)
{
    while (*s)
        write(1, s, ft_strlen(s));
    return (1);
}

int     ft_test(char *name, char *s)
{
    int i;

    i = 0;
    static char *func_lst[2] = {
        "ft_strlen", "ft_putstr"};

    while (i < 2)
    {
        if (!strcmp(name, func_lst[i]))
            break ;
        i++;
    }
    static int  (*fct_list[2])(char*) = {
        ft_strlen, ft_putstr};
    if (i < 2 && i > 0)
        return (*(fct_list[i]))(s);
    else
        return (0);
    return (0);
}

int     main()
{
    char *s = "test";

    ft_test("ft_putstr", s);
    write(1, "\n", 1);
    printf("%d\n", ft_test("ft_strlen", s));
    return (0);
}
