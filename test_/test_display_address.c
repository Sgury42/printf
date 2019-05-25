/*#include <stdio.h>*/
/*#include "ft_printf.h"*/


/*int     p(long long nbr)*/
/*{*/
    /*char tmp[32];*/
    /*int i;*/

    /*i = 0;*/
    /*ft_memcpy(tmp, &nbr, 13);*/
    /*while (i++ < 13)*/
        /*ft_putchar(tmp[i] - '0');*/
    /*return (1);*/
/*}*/

/*int main()*/
/*{*/
    /*int *a;*/
    /*int b;*/

    /*a = &b;*/
    /*b = 45;*/
    /*p((long long)a);*/
    /*printf("\n%p\n", a);*/
    /*return (0);*/
/*}*/

#include <stdio.h>
#include <string.h>
#include "ft_printf.h"


void    print_ptr(long long *p)
{
        unsigned char t[sizeof p];
        unsigned char t_16[sizeof p];
        size_t i;

        /*memcpy(t, &ft_itoa_base(p, 16), sizeof p);*/
        for (i = 0; i < sizeof p; ++i) {
                printf("%02x", t[i]);
        }
}


int
main(void)
{
        long long n;
        long long *p = &n;

        /*print_ptr(p);*/
        /*putchar('\n');*/
        ft_putnbr((int)p);
        putchar('\n');
        ft_putstr("0x");
        ft_putstr(ft_itoa_base((long long)p, 16));
        putchar('\n');
        printf("%p", p);
        return 0;
}
