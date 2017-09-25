/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl0.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 08:34:28 by vtiterin          #+#    #+#             */
/*   Updated: 2017/01/12 08:34:32 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ch_draw0g(t_ray *ray, t_main *tab, int i, double angl)
{
	if (angl <= 180)
		tab->lvl0->c_wall = 0x0000CD;
	else
		tab->lvl0->c_wall = 0x006400;
	if (tab->map[tab->gy][(int)tab->g] == '6')
	{
		tab->w = tab->w_arr[0];
		tab->i_img = (int)(tab->g * tab->w->ww) % tab->w->ww;
		tab->lvl0->ist = 1;
	}
	else
		tab->lvl0->ist = 0;
	ray->ddist = ray->d_gor * cos(RAD(ABS(angl - tab->pov)));
}

void	ch_draw0v(t_ray *ray, t_main *tab, int i, double angl)
{
	if (angl >= 270 || angl <= 90)
		tab->lvl0->c_wall = 0xFFFF00;
	else
		tab->lvl0->c_wall = 0xFF0000;
	if (tab->map[(int)tab->v][tab->vx] == '6')
	{
		tab->w = tab->w_arr[10];
		tab->i_img = (int)(tab->v * tab->w->ww) % tab->w->ww;
		tab->lvl0->ist = 1;
	}
	else
		tab->lvl0->ist = 0;
	ray->ddist = ray->d_vert * cos(RAD(ABS(angl - tab->pov)));
}

void	ch_draw0(t_ray *ray, t_main *tab, int i, double angl)
{
	if (ray->d_gor < ray->d_vert)
		ch_draw0g(ray, tab, i, angl);
	else
		ch_draw0v(ray, tab, i, angl);
	draw_all(ray, tab, i);
}

t_lvl0	*ini_lvl0(t_main *tab)
{
	t_lvl0	*ret;

	ret = (t_lvl0*)malloc(sizeof(t_lvl0));
	ret->c_flor = 0xC1CDCD;
	ret->c_cel = 0x708090;
	ret->ist = 0;
	tab->map = tab->map_lvl0;
	tab->px = 1.5;
	tab->py = 1.5;
	tab->mh = maph(tab->map) - 1;
	tab->mw = ft_strlen(tab->map[0]) - 1;
	return (ret);
}

void	expose_lvl0(t_main *tab)
{
	if (tab->lvl0 == NULL)
		tab->lvl0 = ini_lvl0(tab);
	tab->image = mlx_new_image(tab->mlx, CW, CH);
	tab->ibuf = mlx_get_data_addr(tab->image, &(tab->icolor),
		&(tab->isize), &(tab->iendian));
	wr_map0(tab);
	mlx_put_image_to_window(tab->mlx, tab->win, tab->image, 0, 0);
	mlx_destroy_image(tab->mlx, tab->image);
	fps(tab);
	mowing(tab);
}
