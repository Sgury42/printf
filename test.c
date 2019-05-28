
#include <stdio.h>

int		main()
{
	/*-				yes
	 * +			no	
	 * ' '			no	
	 * 0			yes but not compatible with flag -  !!! if neg nbr 0 are between - and nbr: -0015
	 * #			yes
	 * L			no
	 * h			yes use for argument type short
	 * l			yes use for argument type long
	 * hh			yes use for argument type char
	 * ll			yes use for argument type long long
	 * width		yes
	 * precision	yes display n 0 before nbr, n = precision - nb length
	 */
	printf("%#012xblablabla%#xendofline\n", 2500, 123);
}
