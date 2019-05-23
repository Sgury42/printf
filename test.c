
#include <stdio.h>

int		main()
{
	/*-				yes
	 * +			yes	
	 * ' '			yes but if neg nbr flag is ignored
	 * 0			yes but not compatible with flag -  !!! if neg nbr 0 are between - and nbr: -0015
	 * #			no
	 * L			no
	 * h			yes use for argument type short
	 * l			yes use for argument type long
	 * hh			yes use for argument type char
	 * ll			yes use for argument type long long
	 * width		yes
	 * precision	yes display n 0 before nbr, n = precision - nb length
	 */
	printf("%z1d", 12);
}
