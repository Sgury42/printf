
#include "ft_printf.h"

static void	left_justify(char *str, int neg, t_data_tab *data, t_buff *buff)
{
	int	prec;
	int	spaces;

	spaces = 0;
	prec = data->flags[precision] - (int)ft_strlen(str);
	if (data->flags[width] > data->flags[precision])
		spaces = data->flags[width] - data->flags[precision] - neg;
	if (data->flags[width] == 0 && data->flags[space])
		spaces = 1;
	while (prec)
	{
		ft_buffer('0', buff);
		prec--;
	}
	ft_str_to_buff(str, buff);
	while (spaces)
	{
		ft_buffer(' ', buff);
		spaces--;
	}
}

static void	right_justify(char *str, int neg, t_data_tab *data, t_buff *buff)
{
	int	prec;
	int	spaces;

	spaces = 0;
	prec = data->flags[precision] - (int)ft_strlen(str) + neg;
	if (data->flags[width] >data->flags[precision])
		spaces = data->flags[width] - data->flags[precision] - neg;
	if (data->flags[width] == 0 && data->flags[space])
		spaces = 1;
	if (neg == 0 && data->flags[sign])
		spaces -= 1;
	while (spaces)
	{
		ft_buffer(' ', buff);
		spaces--;
	}
	if (neg)
		ft_buffer('-', buff);
	else if (data->flags[sign])
		ft_buffer('+', buff);
	while (prec)
	{
		ft_buffer('0', buff);
		prec--;
	}
	ft_str_to_buff(str + neg, buff);
}

void	ft_unfloat_prec(char *str, t_data_tab *data, t_buff *buff)
{
	int	neg;

	neg = 0;
	if (str[0] == '-')
		neg = 1;
	if (data->flags[just_left])
	{
		if (neg)
			ft_buffer('-', buff);
		else if (data->flags[sign])
		{
			ft_buffer('+', buff);
			data->flags[width] -= 1;
		}
		left_justify(str + neg, neg, data, buff);
	}
	else 
		right_justify(str, neg, data, buff);
}
