/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 14:45:02 by vtiterin          #+#    #+#             */
/*   Updated: 2017/01/02 14:45:05 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		close_hook(t_main *tab)
{
	exit(0);
	return (0);
}

int		main(void)
{
	t_main *tab;

	if (!(tab = (t_main*)malloc(sizeof(t_main))))
		return (1);
	ft_ini(tab);
	mlx_mouse_hook(tab->win, mouse_hook, tab);
	mlx_hook(tab->win, 6, 6, motion_hook, tab);
	mlx_hook(tab->win, 2, 0, key_hook_p, tab);
	mlx_hook(tab->win, 3, 1, key_hook_r, tab);
	mlx_hook(tab->win, 17, 0, close_hook, tab);
	mlx_loop_hook(tab->mlx, expose_hook, tab);
	mlx_loop(tab->mlx);
	return (0);
}
