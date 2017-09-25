/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 08:34:36 by vtiterin          #+#    #+#             */
/*   Updated: 2017/01/12 08:34:38 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	floor_lvl1(t_main *tab, double x, double y)
{
	if (tab->map[(int)y][(int)x] == '+')
		tab->f = tab->w_arr[1];
	else
		tab->f = tab->w_arr[0];
}

void	ini_lvl1(t_main *tab)
{
	tab->hp = 100;
	tab->cons = 0;
	tab->mask = 0;
	tab->z_pov = 0;
	tab->map = tab->map_lvl1;
	tab->px = 7.5;
	tab->py = 1.5;
	tab->mh = maph(tab->map) - 1;
	tab->mw = ft_strlen(tab->map[0]) - 1;
	tab->ini_l1 = 1;
}

void	shootlvl1(t_main *tab)
{
	double px;
	double py;

	px = tab->px;
	py = tab->py;
	while (1)
	{
		if (tab->map[(int)py][(int)px] >= '0' || py < 0 || py > tab->mh ||
			px < 0 || px > tab->mw)
		{
			if (tab->map[(int)py][(int)px] == '5')
				tab->map[(int)py][(int)px] = 'a';
			if (tab->map[(int)py][(int)px] == '7')
				tab->map[(int)py][(int)px] = 'b';
			break ;
		}
		px = px + 0.1 * cos(RAD(tab->pov));
		py = py + 0.1 * sin(RAD(tab->pov));
	}
}

void	f_expose_lvl1(t_main *tab)
{
	if (tab->wp_b > 0)
	{
		wr_wepon(tab, tab->wp);
		tab->wp++;
		if (tab->wp == 10)
		{
			tab->wp = 0;
			tab->wp_b = 0;
		}
	}
	else
		wr_wepon(tab, 0);
	if (tab->mask == 1)
		wr_mask(tab, 5);
	if (tab->hp < 0)
		tab->lvl = 9;
	if (tab->map[(int)tab->py][(int)tab->px] == '+')
		tab->hp -= 0.10;
	else if (tab->map[(int)tab->py][(int)tab->px] == '1')
	{
		tab->mask = 0;
		tab->z_pov = 0;
		tab->fov = 60;
		tab->hp = 100;
	}
}

void	expose_lvl1(t_main *tab)
{
	if (tab->ini_l1 == 0)
		ini_lvl1(tab);
	tab->image = mlx_new_image(tab->mlx, CW, CH);
	tab->ibuf = mlx_get_data_addr(tab->image, &(tab->icolor),
		&(tab->isize), &(tab->iendian));
	wr_map(tab);
	if (tab->cons == 5)
	{
		tab->map[17][12] = 'c';
		tab->map[17][13] = 'c';
		tab->map[17][14] = 'c';
	}
	if (tab->z_pov == 1)
		tab->fov = 110;
	f_expose_lvl1(tab);
	if (tab->map[(int)tab->py][(int)tab->px] == '2')
		tab->mask = 1;
	if (tab->map[(int)tab->py][(int)tab->px] == '3')
		tab->z_pov = 1;
	mlx_put_image_to_window(tab->mlx, tab->win, tab->image, 0, 0);
	fps(tab);
	mlx_string_put(tab->mlx, tab->win, 10, 30, 0xFFFFFF, "HP  :");
	mlx_string_put(tab->mlx, tab->win, 70, 30, 0xFFFFFF, ft_itoa((int)tab->hp));
	mlx_destroy_image(tab->mlx, tab->image);
	mowing(tab);
}
