/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 07:11:05 by vtiterin          #+#    #+#             */
/*   Updated: 2017/01/04 07:11:08 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw(t_ray *ray, t_main *tab, int i)
{
	int		x;
	int		h;
	double	img;

	img = 0;
	if (ray->ddist >= 0.1)
		h = (int)((CH) / ray->ddist);
	else
		h = (int)CH / 0.1;
	ray->roof = (CH - h) / 2;
	ray->wall = ray->roof + h;
	if (ray->wall > CH)
		ray->wall = CH;
	x = ray->roof;
	while (x < ray->wall)
	{
		if (x > 0)
			ft_memcpy(&tab->ibuf[(i * 4) + (x * tab->isize)],
			&tab->w->wbuf[(tab->i_img * 4) + (int)img *
			tab->w->wsize], 4);
		x++;
		img += (double)tab->w->wh / h;
	}
	wr_floor(ray, tab, i, x);
}

void	ch_draw_g(t_ray *ray, t_main *tab, int i, double angl)
{
	if (tab->lvl == 5)
		wallg_lvl1(tab);
	else if (tab->lvl == 7)
		wallg_lvl2(tab);
	else if (tab->lvl == 8)
		wallg_lvl3(tab);
	if (tab->lvl == 8 && tab->map[tab->gy][(int)tab->g] != '1'
	&& tab->map[tab->gy][(int)tab->g] != '5')
		tab->i_img = (int)(tab->g * (tab->w->ww / 4.0)) % tab->w->ww;
	else if ((tab->map[tab->gy][(int)tab->g] == 'g' ||
	tab->map[tab->gy][(int)tab->g] == '1') && tab->lvl == 7)
		tab->i_img = (int)(tab->g * (tab->w->ww / 2.0)) % tab->w->ww;
	else
		tab->i_img = (int)(tab->g * tab->w->ww) % tab->w->ww;
	ray->ddist = ray->d_gor * cos(RAD(ABS(angl - tab->pov)));
	tab->fxwm = tab->fxwg;
	tab->fywm = tab->fywg;
}

void	ch_draw_v(t_ray *ray, t_main *tab, int i, double angl)
{
	if (tab->lvl == 5)
		wallv_lvl1(tab);
	else if (tab->lvl == 7)
		wallv_lvl2(tab);
	else if (tab->lvl == 8)
		wallv_lvl3(tab);
	if (tab->lvl == 8 && tab->map[(int)tab->v][tab->vx] != '1'
	&& tab->map[(int)tab->v][tab->vx] != '5')
		tab->i_img = (int)(tab->v * (tab->w->ww / 4.0)) % tab->w->ww;
	else if ((tab->map[(int)tab->v][tab->vx] == 'g' ||
	tab->map[(int)tab->v][tab->vx] == '1') && tab->lvl == 7)
		tab->i_img = (int)(tab->v * (tab->w->ww / 2.0)) % tab->w->ww;
	else
		tab->i_img = (int)(tab->v * tab->w->ww) % tab->w->ww;
	ray->ddist = ray->d_vert * cos(RAD(ABS(angl - tab->pov)));
	tab->fxwm = tab->fxwv;
	tab->fywm = tab->fywv;
}

void	ch_draw(t_ray *ray, t_main *tab, int i, double angl)
{
	if (ray->d_gor < ray->d_vert)
		ch_draw_g(ray, tab, i, angl);
	else
		ch_draw_v(ray, tab, i, angl);
	draw(ray, tab, i);
}

void	wr_map(t_main *tab)
{
	t_ray	*ray;
	int		i;

	ray = (t_ray*)malloc(sizeof(t_ray));
	ray->angle = tab->pov - tab->fov / 2;
	if (tab->lvl == 5)
		ft_win_sky(tab, 2, ray->angle);
	else if (tab->lvl == 8)
		ft_win_sky(tab, 1, ray->angle);
	else
		ft_win_sky(tab, 0, ray->angle);
	i = CW - 1;
	while (i >= 0)
	{
		ray->angle = true_angl(ray->angle);
		ray->cosa = cos(RAD(ray->angle));
		ray->tana = tan(RAD(ray->angle));
		ray->sina = sin(RAD(ray->angle));
		ray->d_vert = vert(tab, ray, ray->angle);
		ray->d_gor = gor(tab, ray, ray->angle);
		ch_draw(ray, tab, i, ray->angle);
		i--;
		ray->angle += tab->ugl;
	}
	free(ray);
}
