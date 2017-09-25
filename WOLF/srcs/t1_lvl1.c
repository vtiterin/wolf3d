/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t1_lvl1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:13:15 by vtiterin          #+#    #+#             */
/*   Updated: 2017/01/12 11:13:17 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	f_draw_all(t_ray *ray, t_main *tab, int i)
{
	double	img;

	img = 0;
	while (ray->x < ray->wall)
	{
		if (ray->x > 0)
		{
			if (tab->lvl0->ist == 1)
				ft_memcpy(&tab->ibuf[(i * 4) + (ray->x * tab->isize)],
				&tab->w->wbuf[(tab->i_img * 4) + (int)img * tab->w->wsize], 4);
			else
				ft_memcpy(&tab->ibuf[(i * 4) + (ray->x * tab->isize)],
				&(tab->lvl0->c_wall), 4);
		}
		if (tab->lvl0->ist == 1)
			img += (double)tab->w->wh / ray->h;
		ray->x++;
	}
}

void	draw_all(t_ray *ray, t_main *tab, int i)
{
	if (ray->ddist >= 0.1)
		ray->h = (int)((CH) / ray->ddist);
	else
		ray->h = (int)CH / 0.1;
	ray->roof = (CH - ray->h) / 2;
	ray->wall = ray->roof + ray->h;
	ray->x = 0;
	while (ray->x < ray->roof)
		ft_memcpy(&tab->ibuf[(i * 4) + (ray->x++ * tab->isize)],
		&(tab->lvl0->c_cel), 4);
	if (ray->wall > CH)
		ray->wall = CH;
	ray->x = ray->roof;
	f_draw_all(ray, tab, i);
	while (ray->x < CH)
		ft_memcpy(&tab->ibuf[(i * 4) + (ray->x++ * tab->isize)],
		&(tab->lvl0->c_flor), 4);
}

void	wr_map0(t_main *tab)
{
	t_ray	*ray;
	int		i;

	ray = (t_ray*)malloc(sizeof(t_ray));
	ray->angle = tab->pov - tab->fov / 2;
	i = CW - 1;
	while (i >= 0)
	{
		ray->angle = true_angl(ray->angle);
		ray->cosa = cos(RAD(ray->angle));
		ray->tana = tan(RAD(ray->angle));
		ray->sina = sin(RAD(ray->angle));
		ray->d_vert = vert(tab, ray, ray->angle);
		ray->d_gor = gor(tab, ray, ray->angle);
		ch_draw0(ray, tab, i, ray->angle);
		i--;
		ray->angle += tab->ugl;
	}
	free(ray);
}
