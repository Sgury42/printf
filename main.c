/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:38:46 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/01 18:20:31 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

#define NC "\033[0m"
#define RED "\033[0;31m"
#define BLUE "\033[1;34m"
#define GREEN "\033[0;32m"
#define YEL "\033[1;33m"
#define GOOD BLUE
#define FAIL RED

static int     test_c()
{
    ft_printf(YEL"======= TEST FOR %%c =======\n\n"NC);

    ft_putstr(GOOD"[TEST] - ft_printf(\"This is a test for %c !!\", \'H\')\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %c !!\n\n\n", 'H'); 
    printf(GREEN"[TR_PRINTF] - This is a test for %c !!\n\n\n", 'H'); 

    ft_putstr(GOOD"[TEST] ft_printf(\"[FT_PRINTF RESULT] %7c !!\", \'H\')\n");
    ft_printf(GREEN"[TR_PRINTF] %7c !!\n\n\n", 'H'); 
    printf(GREEN"[TR_PRINTF] %7c !!\n\n\n", 'H'); 

    ft_putstr(GOOD"[TEST] ft_printf(\"[RESULT] %60c !!\", \'H\')\n");
    ft_printf(GREEN"[FT_PRINTF] %60c !!\n\n\n", 'H'); 
    printf(GREEN"[TR_PRINTF] %60c !!\n\n\n", 'H'); 

    ft_putstr(GOOD"[TEST] ft_printf(\"[RESULT] %-23c !!\", \'H\')\n");
    ft_printf(GREEN"[FT_PRINTF] %-23c !!\n\n\n", 'H'); 
    printf(GREEN"[TR_PRINTF] %-23c !!\n\n\n", 'H'); 

    printf(YEL"\n===========================\n"NC);
    return (1);
}

static int  test_x()
{

    printf(YEL"======= TEST FOR %%x =======\n\n"NC);

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %x !!\", 444444)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %x !!\n\n\n", 444444); 
    printf(GREEN"[TR_PRINTF] - This is a test for %x !!\n\n\n", 444444); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %#x !!\", 444444)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %#x !!\n\n\n", 444444); 
    printf(GREEN"[TR_PRINTF] - This is a test for %#x !!\n\n\n", 444444); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %03x !!\", 444444)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %03x !!\n\n\n", 444444); 
    printf(GREEN"[TR_PRINTF] - This is a test for %03x !!\n\n\n", 444444); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %015x !!\", 444444)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %015x !!\n\n\n", 444444); 
    printf(GREEN"[TR_PRINTF] - This is a test for %015x !!\n\n\n", 444444); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %0#15x !!\", 424242)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %0#15x !!\n\n\n", 424242); 
    printf(GREEN"[TR_PRINTF] - This is a test for %0#15x !!\n\n\n", 424242); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %-15x !!\", 15)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %-15x !!\n\n\n", 15); 
    printf(GREEN"[TR_PRINTF] - This is a test for %-15x !!\n\n\n", 15); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %-#15x !!\", 15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %-#15x !!\n\n\n", 15151515); 
    printf(GREEN"[TR_PRINTF] - This is a test for %-#15x !!\n\n\n", 15151515); 

    printf(YEL"\n===========================\n"NC);
    return (1);
}

static int  test_X()
{

    printf(YEL"======= TEST FOR %%X =======\n\n"NC);

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %X !!\", 444444)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %X !!\n\n\n", 444444); 
    printf(GREEN"[TR_PRINTF] - This is a test for %X !!\n\n\n", 444444); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %#X !!\", 444444)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %#X !!\n\n\n", 444444); 
    printf(GREEN"[TR_PRINTF] - This is a test for %#X !!\n\n\n", 444444); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %03X !!\", 444444)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %03X !!\n\n\n", 444444); 
    printf(GREEN"[TR_PRINTF] - This is a test for %03X !!\n\n\n", 444444); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %015X !!\", 444444)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %015X !!\n\n\n", 444444); 
    printf(GREEN"[TR_PRINTF] - This is a test for %015X !!\n\n\n", 444444); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %0#15X !!\", 424242)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %0#15X !!\n\n\n", 424242); 
    printf(GREEN"[TR_PRINTF] - This is a test for %0#15X !!\n\n\n", 424242); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %-15X !!\", 15)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %-15X !!\n\n\n", 15); 
    printf(GREEN"[TR_PRINTF] - This is a test for %-15X !!\n\n\n", 15); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %-#15X !!\", 15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %-#15X !!\n\n\n", 15151515); 
    printf(GREEN"[TR_PRINTF] - This is a test for %-#15X !!\n\n\n", 15151515); 

    printf(YEL"\n===========================\n"NC);
    return (1);
}


static int  test_b()
{
    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %b !!\", 4)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %b !!\n\n\n", 4); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %b !!\", 11)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %b !!\n\n\n", 11); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %b !!\", 1234)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %b !!\n\n\n", 1234); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %34b !!\", 4)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %34b !!\n\n\n", 4); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %-34b !!\", 11)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %-34b !!\n\n\n", 11); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %0b !!\", 1234)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %0b !!\n\n\n", 1234); 

    return (1);
}

static int  test_d()
{

    printf(YEL"======= TEST FOR %%d/i =======\n\n"NC);

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %ld !!\", (long)444444)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %ld !!\n\n\n", (long)444444); 
    printf(GREEN"[TR_PRINTF] - This is a test for %ld !!\n\n\n", (long)444444); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %lld !!\", (long long)4444445555555)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %lld !!\n\n\n", (long long)4444445555555); 
    printf(GREEN"[TR_PRINTF] - This is a test for %lld !!\n\n\n", (long long)4444445555555); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %hd !!\", (short)4444445555555)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %hd !!\n\n\n", (short)4444445555555); 
    printf(GREEN"[TR_PRINTF] - This is a test for %hd !!\n\n\n", (short)4444445555555); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %hhd !!\", (char)444534))\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %hhd !!\n\n\n", (char)444534); 
    printf(GREEN"[TR_PRINTF] - This is a test for %hhd !!\n\n\n", (char)444534); 
    
    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %d !!\", 444444)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %d !!\n\n\n", 444444); 
    printf(GREEN"[TR_PRINTF] - This is a test for %d !!\n\n\n", 444444); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %03d !!\", 444444)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %03d !!\n\n\n", 444444); 
    printf(GREEN"[TR_PRINTF] - This is a test for %03d !!\n\n\n", 444444); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %015d !!\", 444444)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %015d !!\n\n\n", 444444); 
    printf(GREEN"[TR_PRINTF] - This is a test for %015d !!\n\n\n", 444444); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for % 15d !!\", 424242)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for % 15d !!\n\n\n", 424242); 
    printf(GREEN"[TR_PRINTF] - This is a test for % 15d !!\n\n\n", 424242); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %-15d !!\", 15)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %-15d !!\n\n\n", 15); 
    printf(GREEN"[TR_PRINTF] - This is a test for %-15d !!\n\n\n", 15); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %+015d !!\", 15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %+015d !!\n\n\n", 15151515); 
    printf(GREEN"[TR_PRINTF] - This is a test for %+015d !!\n\n\n", 15151515); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %+d !!\", 1515151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %+d !!\n\n\n", 1515151515); 
    printf(GREEN"[TR_PRINTF] - This is a test for %+d !!\n\n\n", 1515151515); 
    
    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %+d !!\", -15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %+d !!\n\n\n", -1515151515); 
    printf(GREEN"[TR_PRINTF] - This is a test for %+d !!\n\n\n", -1515151515); 

    printf(YEL"\n===========================\n"NC);
    return (1);
}

static int  test_u()
{
    printf(YEL"======= TEST FOR %%u =======\n\n"NC);

    
    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %u !!\", 15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %u !!\n\n\n", 1515151515); 
    printf(GREEN"[TR_PRINTF] - This is a test for %u !!\n\n\n", 1515151515); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %0u !!\", 15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %0u !!\n\n\n", 1515151515); 
    printf(GREEN"[TR_PRINTF] - This is a test for %0u !!\n\n\n", 1515151515); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %012u !!\", 15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %012u !!\n\n\n", 1515151515); 
    printf(GREEN"[TR_PRINTF] - This is a test for %012u !!\n\n\n", 1515151515); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %-12u !!\", 15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %-12u !!\n\n\n", 1515151515); 
    printf(GREEN"[TR_PRINTF] - This is a test for %-12u !!\n\n\n", 1515151515); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %12u !!\", 15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %12u !!\n\n\n", 1515151515); 
    printf(GREEN"[TR_PRINTF] - This is a test for %12u !!\n\n\n", 1515151515); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %12lu !!\", 15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %12lu !!\n\n\n", (unsigned long)1515151515); 
    printf(GREEN"[TR_PRINTF] - This is a test for %12lu !!\n\n\n", (unsigned long)1515151515); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %12hu !!\", 15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %12hu !!\n\n\n", (unsigned short)1515151515); 
    printf(GREEN"[TR_PRINTF] - This is a test for %12hu !!\n\n\n", (unsigned short)1515151515); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %1hhu !!\", 15)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %1hhu !!\n\n\n", (char)15); 
    printf(GREEN"[TR_PRINTF] - This is a test for %1hhu !!\n\n\n", (char)15); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %-4llu !!\", 987654321)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %-4llu !!\n\n\n", (long long)987654321); 
    printf(GREEN"[TR_PRINTF] - This is a test for %-4llu !!\n\n\n", (long long)987654321); 

    printf(YEL"\n===========================\n"NC);
    return (1);
}

static int  test_f()
{
    printf(YEL"======= TEST FOR %%f =======\n\n"NC);

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %Lf !!\", (double)444444)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %Lf !!\n\n\n", (long double)444444.23434); 
    printf(GREEN"[TR_PRINTF] - This is a test for %Lf !!\n\n\n", (long double)444444.32434); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %f !!\", (float)444444.5555555)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %f !!\n\n\n", (float)444444.5555555); 
    printf(GREEN"[TR_PRINTF] - This is a test for %f !!\n\n\n", (float)444444.5555555); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %f !!\", 3.33333333333)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %f !!\n\n\n", 3.33333333333); 
    printf(GREEN"[TR_PRINTF] - This is a test for %f !!\n\n\n", 3.33333333333); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %f !!\", 3.3)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %f !!\n\n\n", 3.3); 
    printf(GREEN"[TR_PRINTF] - This is a test for %f !!\n\n\n", 3.3); 
    
    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %f !!\", 4545354534.4)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %f !!\n\n\n", 4545354534.4); 
    printf(GREEN"[TR_PRINTF] - This is a test for %f !!\n\n\n", 4545354534.4); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %0.2f !!\", 44.4424)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %0.2f !!\n\n\n", 44.4424); 
    printf(GREEN"[TR_PRINTF] - This is a test for %0.2f !!\n\n\n", 44.4424); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %015f !!\", 44.424657444)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %015f !!\n\n\n", 44.424657444); 
    printf(GREEN"[TR_PRINTF] - This is a test for %015f !!\n\n\n", 44.424657444); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for % 15f !!\", 42.42429876)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for % 15f !!\n\n\n", 42.42429876); 
    printf(GREEN"[TR_PRINTF] - This is a test for % 15f !!\n\n\n", 42.42429876); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %-15f !!\", 1545.5232)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %-15f !!\n\n\n", 1545.5232); 
    printf(GREEN"[TR_PRINTF] - This is a test for %-15f !!\n\n\n", 15.5232); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %+015f !!\", 15.37864394857345)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %+015f !!\n\n\n", 15.37864394857345); 
    printf(GREEN"[TR_PRINTF] - This is a test for %+015f !!\n\n\n", 15.37864394857345); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %+0.12Lf !!\", 15.37864394857345)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %+0.12Lf !!\n\n\n", (long double)15.37864394857345); 
    printf(GREEN"[TR_PRINTF] - This is a test for %+0.12Lf !!\n\n\n", (long double)15.37864394857345); 
    
    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %+.32f !!\", -15.37864394857345)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %+.32f !!\n\n\n", -15.37864394857345); 
    printf(GREEN"[TR_PRINTF] - This is a test for %+.32f !!\n\n\n", -15.37864394857345); 

    printf(YEL"\n===========================\n"NC);
    return (1);
}

static int  test_o()
{
    printf(YEL"======= TEST FOR %%o =======\n\n"NC);

    
    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %o !!\", 15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %o !!\n\n\n", 1515151515); 
    printf(GREEN"[TR_PRINTF] - This is a test for %o !!\n\n\n", 1515151515); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %020o !!\", 15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %020o !!\n\n\n", 1515151515); 
    printf(GREEN"[TR_PRINTF] - This is a test for %020o !!\n\n\n", 1515151515); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %012o !!\", 15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %012o !!\n\n\n", 1515151515); 
    printf(GREEN"[TR_PRINTF] - This is a test for %012o !!\n\n\n", 1515151515); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %-120o !!\", 15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %-120o !!\n\n\n", 1515151515); 
    printf(GREEN"[TR_PRINTF] - This is a test for %-120o !!\n\n\n", 1515151515); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %42o !!\", 15151515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %42o !!\n\n\n", 1515151515); 
    printf(GREEN"[TR_PRINTF] - This is a test for %42o !!\n\n\n", 1515151515); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %12lo !!\", 1515421515)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %12lo !!\n\n\n", (unsigned long)1515421515); 
    printf(GREEN"[TR_PRINTF] - This is a test for %12lo !!\n\n\n", (unsigned long)1515421515); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %12ho !!\", 999)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %12ho !!\n\n\n", (unsigned short)999); 
    printf(GREEN"[TR_PRINTF] - This is a test for %12ho !!\n\n\n", (unsigned short)999); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %1hho !!\", 15)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %1hho !!\n\n\n", (char)15); 
    printf(GREEN"[TR_PRINTF] - This is a test for %1hho !!\n\n\n", (char)15); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %-4llo !!\", 987654321)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %-4llo !!\n\n\n", (long long)987654321); 
    printf(GREEN"[TR_PRINTF] - This is a test for %-4llo !!\n\n\n", (long long)987654321); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %#llo !!\", 987654321)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %#llo !!\n\n\n", (long long)987654321); 
    printf(GREEN"[TR_PRINTF] - This is a test for %#llo !!\n\n\n", (long long)987654321); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %#0llo !!\", 987654321)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %#0llo !!\n\n\n", (long long)987654321); 
    printf(GREEN"[TR_PRINTF] - This is a test for %#0llo !!\n\n\n", (long long)987654321); 

    printf(YEL"\n===========================\n"NC);
    return (1);
}


static int test_p()
{
    int     ***y;
    int     **z;
    int     *a;
    int     b;

    a = &b;
    z = &a;
    b = 42;
    y = &z;
    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %-70p !!\", a)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %-70p !!\n", a); 
    printf(GREEN"[PRINTF] - This is a test for %-70p !!\n\n\n", a); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %70p !!\", a)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %70p !!\n", z); 
    printf(GREEN"[PRINTF] - This is a test for %70p !!\n\n\n", z); 

    ft_putstr(GOOD"[TEST] ft_printf(GREEN\"[FT_PRINTF] - This is a test for %p !!\", a)\n");
    ft_printf(GREEN"[FT_PRINTF] - This is a test for %p !!\n", y); 
    printf(GREEN"[PRINTF] - This is a test for %p !!\n\n\n", y); 
    return (1);
}

int     main(void)
{
    char c;

    c = 0;
    while (c != 'q')
    {
        ft_printf("Conversion a tester: (press 'q' for quit, press 'D' for clear)\n");
        read(0, &c, 2);   
        system("clear");

        switch (c)
        {
            case 'c':
                test_c();
                break ;
            case 'x':
                test_x();
                break ;
            case 'X':
                test_X();
                break ;
            case 'i':
            case 'd':
                test_d();
                break ;
            case 'u':
                test_u();
                break ;
            case 'o':
                test_o();
                break ;
            case 'p':
                test_p();
                break ;
            case 'b':
                test_b();
                break ;
            case 'f':
                test_f();
                break ;
            case 'D':
                system("clear");
                break ;
        }
    }
    return (0);
}
