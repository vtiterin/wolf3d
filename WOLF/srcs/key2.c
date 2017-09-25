/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 14:38:57 by vtiterin          #+#    #+#             */
/*   Updated: 2017/01/14 14:38:58 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	my_key_func(int keycode, t_main *tab, int i)
{
	if (keycode == 123)
		tab->left = i;
	if (keycode == 124)
		tab->right = i;
	if (keycode == 126 || keycode == 13)
		tab->up = i;
	if (keycode == 125 || keycode == 1)
		tab->down = i;
	if (keycode == 0)
		tab->str_l = i;
	if (keycode == 2)
		tab->str_r = i;
}

void	for_lvl2(t_main *tab)
{
	if ((int)tab->px == 6 && (int)tab->py == 17 && tab->map[17][7] == '8')
	{
		tab->map[17][7] = 'd';
		tab->cons++;
	}
	if ((int)tab->px == 1 && (int)tab->py == 14 && tab->map[14][2] == '8')
	{
		tab->map[14][2] = 'd';
		tab->cons++;
	}
	if ((int)tab->px == 20 && (int)tab->py == 12 && tab->map[12][19] == '8')
	{
		tab->map[12][19] = 'd';
		tab->cons++;
	}
	if ((int)tab->px == 19 && (int)tab->py == 16 && tab->map[16][20] == '8')
	{
		tab->map[16][20] = 'd';
		tab->cons++;
	}
	if ((int)tab->px == 31 && (int)tab->py == 13 && tab->map[14][31] == '8')
	{
		tab->map[14][31] = 'd';
		tab->cons++;
	}
}

void	lvl_up(t_main *tab)
{
	if (tab->lvl == 3)
	{
		if ((int)tab->px == 24 && (int)tab->py == 11)
			tab->lvl++;
	}
	else if (tab->lvl == 5)
	{
		if (((int)tab->px == 12 && (int)tab->py == 16
			&& tab->map[17][12] == 'c') ||
			((int)tab->px == 13 && (int)tab->py == 16
			&& tab->map[17][13] == 'c') ||
			((int)tab->px == 14 && (int)tab->py == 16
			&& tab->map[17][14] == 'c'))
			tab->lvl++;
		for_lvl2(tab);
	}
}

int		key_hook_p(int keycode, t_main *tab)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 48)
		tab->lvl = 1;
	else if (keycode == 49)
	{
		if (tab->lvl == 5)
			shootlvl1(tab);
		if (tab->lvl == 7)
			shootlvl2(tab);
		tab->wp_b++;
	}
	else if (keycode == 14)
		lvl_up(tab);
	else
		my_key_func(keycode, tab, 1);
	return (0);
}

int		key_hook_r(int keycode, t_main *tab)
{
	my_key_func(keycode, tab, 0);
	return (0);
}
