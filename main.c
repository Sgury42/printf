/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:38:46 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/31 17:26:04 by sgury            ###   ########.fr       */
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

    TEST_C(count); ++count;

    ft_printf("{MAGENTA}[ TEST ] --> %%35lld d = (long long)42\n[ TEST ] --> %35lld\n\n{AEOC}", (long long)42);
    printf("[ TEST ] --> %%35lld d = (long long)42\n[ TEST ] --> %35lld\n\n\n", (long long)42);


    TEST_C(count); ++count;

    ft_printf("{ROSE}[ TEST ] --> %s \n{EOC}[ TEST ] --> %-100ld\n\n", "Hello World !", (long)42);
    printf("[ TEST ] --> %s \n[ TEST ] --> %-100ld\n\n\n", "Hello World !", (long)42);


    TEST_C(count); ++count;

    ft_printf("[ TEST ] --> %c \n[ TEST ] --> %d%%\n\n", 'H', 42);
    printf("[ TEST ] --> %c \n[ TEST ] --> %d%%\n\n\n", 'H', 42);


    TEST_C(count); ++count;

    ft_printf("[ TEST ] --> %c \n[ TEST ] --> %+42d\n\n", 'H', 42);
    printf("[ TEST ] --> %c \n[ TEST ] --> %+42d\n\n\n", 'H', 42);


    TEST_C(count); ++count;

    ft_printf("[ TEST ] --> %c \n[ TEST ] --> %-42d\n\n", 'H', 42);
    printf("[ TEST ] --> %c \n[ TEST ] --> %-42d\n\n\n", 'H', 42);

    TEST_C(count); ++count;

    ft_printf("[ TEST ] --> %c \n[ TEST ] --> %hhoendofline\n\n", 'H', (long)123123123);
    printf("[ TEST ] --> %c \n[ TEST ] --> %hhoendofline\n\n\n", 'H', (long)123123123);

    TEST_C(count); ++count;

	ft_printf("[ TEST ] --> %c \n[ TEST ] --> %030ld\n\n", 'H', (long)4748364);
    printf("[ TEST ] --> %c \n[ TEST ] --> %030ld\n\n\n", 'H', (long)4748364);

    TEST_C(count); ++count;

	ft_printf("[ TEST ] --> %c \n[ TEST ] --> %%tralala\n\n", 'H');
    printf("[ TEST ] --> %c \n[ TEST ] --> %%tralala\n\n\n", 'H');

 	TEST_C(count); ++count;

	ft_printf("[ TEST ] --> %c \n[ TEST ] --> %x\n\n", 'H', 1234);
    printf("[ TEST ] --> %c \n[ TEST ] --> %x\n\n\n", 'H', 1234);

	 TEST_C(count); ++count;

	ft_printf("[ TEST ] --> %c \n[ TEST ] --> %X\n\n", 'H', 155);
    printf("[ TEST ] --> %c \n[ TEST ] --> %X\n\n\n", 'H', 155);

 	TEST_C(count); ++count;

	ft_printf("[ TEST ] --> %c \n[ TEST ] --> %f\n\n", 'H', (float)12.34);
    printf("[ TEST ] --> %c \n[ TEST ] --> %f\n\n\n", 'H', (float)12.34);

	TEST_C(count); ++count;

	ft_printf("[ TEST ] --> %c \n[ TEST ] --> %.0Lf\n\n", 'H', (long double)155555.123456789);
    printf("[ TEST ] --> %c \n[ TEST ] --> %.0Lf\n\n\n", 'H', (long double)155555.123456789);

	TEST_C(count); ++count;

	ft_printf("[ TEST ] --> %c \n[ TEST ] --> %20.12lf\n\n", 'H', (double)155.123456789);
    printf("[ TEST ] --> %c \n[ TEST ] --> %20.12lf\n\n\n", 'H', (double)155.123456789);

	printf("end of test\n");
 
    return (0);
}
