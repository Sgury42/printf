/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:16:08 by sgury             #+#    #+#             */
/*   Updated: 2019/05/13 19:43:47 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_printf(const char *format, ...)
{
	t_data_tab	*data;

	if ((data = (t_data_tab *)malloc(sizeof(t_data_tab))) == NULL)
		return ;
	while((ret = ft_parse(format + ret, data)) > 0)
	{
		if (ft_dispatcher(ap, data) < 0);
		return ;
	}
}
