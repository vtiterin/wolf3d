/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 10:30:37 by vtiterin          #+#    #+#             */
/*   Updated: 2017/01/14 10:30:40 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_im_up(t_main *tab)
{
	double x;
	double y;

	x = tab->px + 0.3 * cos(RAD(tab->pov));
	y = tab->py + 0.3 * sin(RAD(tab->pov));
	if (tab->map[r(y)][r(x)] < '4' &&
		tab->map[(int)(y - 0.1)][(int)(x - 0.1)] < '4')
	{
		tab->px = x;
		tab->py = y;
	}
}

void	ft_im_down(t_main *tab)
{
	double x;
	double y;

	x = tab->px - 0.3 * cos(RAD(tab->pov));
	y = tab->py - 0.3 * sin(RAD(tab->pov));
	if (tab->map[r(y)][r(x)] < '4' &&
		tab->map[(int)(y - 0.1)][(int)(x - 0.1)] < '4')
	{
		tab->px = x;
		tab->py = y;
	}
}

void	f2_mouse_hook(int button, int x, int y, t_main *tab)
{
	if (tab->lvl == 2 && button == 1 && (x > 1190 && x < 1280)
		&& (y > 940 && y < 980))
		tab->lvl = 1;
	else if (tab->lvl == 2 && button == 1 && (x > 10 && x < 100)
		&& (y > 950 && y < 1000))
		exit(0);
	else if (tab->lvl == 4 && button == 1 && (x > 1040 && x < 1250)
		&& (y > 820 && y < 870))
		tab->lvl = 5;
	else if (tab->lvl == 4 && button == 1 && (x > 0 && x < 120)
		&& (y > 830 && y < 880))
		exit(0);
	else if (tab->lvl == 6 && button == 1 && (x > 340 && x < 550)
		&& (y > 540 && y < 590))
		tab->lvl = 7;
	else if (tab->lvl == 6 && button == 1 && (x > 970 && x < 1080)
		&& (y > 620 && y < 670))
		exit(0);
}

void	f_mouse_hook(int button, int x, int y, t_main *tab)
{
	if (tab->lvl == 1 && button == 1 && (x > 35 && x < 400)
		&& (y > 520 && y < 580))
		tab->lvl = 2;
	else if (tab->lvl == 1 && button == 1 && (x > 35 && x < 180)
		&& (y > 640 && y < 700))
		exit(0);
	else if (tab->lvl == 2 && button == 1 && (x > 940 && x < 1000)
		&& (y > 940 && y < 980))
		tab->lvl = 3;
	else if (tab->lvl == 2 && button == 1 && (x > 1030 && x < 1100)
		&& (y > 940 && y < 980))
		tab->lvl = 5;
	else if (tab->lvl == 2 && button == 1 && (x > 1017 && x < 1178)
		&& (y > 600 && y < 610))
		tab->lvl = 8;
	else if (tab->lvl == 2 && button == 1 && (x > 1110 && x < 1180)
		&& (y > 940 && y < 980))
		tab->lvl = 7;
	else
		f2_mouse_hook(button, x, y, tab);
}

int		mouse_hook(int button, int x, int y, t_main *tab)
{
	if (tab->lvl == 1 && button == 1 && (x > 35 && x < 415)
		&& (y > 400 && y < 460))
		tab->lvl = 3;
	else
		f_mouse_hook(button, x, y, tab);
	if (button == 1)
	{
		if (tab->lvl == 5)
			shootlvl1(tab);
		if (tab->lvl == 7)
			shootlvl2(tab);
		tab->wp_b++;
	}
	return (0);
}
