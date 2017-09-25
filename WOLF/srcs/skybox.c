/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 11:20:38 by vtiterin          #+#    #+#             */
/*   Updated: 2017/01/06 11:20:40 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ini_sky(t_main *tab, t_sky *sk, int sky)
{
	sk->xm_ini = (double)tab->r_arr[sky]->ww / 360;
	sk->ym_ini = tab->r_arr[sky]->wh / (CH / 2.0);
	sk->wh_y = CH / 2;
	sk->x = CW;
}

void	ft_win_sky(t_main *tab, int sky, double angl)
{
	t_sky	*sk;

	sk = (t_sky*)malloc(sizeof(t_sky));
	ini_sky(tab, sk, sky);
	angl = true_angl(angl);
	sk->xm = sk->xm_ini * angl;
	while (--sk->x > 0)
	{
		angl = true_angl(angl);
		sk->y = -1;
		sk->ym = 0;
		while (++sk->y < sk->wh_y)
		{
			ft_memcpy(&tab->ibuf[sk->x * 4 + (sk->y * tab->isize)],
			&tab->r_arr[sky]->wbuf[(int)sk->xm * 4 + (int)sk->ym *
			tab->r_arr[sky]->wsize], 4);
			sk->ym += sk->ym_ini;
		}
		angl += tab->ugl;
		sk->xm = sk->xm_ini * angl;
	}
	free(sk);
}

void	wr_wepon(t_main *tab, int wp)
{
	int		x;
	int		y;
	double	ym;
	double	xm;

	tab->st_xm = (double)tab->wp_arr[wp]->ww / (CW / 2);
	tab->st_ym = (double)tab->wp_arr[wp]->wh / (CH / 2 + 100);
	x = CW / 2 - 1;
	xm = 0.0;
	while (++x < CW)
	{
		y = CH / 2 + 100 - 1;
		ym = 0.0;
		while (++y < CH)
		{
			if (tab->wp_arr[wp]->wbuf[((int)xm * 4) +
			(int)ym * tab->wp_arr[wp]->wsize] != 0x000000)
				ft_memcpy(&tab->ibuf[x * 4 + (y * tab->isize)],
				&tab->wp_arr[wp]->wbuf[((int)xm * 4) + (int)ym *
				tab->wp_arr[wp]->wsize], 4);
			ym += tab->st_ym;
		}
		xm += tab->st_xm;
	}
}

void	wr_mask(t_main *tab, int wp)
{
	int		x;
	int		y;
	double	ym;
	double	xm;

	tab->st_xm = (double)tab->r_arr[wp]->ww / (CW);
	tab->st_ym = (double)tab->r_arr[wp]->wh / (CH);
	x = -1;
	xm = 0.0;
	while (++x < CW)
	{
		y = -1;
		ym = 0.0;
		while (++y < CH)
		{
			if (tab->r_arr[wp]->wbuf[((int)xm * 4) +
			(int)ym * tab->r_arr[wp]->wsize] != 0x000000)
				ft_memcpy(&tab->ibuf[x * 4 + (y * tab->isize)],
				&tab->r_arr[wp]->wbuf[((int)xm * 4) +
				(int)ym * tab->r_arr[wp]->wsize], 4);
			ym += tab->st_ym;
		}
		xm += tab->st_xm;
	}
}

void	wr_menu(t_main *tab, int wp)
{
	int		x;
	int		y;
	double	ym;
	double	xm;

	tab->st_xm = (double)tab->r_arr[wp]->ww / (CW);
	tab->st_ym = (double)tab->r_arr[wp]->wh / (CH);
	x = -1;
	xm = 0.0;
	while (++x < CW)
	{
		y = -1;
		ym = 0.0;
		while (++y < CH)
		{
			ft_memcpy(&tab->ibuf[x * 4 + (y * tab->isize)],
			&tab->r_arr[wp]->wbuf[((int)xm * 4) + (int)ym *
			tab->r_arr[wp]->wsize], 4);
			ym += tab->st_ym;
		}
		xm += tab->st_xm;
	}
	mlx_put_image_to_window(tab->mlx, tab->win, tab->image, 0, 0);
	mlx_destroy_image(tab->mlx, tab->image);
}
