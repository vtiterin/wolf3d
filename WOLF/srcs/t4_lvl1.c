/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t4_lvl1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 16:04:36 by vtiterin          #+#    #+#             */
/*   Updated: 2017/01/14 16:04:38 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	floor_lvl2(t_main *tab, double x, double y)
{
	if (tab->map[(int)y][(int)x] == '+')
		tab->f = tab->w_arr[20];
	else if (tab->map[(int)y][(int)x] == '-')
		tab->f = tab->w_arr[21];
	else
		tab->f = tab->w_arr[19];
}
