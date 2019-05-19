/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 08:35:31 by sgury             #+#    #+#             */
/*   Updated: 2019/05/15 09:47:31 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		pf_c(va_list ap,t_data_tab *data)
{
	char	c;

//	if flag '+' || '0' || '.' printf=> error: flag '+' results in undefined behavior with 'c'
//	conversion specifier [-Werror,-Wformat]
//
//	FLAGS VALABLES = 'nb positif > 0' => largeur le l'affichage, si 2 : ajoute un espace
//	|| '-' (alligne a droite si espace, sinon ignore) ||
//	
//
//	if (flags != NULL)
//		..

	c = va_arg(ap, char);
	ft_putchar(c);
	return (0);
}
