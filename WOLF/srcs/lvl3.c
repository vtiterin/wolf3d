/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 19:12:21 by vtiterin          #+#    #+#             */
/*   Updated: 2017/01/14 19:12:23 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wallg_lvl3(t_main *tab)
{
	if (tab->map[tab->gy][(int)tab->g] == '1')
		tab->w = tab->w_arr[14];
	else if (tab->map[tab->gy][(int)tab->g] == '5')
		tab->w = tab->w_arr[15];
	else if (tab->map[tab->gy][(int)tab->g] == '9')
		ch_anim(tab, &tab->lvl3->vv1, 9 * 2, tab->lvl3->a_vv1);
	else if (tab->map[tab->gy][(int)tab->g] == '7')
		ch_anim(tab, &tab->lvl3->vv2, 29 * 2, tab->lvl3->a_vv2);
	else if (tab->map[tab->gy][(int)tab->g] == '8')
		ch_anim(tab, &tab->lvl3->vv3, 22 * 2, tab->lvl3->a_vv3);
	else if (tab->map[tab->gy][(int)tab->g] == '6')
		ch_anim(tab, &tab->lvl3->vv4, 53 * 2, tab->lvl3->a_vv4);
	else if (tab->map[tab->gy][(int)tab->g] == 'a')
		ch_anim(tab, &tab->lvl3->vv5, 50 * 2, tab->lvl3->a_vv5);
	else if (tab->map[tab->gy][(int)tab->g] == 'b')
		ch_anim(tab, &tab->lvl3->vv6, 58 * 2, tab->lvl3->a_vv6);
	else if (tab->map[tab->gy][(int)tab->g] == 'd')
		ch_anim(tab, &tab->lvl3->vv7, 11 * 2, tab->lvl3->a_vv7);
	else if (tab->map[tab->gy][(int)tab->g] == 'e')
		ch_anim(tab, &tab->lvl3->vv8, 31 * 2, tab->lvl3->a_vv8);
}

void	wallv_lvl3(t_main *tab)
{
	if (tab->map[(int)tab->v][tab->vx] == '1')
		tab->w = tab->w_arr[14];
	else if (tab->map[(int)tab->v][tab->vx] == '5')
		tab->w = tab->w_arr[16];
	else if (tab->map[(int)tab->v][tab->vx] == '9')
		ch_anim(tab, &tab->lvl3->vv1, 9 * 2, tab->lvl3->a_vv1);
	else if (tab->map[(int)tab->v][tab->vx] == '7')
		ch_anim(tab, &tab->lvl3->vv2, 29 * 2, tab->lvl3->a_vv2);
	else if (tab->map[(int)tab->v][tab->vx] == '8')
		ch_anim(tab, &tab->lvl3->vv3, 22 * 2, tab->lvl3->a_vv3);
	else if (tab->map[(int)tab->v][tab->vx] == '6')
		ch_anim(tab, &tab->lvl3->vv4, 53 * 2, tab->lvl3->a_vv4);
	else if (tab->map[(int)tab->v][tab->vx] == 'a')
		ch_anim(tab, &tab->lvl3->vv5, 50 * 2, tab->lvl3->a_vv5);
	else if (tab->map[(int)tab->v][tab->vx] == 'b')
		ch_anim(tab, &tab->lvl3->vv6, 58 * 2, tab->lvl3->a_vv6);
	else if (tab->map[(int)tab->v][tab->vx] == 'd')
		ch_anim(tab, &tab->lvl3->vv7, 11 * 2, tab->lvl3->a_vv7);
	else if (tab->map[(int)tab->v][tab->vx] == 'e')
		ch_anim(tab, &tab->lvl3->vv8, 31 * 2, tab->lvl3->a_vv8);
}

t_lvl3	*ini_lvl3(t_main *tab)
{
	t_lvl3	*ret;

	ret = (t_lvl3*)malloc(sizeof(t_lvl3));
	ret->vv1 = 0;
	ret->vv2 = 0;
	ret->vv3 = 0;
	ret->vv4 = 0;
	ret->vv5 = 0;
	ret->vv6 = 0;
	ret->vv7 = 0;
	ret->vv8 = 0;
	ret->a_vv1 = awl_q1(tab);
	ret->a_vv2 = awl_q2(tab);
	ret->a_vv3 = awl_q3(tab);
	ret->a_vv4 = awl_q4(tab);
	ret->a_vv5 = awl_q5(tab);
	ret->a_vv6 = awl_q6(tab);
	ret->a_vv7 = awl_q7(tab);
	ret->a_vv8 = awl_q8(tab);
	tab->px = 7.5;
	tab->py = 1.5;
	tab->map = tab->map_lvl3;
	tab->mh = maph(tab->map) - 1;
	tab->mw = ft_strlen(tab->map[0]) - 1;
	return (ret);
}

void	f_expose_lvl3(t_main *tab)
{
	tab->lvl3->vv1++;
	tab->lvl3->vv2++;
	tab->lvl3->vv3++;
	tab->lvl3->vv4++;
	tab->lvl3->vv5++;
	tab->lvl3->vv6++;
	tab->lvl3->vv7++;
	tab->lvl3->vv8++;
}

void	expose_lvl3(t_main *tab)
{
	if (tab->lvl3 == NULL)
		tab->lvl3 = ini_lvl3(tab);
	tab->image = mlx_new_image(tab->mlx, CW, CH);
	tab->ibuf = mlx_get_data_addr(tab->image, &(tab->icolor),
		&(tab->isize), &(tab->iendian));
	wr_map(tab);
	f_expose_lvl3(tab);
	mlx_put_image_to_window(tab->mlx, tab->win, tab->image, 0, 0);
	mlx_destroy_image(tab->mlx, tab->image);
	fps(tab);
	mowing(tab);
}
