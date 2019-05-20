
#include <stdio.h>

int		main()
{
	/*-				yes
	 * +			no flag '+' results in undefined behavior with 'c' conversion specifier [-Wformat]
	 * ' '			no
	 * 0			no
	 * #			no
	 * L			no
	 * h			no
	 * l
	 * hh			no
	 * ll			no	
	 * width		yes
	 * precision	no
	 */
	printf("%2s", "salut");
}
