/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_color.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:11:49 by sgury             #+#    #+#             */
/*   Updated: 2019/05/31 17:26:45 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_COLOR_H
# define PF_COLOR_H

# define NB_COLOR			7

# define RED				"\e[1;30;41m"
# define GREEN				"\e[1;30;42m"
# define YELLOW				"\e[1;30;43m"
# define BLUE				"\e[1;30;44m"
# define MAGENTA			"\e[1;30;45m"
# define CYAN				"\e[1;30;46m"

# define EOC				"\e[0m"

const char	*g_pf_color[NB_COLOR] = {"RED", "GREEN", "YELLOW", "BLUE",
	"MAGENTA", "CYAN", "EOC"};

const char	*g_pf_color_define[NB_COLOR] = {RED, GREEN, YELLOW, BLUE,
	MAGENTA, CYAN, EOC};

#endif
