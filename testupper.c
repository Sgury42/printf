#include <stdio.h>
#include "libft/libft.h"
/*
static void	upperx(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' || str[i] <= 'z')
			str[i] = str[i] - 32;
	}
}
*/


int	main()
{
	char	str[123] = "La vie est belle 12345";
	int	i;

	i = 0;
//	upperx(&str);
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	printf("str uppered= %s\n", str);
	return(0);
}
