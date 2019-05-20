
#include <stdio.h>
#include "ft_printf.h"

int		main()
{
	int 	spaces;
	char	*ret;
	char	*str;
	int 	i;
	int		width;
	char	*tmp;

	str = "coucou";
	width = 10;
	spaces = width - ft_strlen(str);
	i = 0;
//	if (spaces <= 0)
//		return (str);
	if ((ret = (char *)malloc(sizeof(char) * (width + 1))) == NULL)
		return (-1);
	while (spaces > 0)
	{
		ret[i++] = ' ';
		spaces--;
	}
	while (*str)
		ret[i++] = *str++;
	ret[i] = '\0';
	tmp = ret;
	free(ret);
	printf("after: %s\n", tmp);
	return (0);
}
