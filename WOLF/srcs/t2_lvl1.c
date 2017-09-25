/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t2_lvl1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:13:22 by vtiterin          #+#    #+#             */
/*   Updated: 2017/01/12 11:13:24 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wallg_lvl1(t_main *tab)
{
	if (tab->map[tab->gy][(int)tab->g] == '5')
		tab->w = tab->w_arr[2];
	else if (tab->map[tab->gy][(int)tab->g] == 'a')
		tab->w = tab->w_arr[3];
	else if (tab->map[tab->gy][(int)tab->g] == '7')
		tab->w = tab->w_arr[4];
	else if (tab->map[tab->gy][(int)tab->g] == 'b')
		tab->w = tab->w_arr[5];
	else if (tab->map[tab->gy][(int)tab->g] == '1')
		tab->w = tab->w_arr[10];
	else if (tab->map[tab->gy][(int)tab->g] == '2')
		tab->w = tab->w_arr[11];
	else if (tab->map[tab->gy][(int)tab->g] == '3')
		tab->w = tab->w_arr[12];
	else if (tab->map[tab->gy][(int)tab->g] == '6')
		tab->w = tab->w_arr[7];
	else if (tab->map[tab->gy][(int)tab->g] == 'c')
		tab->w = tab->w_arr[6];
	else if (tab->map[tab->gy][(int)tab->g] == '8')
		tab->w = tab->w_arr[9];
	else if (tab->map[tab->gy][(int)tab->g] == 'd')
		tab->w = tab->w_arr[8];
}

void	wallv_lvl1(t_main *tab)
{
	if (tab->map[(int)tab->v][tab->vx] == '5')
		tab->w = tab->w_arr[2];
	else if (tab->map[(int)tab->v][tab->vx] == 'a')
		tab->w = tab->w_arr[3];
	else if (tab->map[(int)tab->v][tab->vx] == '7')
		tab->w = tab->w_arr[4];
	else if (tab->map[(int)tab->v][tab->vx] == 'b')
		tab->w = tab->w_arr[5];
	else if (tab->map[(int)tab->v][tab->vx] == '1')
		tab->w = tab->w_arr[10];
	else if (tab->map[(int)tab->v][tab->vx] == '2')
		tab->w = tab->w_arr[11];
	else if (tab->map[(int)tab->v][tab->vx] == '3')
		tab->w = tab->w_arr[12];
	else if (tab->map[(int)tab->v][tab->vx] == '6')
		tab->w = tab->w_arr[7];
	else if (tab->map[(int)tab->v][tab->vx] == 'c')
		tab->w = tab->w_arr[6];
	else if (tab->map[(int)tab->v][tab->vx] == '8')
		tab->w = tab->w_arr[9];
	else if (tab->map[(int)tab->v][tab->vx] == 'd')
		tab->w = tab->w_arr[8];
}
