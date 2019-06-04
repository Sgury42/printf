#include "ft_printf.h"

int	main()
{
	int	nb;

	nb = -45;
	ft_printf("5.3d: %5.3d.\n", nb);
	printf("5.3d: %5.3d.\n----------\n", nb);
	ft_printf("+d: %+d.\n", nb);
	printf("+d: %+d.\n----------\n", nb);
	ft_printf(".5d: %.5d.\n", nb);
	printf(".5d: %.5d.\n----------\n", nb);
	ft_printf(" .5d: % .5d.\n", nb);
	printf(" .5d: % .5d.\n----------\n", nb);
	ft_printf("+.5d: %+.5d.\n", nb);
	printf("+.5d: %+.5d.\n----------\n", nb);
	ft_printf("+.0d: %+.0d.\n", nb);
	printf("+.0d: %+.0d.\n----------\n", nb);
	ft_printf("0.5d: %0.5d.\n", nb);
	printf("0.5d: %0.5d.\n----------\n", nb);
	ft_printf("-.5d: %-.5d.\n", nb);
	printf("-.5d: %-.5d.\n----------\n", nb);
	ft_printf("5d: %5d.\n", nb);
	printf("5d: %5d.\n----------\n", nb);
	ft_printf(" 5d: % 5d.\n", nb);
	printf(" 5d: % 5d.\n----------\n", nb);
	ft_printf("+5d: %+5d.\n", nb);
	printf("+5d: %+5d.\n----------\n", nb);
	ft_printf("-5d: %-5d.\n", nb);
	printf("-5d: %-5d.\n----------\n", nb);
	ft_printf("05d: %05d.\n", nb);
	printf("05d: %05d.\n----------\n", nb);
	ft_printf("+05d: %+05d.\n", nb);
	printf("+05d: %+05d.\n----------\n", nb);
	ft_printf("0+5d: %0+5d.\n", nb);
	printf("0+5d: %0+5d.\n----------\n", nb);
	ft_printf("05.3d: %05.3d.\n", nb);
	printf("05.3d: %05.3d.\n----------\n", nb);
	ft_printf("-5.3d: %-5.3d.\n", nb);
	printf("-5.3d: %-5.3d.\n----------\n", nb);
	ft_printf("+05.3d: %+05.3d.\n", nb);
	printf("+05.3d: %+05.3d.\n----------\n", nb);
	ft_printf("0 5.3d: %0 5.3d.\n", nb);
	printf("0 5.3d: %0 5.3d.\n----------\n", nb);
	ft_printf(" 05.3d: % 05.3d.\n", nb);
	printf(" 05.3d: % 05.3d.\n----------\n", nb);
	ft_printf("-+5.3d: %-+5.3d.\n", nb);
	printf("-+5.3d: %-+5.3d.\n----------\n", nb);

	return (0);
}
