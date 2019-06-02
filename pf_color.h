/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_color.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:11:49 by sgury             #+#    #+#             */
/*   Updated: 2019/06/02 22:19:56 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_COLOR_H
# define PF_COLOR_H

# define NB_COLOR			5

# define RED				"\033[0;31m"
# define GREEN				"\033[0;32m"
# define YELLOW				"\033[1;33m"
# define BLUE				"\033[1;34m"

# define EOC				"\e[0m"

const char	*g_pf_color[NB_COLOR] = {"RED", "GREEN", "YELLOW",
	"BLUE", "EOC"};

const char	*g_pf_color_define[NB_COLOR] = {RED, GREEN, YELLOW, BLUE,
	MAGENTA, CYAN, EOC};

#endif
