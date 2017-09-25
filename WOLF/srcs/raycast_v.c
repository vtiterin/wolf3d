/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_v.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 08:07:05 by vtiterin          #+#    #+#             */
/*   Updated: 2017/01/04 08:07:07 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double	ray_right(t_main *tab, t_ray *ray)
{
	ray->dx += 1;
	ray->ddx = (double)ray->dx;
	ray->ddy = (double)(tab->py + (ray->ddx - tab->px) * ray->tana);
	while (1)
	{
		ray->dy = (int)ray->ddy;
		if (ray->dy < 0 || ray->dy > tab->mh ||
			ray->dx < 0 || ray->dx > tab->mw)
			return (D_MAX);
		if (tab->map[ray->dy][ray->dx] >= '0')
		{
			tab->v = ray->ddy;
			tab->vx = ray->dx;
			tab->fxwv = ray->ddx;
			tab->fywv = ray->ddy;
			return (ray->ddx - tab->px) / ray->cosa;
		}
		ray->ddy += ray->tana;
		ray->ddx += 1.0;
		ray->dx += 1;
	}
}

double	ray_left(t_main *tab, t_ray *ray)
{
	ray->dx -= 1;
	ray->ddx = (double)(ray->dx + 1);
	ray->ddy = (double)(tab->py + (ray->ddx - tab->px) * ray->tana);
	while (1)
	{
		ray->dy = (int)ray->ddy;
		if (ray->dy < 0 || ray->dy > tab->mh ||
			ray->dx < 0 || ray->dx > tab->mw)
			return (D_MAX);
		if (tab->map[ray->dy][ray->dx] >= '0')
		{
			tab->v = ray->ddy;
			tab->vx = ray->dx;
			tab->fxwv = ray->ddx;
			tab->fywv = ray->ddy;
			return (ray->ddx - tab->px) / ray->cosa;
		}
		ray->ddy -= ray->tana;
		ray->ddx -= 1.0;
		ray->dx -= 1;
	}
}

double	vert(t_main *tab, t_ray *ray, double angle)
{
	ray->dx = (int)tab->px;
	ray->dy = (int)tab->py;
	if (angle >= 270 || angle <= 90)
		return (ray_right(tab, ray));
	else
		return (ray_left(tab, ray));
}
