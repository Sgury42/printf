/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 21:03:20 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/14 17:41:35 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "ft_printf.h"

ft_dispacher(va_list ap, t_data_tab *data)
{
    int     i;

    i = 0;
    static char *fct_name[NB_FUNC] = {"c", "s", "d"};
    while (i < NB_FUNC)
    {
        if (!ft_strcmp(data->conv, fct_name[i]))
            break ;
        i++;
    }
    static int  (*fct_list[NB_FUNC])(va_list, t_data_tab *) = {pf_c, pf_s, pf_d};
    if (i >= 0 && i < NB_FUNC)
        return (*(fct_list[i]))(ap, data);
    return (-1);

}

/*int     ft_strlen(char *s)*/
/*{*/
    /*int i;*/

    /*i = 0;*/
    /*while (s[i])*/
        /*++i;*/
    /*return (i);*/
/*}*/

/*int     ft_putstr(char *s)*/
/*{*/
    /*write(1, s, ft_strlen(s));*/
    /*return (1);*/
/*}*/

/*int     ft_test(char *name, char *s)*/
/*{*/
    /*int i;*/

    /*i = 0;*/
    /*static char *func_lst[2] = {"ft_strlen", "ft_putstr"};*/
    /*while (i < 2)*/
    /*{*/
        /*if (!strcmp(name, func_lst[i]))*/
            /*break ;*/
        /*i++;*/
    /*}*/
    /*static int  (*fct_list[2])(char*) = {ft_strlen, ft_putstr};*/
    /*if (i >= 0 && i < 2)*/
        /*return (*(fct_list[i]))(s);*/
    /*return (0);*/
/*}*/

int     main()
{
    char *s = "test";

    printf("%d\n", ft_test("ft_strlen", s));
    ft_test("ft_putstr", s);
    write(1, "\n", 1);
    return (0);
}
