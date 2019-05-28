#include "libft/libft.h"
#include <stdio.h>

int		main()
{
	char 	*str = "la vie est belle 123456";
	int		i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	printf("uppered? => %s\n", str);
	return (0);
}
