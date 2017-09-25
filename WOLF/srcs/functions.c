/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 09:54:58 by vtiterin          #+#    #+#             */
/*   Updated: 2017/01/04 09:55:00 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		maph(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

double	true_angl(double angl)
{
	if (angl < 0)
		return (angl + 360);
	if (angl > 360)
		return (angl - 360);
	else
		return (angl);
}

void	wr_floor(t_ray *ray, t_main *tab, int i, int y)
{
	double weight;
	double dstx;
	double dsty;

	while (y < CH)
	{
		weight = CH / (2.0 * y - CH) / ray->ddist;
		dstx = weight * tab->fxwm + (1.0 - weight) * tab->px;
		dsty = weight * tab->fywm + (1.0 - weight) * tab->py;
		if (tab->lvl == 5)
			floor_lvl1(tab, dstx, dsty);
		else
			floor_lvl2(tab, dstx, dsty);
		ft_memcpy(&tab->ibuf[(i * 4) + (y * tab->isize)],
			&tab->f->wbuf[((int)(dstx * tab->f->ww * 2) %
			tab->f->ww * 4) + (int)(dsty * tab->f->wh *
			2) % tab->f->wh * tab->f->wsize], 4);
		y++;
	}
}

void	fps(t_main *tab)
{
	if (time(NULL) != tab->time)
	{
		tab->fps2 = tab->fps;
		tab->fps = 0;
		tab->time = (int)time(NULL);
	}
	else
		tab->fps++;
	mlx_string_put(tab->mlx, tab->win, 10, 15, 0xFFFFFF, "FPS  :");
	mlx_string_put(tab->mlx, tab->win, 70, 15, 0xFFFFFF, ft_itoa(tab->fps2));
}

void	mowing(t_main *tab)
{
	if (tab->left == 1)
		ft_im_left(tab);
	if (tab->right == 1)
		ft_im_right(tab);
	if (tab->up == 1)
		ft_im_up(tab);
	if (tab->down == 1)
		ft_im_down(tab);
	if (tab->str_l == 1)
		ft_strafe_l(tab);
	if (tab->str_r == 1)
		ft_strafe_r(tab);
}
