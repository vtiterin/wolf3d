/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_g.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 08:07:12 by vtiterin          #+#    #+#             */
/*   Updated: 2017/01/04 08:07:14 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double	ray_up(t_main *tab, t_ray *ray)
{
	ray->dy += 1;
	ray->ddy = (double)ray->dy;
	ray->ddx = (double)(tab->px + (ray->ddy - tab->py) / ray->tana);
	while (1)
	{
		ray->dx = (int)ray->ddx;
		if (ray->dx < 0 || ray->dx > tab->mw ||
			ray->dy < 0 || ray->dy > tab->mh)
			return (D_MAX);
		if (tab->map[ray->dy][ray->dx] >= '0')
		{
			tab->g = ray->ddx;
			tab->gy = ray->dy;
			tab->fxwg = ray->ddx;
			tab->fywg = ray->ddy;
			return (ray->ddy - tab->py) / ray->sina;
		}
		ray->ddx += 1.0 / ray->tana;
		ray->ddy += 1.0;
		ray->dy += 1;
	}
}

double	ray_down(t_main *tab, t_ray *ray)
{
	ray->dy -= 1;
	ray->ddy = (double)(ray->dy + 1);
	ray->ddx = (double)(tab->px + (ray->ddy - tab->py) / ray->tana);
	while (1)
	{
		ray->dx = (int)ray->ddx;
		if (ray->dx < 0 || ray->dx > tab->mw ||
			ray->dy < 0 || ray->dy > tab->mh)
			return (D_MAX);
		if (tab->map[ray->dy][ray->dx] >= '0')
		{
			tab->g = ray->ddx;
			tab->gy = ray->dy;
			tab->fxwg = ray->ddx;
			tab->fywg = ray->ddy;
			return (ray->ddy - tab->py) / ray->sina;
		}
		ray->ddx -= 1.0 / ray->tana;
		ray->ddy -= 1.0;
		ray->dy -= 1;
	}
}

double	gor(t_main *tab, t_ray *ray, double angle)
{
	ray->dx = (int)tab->px;
	ray->dy = (int)tab->py;
	if (angle <= 180)
		return (ray_up(tab, ray));
	else
		return (ray_down(tab, ray));
}
