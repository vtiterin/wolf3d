/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 08:34:42 by vtiterin          #+#    #+#             */
/*   Updated: 2017/01/12 08:34:44 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_lvl2	*ini_lvl2(t_main *tab)
{
	t_lvl2	*ret;

	ret = (t_lvl2*)malloc(sizeof(t_lvl2));
	ret->vv1 = 0;
	ret->vv2 = 0;
	ret->vv3 = 0;
	ret->zz1 = 0;
	ret->zz2 = 0;
	ret->zz3 = 0;
	ret->count = 0;
	ret->a_vv1 = awl_vv1(tab);
	ret->a_vv2 = awl_vv2(tab);
	ret->a_vv3 = awl_vv3(tab);
	ret->a_zz1 = awl_zz1(tab);
	ret->a_zz2 = awl_zz2(tab);
	ret->a_zz3 = awl_zz3(tab);
	tab->map = tab->map_lvl2;
	tab->px = 16.5;
	tab->py = 7.5;
	tab->mh = maph(tab->map) - 1;
	tab->mw = ft_strlen(tab->map[0]) - 1;
	return (ret);
}

void	f_shootlvl2(t_main *tab, double px, double py)
{
	if (tab->map[(int)py][(int)px] == '9')
	{
		tab->map[(int)py][(int)px] = 'a';
		tab->lvl2->count++;
	}
	else if (tab->map[(int)py][(int)px] == '8')
	{
		tab->map[(int)py][(int)px] = 'b';
		tab->lvl2->count++;
	}
	else if (tab->map[(int)py][(int)px] == '7')
	{
		tab->map[(int)py][(int)px] = 'c';
		tab->lvl2->count++;
	}
}

void	shootlvl2(t_main *tab)
{
	double px;
	double py;

	px = tab->px;
	py = tab->py;
	while (1)
	{
		if (tab->map[(int)py][(int)px] >= '0' || py < 0 ||
		py > tab->mh || px < 0 || px > tab->mw)
		{
			f_shootlvl2(tab, px, py);
			break ;
		}
		px = px + 0.1 * cos(RAD(tab->pov));
		py = py + 0.1 * sin(RAD(tab->pov));
	}
}

void	f_expose_lvl2(t_main *tab)
{
	tab->lvl2->vv1++;
	tab->lvl2->vv2++;
	tab->lvl2->vv3++;
	tab->lvl2->zz1++;
	tab->lvl2->zz2++;
	tab->lvl2->zz3++;
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
}

void	expose_lvl2(t_main *tab)
{
	if (tab->lvl2 == NULL)
		tab->lvl2 = ini_lvl2(tab);
	tab->image = mlx_new_image(tab->mlx, CW, CH);
	tab->ibuf = mlx_get_data_addr(tab->image, &(tab->icolor),
		&(tab->isize), &(tab->iendian));
	if (tab->lvl2->count == 30)
	{
		tab->map[9][16] = '1';
		tab->map[9][17] = '1';
	}
	wr_map(tab);
	f_expose_lvl2(tab);
	mlx_put_image_to_window(tab->mlx, tab->win, tab->image, 0, 0);
	mlx_string_put(tab->mlx, tab->win, 10, 30, 0xFFFFFF, "GIRL  :");
	mlx_string_put(tab->mlx, tab->win, 70, 30, 0xFFFFFF,
		ft_itoa(tab->lvl2->count));
	mlx_string_put(tab->mlx, tab->win, 90, 30, 0xFFFFFF, "/ 30");
	mlx_destroy_image(tab->mlx, tab->image);
	fps(tab);
	mowing(tab);
}
