
#include "ft_printf.h"

int		main()
{
	ft_putstr("my printf: ");
	ft_printf("La vie %c est %s belle%+09d\n", 'A', "super", -100);
	ft_putstr("rl printf: ");
	printf("La vie %c est %s belle%+09d\n", 'A', "super", -100);

	return (0);
}
