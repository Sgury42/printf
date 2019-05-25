/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:38:46 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/25 15:33:54 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

#define NC "\033[0m"
#define RED "\033[0;31m"
#define BLUE "\033[1;34m"
#define GREEN "\033[0;32m"
#define YEL "\033[1;33m"
#define TEST_C(x) printf(x % 2 ? BLUE"TEST NUMBER:"RED" %d"NC"\n\n" : YEL"TEST NUMBER:"RED" %d"NC"\n\n", x)

int     main(void)
{
    int count = 1;
    int *a;
    int b = 42;

    a = &b;
    TEST_C(count); ++count;

    ft_printf("[ TEST ] --> %s \n[ TEST ] --> %35lld\n\n", "Hello World !", (long long)42);
    printf("[ TEST ] --> %s \n[ TEST ] --> %35lld\n\n\n", "Hello World !", (long long)42);


    TEST_C(count); ++count;

    ft_printf("[ TEST ] --> %s \n[ TEST ] --> %-100ld\n\n", "Hello World !", (long)42);
    printf("[ TEST ] --> %s \n[ TEST ] --> %-100ld\n\n\n", "Hello World !", (long)42);


    TEST_C(count); ++count;

    ft_printf("[ TEST ] --> %s \n[ TEST ] --> %04ld\n\n", "Hello World !", (long)42);
    printf("[ TEST ] --> %s \n[ TEST ] --> %04ld\n\n\n", "Hello World !", (long)42);


    TEST_C(count); ++count;

    ft_printf("[ TEST ] --> %c \n[ TEST ] --> %d\n\n", 'H', 42);
    printf("[ TEST ] --> %c \n[ TEST ] --> %d\n\n\n", 'H', 42);


    /*TEST_C(count); ++count;*/

    /*ft_printf("[ TEST ] --> %0c \n[ TEST ] --> %d\n\n", 'H', 42);*/


    TEST_C(count); ++count;

    ft_printf("[ TEST ] --> %c \n[ TEST ] --> %+42d\n\n", 'H', 42);
    printf("[ TEST ] --> %c \n[ TEST ] --> %+42d\n\n\n", 'H', 42);


    TEST_C(count); ++count;

    ft_printf("[ TEST ] --> %c \n[ TEST ] --> %-42d\n\n", 'H', 42);
    printf("[ TEST ] --> %c \n[ TEST ] --> %-42d\n\n\n", 'H', 42);
    
    
    TEST_C(count); ++count;

    ft_printf("[ TEST ] --> %c \n[ TEST ] --> %x\n\n", 'H', 15);
    printf("[ TEST ] --> %c \n[ TEST ] --> %x\n\n\n", 'H', 15);

    TEST_C(count); ++count;

    ft_printf("[ NOT WORKING ] --> %X\n\n", 15);
    printf("[ TEST ] --> %X\n\n\n", 15);


    TEST_C(count); ++count;

    ft_printf("[ TEST ] --> %o\n\n", 15);
    printf("[ TEST ] --> %o\n\n\n", 15);


    TEST_C(count); ++count;

    ft_printf("\n[ TEST ] --> %p\n\n", a);
    printf("[ TEST ] --> %p\n\n\n", a);
    return (0);
}
