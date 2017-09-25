/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 14:38:51 by vtiterin          #+#    #+#             */
/*   Updated: 2017/01/14 14:38:53 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		motion_hook(int x, int y, t_main *tab)
{
	if (tab->tmpx == 0)
		tab->tmpx = x;
	if (x >= 0 && x <= CW && y >= 0 && y <= CH)
	{
		if (x < tab->tmpx)
		{
			tab->tmpx = x;
			tab->pov = tab->pov + 5;
			tab->pov = true_angl(tab->pov);
		}
		else
		{
			tab->tmpx = x;
			tab->pov = tab->pov - 5;
			tab->pov = true_angl(tab->pov);
		}
		expose_hook(tab);
	}
	return (0);
}

void	lvl_hook(t_main *tab)
{
	tab->image = mlx_new_image(tab->mlx, CW, CH);
	tab->ibuf = mlx_get_data_addr(tab->image, &(tab->icolor),
	&(tab->isize), &(tab->iendian));
	if (tab->lvl == 9)
		wr_menu(tab, 6);
	else if (tab->lvl == 1)
		wr_menu(tab, 7);
	else if (tab->lvl == 2)
		wr_menu(tab, 8);
	else if (tab->lvl == 4)
		wr_menu(tab, 9);
	else if (tab->lvl == 6)
		wr_menu(tab, 10);
}

int		expose_hook(t_main *tab)
{
	if (tab->lvl == 3)
		expose_lvl0(tab);
	else if (tab->lvl == 5)
		expose_lvl1(tab);
	else if (tab->lvl == 7)
		expose_lvl2(tab);
	else if (tab->lvl == 8)
		expose_lvl3(tab);
	else
		lvl_hook(tab);
	return (0);
}

void	ft_ini2(t_main *tab)
{
	tab->tmpx = 0;
	tab->r_arr = sky_arr(tab);
	tab->w_arr = sky_wall(tab);
	tab->wp_arr = wp_arr(tab);
	tab->wp = 0;
	tab->wp_b = 0;
	tab->awl = 0;
	tab->up = 0;
	tab->left = 0;
	tab->right = 0;
	tab->down = 0;
	tab->str_l = 0;
	tab->str_r = 0;
	tab->lvl = 1;
	tab->ini_l1 = 0;
	tab->fps = 0;
	tab->fps2 = 0;
	tab->time = 0;
	tab->st_xm = 0;
	tab->st_ym = 0;
	tab->lvl0 = ini_lvl0(tab);
}

void	ft_ini(t_main *tab)
{
	tab->map_lvl0 = cr_map("./bin/lvl/lvl0.txt");
	tab->map_lvl1 = cr_map("./bin/lvl/lvl1.txt");
	tab->map_lvl2 = cr_map("./bin/lvl/lvl2.txt");
	tab->map_lvl3 = cr_map("./bin/lvl/lvl3.txt");
	tab->fov = 60.0;
	tab->ugl = tab->fov / CW;
	tab->pov = 0;
	tab->mlx = mlx_init();
	tab->win = mlx_new_window(tab->mlx, CW, CH, "wolf3d");
	tab->px = 1.5;
	tab->py = 2.5;
	tab->i_img = 0;
	tab->g = 0;
	tab->v = 0;
	ft_ini2(tab);
}
