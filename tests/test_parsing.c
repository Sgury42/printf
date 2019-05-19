
#include "../ft_printf.h"

int		main()
{
	t_data_tab	*data;
	t_buff		buff;
	int			index;
	char		format[123] = "la vie est %l-123.456c belle";

//	if (ac != 2)
//		return (-1);
	if ((data = (t_data_tab *)malloc(sizeof(t_data_tab))) == NULL)
		return (-1);
	ft_bzero(data, sizeof(t_data_tab));
	ft_bzero(&buff, sizeof(t_buff));
	buff.len = 0;
	index = 0;
//	format = av[1];
	while ((index = ft_parse(format, data, index, &buff)) > 0)
	{
		ft_put_int_tab(data->flags, 12, ", ");
		ft_putchar(data->conv);
		ft_putchar('\n');
		ft_bzero(data, sizeof(t_data_tab));
	}
	if (index < 0)
		return (printf("-1"));
	ft_putstr(buff.buffer);
	free(data);
	return (0);
}
