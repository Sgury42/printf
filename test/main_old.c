/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:38:46 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/30 11:26:29 by flbeaumo         ###   ########.fr       */
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
#define GOOD BLUE
#define FAIL RED

int     main(void)
{
    int count = 1;

    TEST_C(count); ++count;

    ft_printf("[ TEST ] --> %s \n[ TEST ] --> %35lld\n\n", "Hello World !", (long long)42);
    /*printf("[ TEST ] --> %s \n[ TEST ] --> %35lld\n\n\n", "Hello World !", (long long)42);*/


    TEST_C(count); ++count;

    ft_printf("[ TEST ] --> %s \n[ TEST ] --> %-100ld\n\n", "Hello World !", (long)42);
    /*printf("[ TEST ] --> %s \n[ TEST ] --> %-100ld\n\n\n", "Hello World !", (long)42);*/


    TEST_C(count); ++count;

    ft_printf("[ TEST ] --> %s \n[ TEST ] --> %04ld\n\n", "Hello World !", (long)42);
    /*printf("[ TEST ] --> %s \n[ TEST ] --> %04ld\n\n\n", "Hello World !", (long)42);*/


    TEST_C(count); ++count;

    ft_printf("[ TEST ] --> %c \n[ TEST ] --> %d\n\n", 'H', 42);
    /*printf("[ TEST ] --> %c \n[ TEST ] --> %d\n\n\n", 'H', 42);*/


    /*TEST_C(count); ++count;*/

    /*ft_printf("[ TEST ] --> %0c \n[ TEST ] --> %d\n\n", 'H', 42);*/


    TEST_C(count); ++count;

    ft_printf("[ TEST ] --> %c \n[ TEST ] --> %+42d\n\n", 'H', 42);
    /*printf("[ TEST ] --> %c \n[ TEST ] --> %+42d\n\n\n", 'H', 42);*/


    TEST_C(count); ++count;

    ft_printf("[ TEST ] --> %c \n[ TEST ] --> %-42d\n\n", 'H', 42);
    /*printf("[ TEST ] --> %c \n[ TEST ] --> %-42d\n\n\n", 'H', 42);*/

    ft_printf(YEL"======= TEST FOR %%c =======\n\n"NC);

    ft_putstr(GOOD"[TEST] - ft_printf(\"This is a test for %c !!\", \'H\')\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %c !!\n\n\n", 'H'); 

    ft_putstr(GOOD"[TEST] ft_printf(\"[FT_PRINTF RESULT] %7c !!\", \'H\')\n");
    ft_printf(GREEN"[TR_PRINTF] %7c !!\n\n\n", 'H'); 

    ft_putstr(GOOD"[TEST] ft_printf(\"[RESULT] %60c !!\", \'H\')\n");
    ft_printf(GREEN"[FT_PRINTF] %60c !!\n\n\n", 'H'); 

    ft_putstr(GOOD"[TEST] ft_printf(\"[RESULT] %-23c !!\", \'H\')\n");
    ft_printf(GREEN"[FT_PRINTF] %-23c !!\n\n\n", 'H'); 




    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %x !!\", 444444)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %x !!\n\n\n", 444444); 

    ft_putstr(FAIL"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %x !!\", 444444)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %#x !!\n\n\n", 444444); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %x !!\", 444444)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %03x !!\n\n\n", 444444); 

    ft_putstr(FAIL"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %x !!\", 444444)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %015x !!\n\n\n", 444444); 

    ft_putstr(FAIL"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %x !!\", 424242)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %0#15x !!\n\n\n", 424242); 

    ft_putstr(FAIL"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %x !!\", 15)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %-15x !!\n\n\n", 15); 

    ft_putstr(FAIL"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %x !!\", 15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %-#15x !!\n\n\n", 1515151515); 




    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %ld !!\", (long)444444)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %ld !!\n\n\n", (long)444444); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %lld !!\", (long long)4444445555555)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %lld !!\n\n\n", (long long)4444445555555); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %hd !!\", (short)4444445555555)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %hd !!\n\n\n", (short)4444445555555); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %hhd !!\", (char)444534))\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %hhd !!\n\n\n", (char)444534); 
    
    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %d !!\", 444444)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %d !!\n\n\n", 444444); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %03d !!\", 444444)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %03d !!\n\n\n", 444444); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %015d !!\", 444444)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %015d !!\n\n\n", 444444); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for % 15d !!\", 424242)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for % 15d !!\n\n\n", 424242); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %-15d !!\", 15)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %-15d !!\n\n\n", 15); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %+015d !!\", 15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %+015d !!\n\n\n", 1515151515); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %+d !!\", 15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %+d !!\n\n\n", 1515151515); 
    
    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %+d !!\", 15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %+d !!\n\n\n", -1515151515); 




    
    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %u !!\", 15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %u !!\n\n\n", 1515151515); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %0u !!\", 15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %0u !!\n\n\n", 1515151515); 

    ft_putstr(FAIL"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %012u !!\", 15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %012u !!\n\n\n", 1515151515); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %-12u !!\", 15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %-12u !!\n\n\n", 1515151515); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %12u !!\", 15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %12u !!\n\n\n", 1515151515); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %12lu !!\", 15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %12lu !!\n\n\n", (unsigned long)1515151515); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %12hu !!\", 15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %12hu !!\n\n\n", (unsigned short)1515151515); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %1hhu !!\", 15)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %1hhu !!\n\n\n", (char)15); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %-4llu !!\", 987654321)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %-4llu !!\n\n\n", (long long)987654321); 



    
    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %o !!\", 15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %o !!\n\n\n", 1515151515); 

    ft_putstr(FAIL"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %020o !!\", 15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %020o !!\n\n\n", 1515151515); 

    ft_putstr(FAIL"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %012o !!\", 15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %012o !!\n\n\n", 1515151515); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %-120o !!\", 15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %-120o !!\n\n\n", 1515151515); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %42o !!\", 15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %42o !!\n\n\n", 1515151515); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %12lo !!\", 1515421515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %12lo !!\n\n\n", (unsigned long)1515421515); 
    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %12ho !!\", 999)\n");

    ft_printf(GREEN"[FT_PRINTF] - This is a test for %12ho !!\n\n\n", (unsigned short)999); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %1hho !!\", 15)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %1hho !!\n\n\n", (char)15); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %-4llo !!\", 987654321)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %-4llo !!\n\n\n", (long long)987654321); 



}


