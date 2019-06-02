
#include "ft_printf.h"
#include <unistd.h>

#define NC "\033[0m"
#define RED "\033[0;31m"
#define BLUE "\033[1;34m"
#define GREEN "\033[0;32m"
#define YEL "\033[1;33m"
#define GOOD BLUE
#define FAIL RED


int		main()
{
	ft_printf(GREEN"[FT_PRINTF] - This is a test for %c !!\n\n\n", 'H');

	ft_printf(GREEN"[FT_PRINTF] - This is a test for %x !!\n\n\n", 444444);

	ft_printf(GREEN"[FT_PRINTF] - This is a test for %X !!\n\n\n", 444444);

	ft_printf(GREEN"[FT_PRINTF] - This is a test for %b !!\n\n\n", 4);

	ft_printf(GREEN"[FT_PRINTF] - This is a test for %ld !!\n\n\n", (long)444444);

	ft_printf(GREEN"[FT_PRINTF] - This is a test for %u !!\n\n\n", 1515151515);

	ft_printf(GREEN"[FT_PRINTF] - This is a test for %Lf !!\n\n\n", (long double)444444.23434);

	ft_printf(GREEN"[FT_PRINTF] - This is a test for %o !!\n\n\n", 1515151515);

	int     *a;
	int     b;

	a = &b;
	b = 42;
	ft_printf(GREEN"[FT_PRINTF] - This is a test for %-70p !!\n", a);
	return (0);
}
