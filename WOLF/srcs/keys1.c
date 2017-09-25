/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 09:53:47 by vtiterin          #+#    #+#             */
/*   Updated: 2017/01/04 09:53:48 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		r(double f)
{
	if (f - (int)f > 0.9)
		return (ceil(f));
	else
		return ((int)f);
}

void	ft_im_left(t_main *tab)
{
	tab->pov = tab->pov + 4.0;
	tab->pov = true_angl(tab->pov);
}

void	ft_im_right(t_main *tab)
{
	tab->pov = tab->pov - 4.0;
	tab->pov = true_angl(tab->pov);
}

void	ft_strafe_l(t_main *tab)
{
	double x;
	double y;

	x = tab->px - 0.2 * sin(RAD(tab->pov));
	y = tab->py + 0.2 * cos(RAD(tab->pov));
	if (tab->map[r(y)][r(x)] < '4' &&
		tab->map[(int)(y - 0.1)][(int)(x - 0.1)] < '4')
	{
		tab->px = x;
		tab->py = y;
	}
}

void	ft_strafe_r(t_main *tab)
{
	double x;
	double y;

	x = tab->px + 0.2 * sin(RAD(tab->pov));
	y = tab->py - 0.2 * cos(RAD(tab->pov));
	if (tab->map[r(y)][r(x)] < '4' &&
		tab->map[(int)(y - 0.1)][(int)(x - 0.1)] < '4')
	{
		tab->px = x;
		tab->py = y;
	}
}
