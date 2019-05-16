
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct	s_data_tab
{
	int			just_left;
	int			sign;
	int			space;
}				t_data_tab;


int		main()
{
	t_data_tab	data;

	int		*flags[3] = { &data.just_left , &data.sign , &data.space };
	char	character[3] = { '-' , '+' , ' ' };
	int		index;
	int		i;
	char	str[123] = "+blablabla";

	ft_bzero(&data, sizeof(t_data_tab));
	index = 0;
	i = 0;
	while (str[index] != character[i])
		i++;
	*flags[i] = 1;
	printf("sign = %d\n", data.sign);
}
