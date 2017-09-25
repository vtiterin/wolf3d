/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t3_lvl1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 15:55:39 by vtiterin          #+#    #+#             */
/*   Updated: 2017/01/14 15:55:53 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ch_anim(t_main *tab, int *i, int len, t_tex **anim)
{
	if (*i >= len)
		*i = 0;
	tab->w = anim[(*i) / 2];
}

void	wallg_lvl2_2(t_main *tab)
{
	if (tab->map[tab->gy][(int)tab->g] == '9')
		ch_anim(tab, &tab->lvl2->vv1, 18 * 2, tab->lvl2->a_vv1);
	else if (tab->map[tab->gy][(int)tab->g] == '7')
		ch_anim(tab, &tab->lvl2->vv3, 17 * 2, tab->lvl2->a_vv3);
	else if (tab->map[tab->gy][(int)tab->g] == '8')
		ch_anim(tab, &tab->lvl2->vv2, 14 * 2, tab->lvl2->a_vv2);
	else if (tab->map[tab->gy][(int)tab->g] == 'a')
		ch_anim(tab, &tab->lvl2->zz1, 9 * 2, tab->lvl2->a_zz1);
	else if (tab->map[tab->gy][(int)tab->g] == 'b')
		ch_anim(tab, &tab->lvl2->zz3, 4 * 2, tab->lvl2->a_zz3);
	else if (tab->map[tab->gy][(int)tab->g] == 'c')
		ch_anim(tab, &tab->lvl2->zz2, 15 * 2, tab->lvl2->a_zz2);
}

void	wallg_lvl2(t_main *tab)
{
	if (tab->map[tab->gy][(int)tab->g] == 'z')
		tab->w = tab->w_arr[13];
	else if (tab->map[tab->gy][(int)tab->g] == 'x')
		tab->w = tab->w_arr[14];
	else if (tab->map[tab->gy][(int)tab->g] == 'y')
		tab->w = tab->w_arr[15];
	else if (tab->map[tab->gy][(int)tab->g] == 'w')
		tab->w = tab->w_arr[16];
	else if (tab->map[tab->gy][(int)tab->g] == 'v')
		tab->w = tab->w_arr[17];
	else if (tab->map[tab->gy][(int)tab->g] == '6')
		tab->w = tab->w_arr[18];
	else if (tab->map[tab->gy][(int)tab->g] == '1')
		tab->w = tab->w_arr[22];
	else if (tab->map[tab->gy][(int)tab->g] == 'g')
		tab->w = tab->w_arr[23];
	else
		wallg_lvl2_2(tab);
}

void	wallv_lvl2_2(t_main *tab)
{
	if (tab->map[(int)tab->v][tab->vx] == '9')
		ch_anim(tab, &tab->lvl2->vv1, 18 * 2, tab->lvl2->a_vv1);
	else if (tab->map[(int)tab->v][tab->vx] == '7')
		ch_anim(tab, &tab->lvl2->vv3, 17 * 2, tab->lvl2->a_vv3);
	else if (tab->map[(int)tab->v][tab->vx] == '8')
		ch_anim(tab, &tab->lvl2->vv2, 14 * 2, tab->lvl2->a_vv2);
	else if (tab->map[(int)tab->v][tab->vx] == 'a')
		ch_anim(tab, &tab->lvl2->zz1, 9 * 2, tab->lvl2->a_zz1);
	else if (tab->map[(int)tab->v][tab->vx] == 'b')
		ch_anim(tab, &tab->lvl2->zz3, 4 * 2, tab->lvl2->a_zz3);
	else if (tab->map[(int)tab->v][tab->vx] == 'c')
		ch_anim(tab, &tab->lvl2->zz2, 15 * 2, tab->lvl2->a_zz2);
}

void	wallv_lvl2(t_main *tab)
{
	if (tab->map[(int)tab->v][tab->vx] == 'z' ||
	tab->map[(int)tab->v][tab->vx] == '2' ||
	tab->map[(int)tab->v][tab->vx] == '3')
		tab->w = tab->w_arr[13];
	else if (tab->map[(int)tab->v][tab->vx] == 'x')
		tab->w = tab->w_arr[14];
	else if (tab->map[(int)tab->v][tab->vx] == 'y')
		tab->w = tab->w_arr[15];
	else if (tab->map[(int)tab->v][tab->vx] == 'w')
		tab->w = tab->w_arr[16];
	else if (tab->map[(int)tab->v][tab->vx] == 'v')
		tab->w = tab->w_arr[17];
	else if (tab->map[(int)tab->v][tab->vx] == '6')
		tab->w = tab->w_arr[18];
	else if (tab->map[(int)tab->v][tab->vx] == '1')
		tab->w = tab->w_arr[22];
	else if (tab->map[(int)tab->v][tab->vx] == 'g')
		tab->w = tab->w_arr[23];
	else
		wallv_lvl2_2(tab);
}
