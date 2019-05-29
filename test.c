
#include <stdio.h>

int		main()
{
	/*-				yes
	 * +			yes
	 * ' '			yes	
	 * 0			yes but not compatible with flag -  !!! if neg nbr 0 are between - and nbr: -0015
	 * #			no
	 * L			yes used for long double
	 * h			no
	 * l			yes use for double
	 * hh			no
	 * ll			no
	 * width		yes
	 * precision	yes 6 nbr precision if non flag
	 */
	printf("%.12lfendofline\n", (double)-0.123456789123);
}
