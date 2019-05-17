
#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

int		main(int ac, char **av)
{
	t_data_tab	*data;
	int			index;
	int			i;
	char		*format;

	i = 0;
	if (ac != 2)
		return (-1);
	if ((data = (t_data_tab *)malloc(sizeof(t_data_tab))) == NULL)
		return (-1);
	ft_bzero(data, sizeof(t_data_tab));
	index = 0;
	format = av[1];
	while((index = ft_parse(format, data, index)) > 0)
	{
		printf("just_left = %d\nsign = %d\nspace = %d\nzero = %d\nhashtag = %d\nhh = %d\nh = %d\nll = %d\nl = %d\nL = %d\nwidth = %d\nprecision = %d\nconv = %c\n", data->just_left, data->sign, data->space, data->zero, data->hashtag, data->hh, data->h, data->ll, data->l, data->L, data->width, data->precision, data->conv);
		ft_bzero(data, sizeof(t_data_tab));
		data->conv = '\0';
	}
	return (0);
}
