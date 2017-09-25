/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_tex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 11:21:55 by vtiterin          #+#    #+#             */
/*   Updated: 2017/01/06 11:21:58 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_tex	*t_r(t_main *tab, char *file)
{
	t_tex	*ret;

	ret = (t_tex*)malloc(sizeof(t_tex));
	ret->wall = mlx_xpm_file_to_image(tab->mlx, file, &ret->ww, &ret->wh);
	ret->wbuf = mlx_get_data_addr(ret->wall, &(ret->wcolor),
		&(ret->wsize), &(ret->wendian));
	return (ret);
}

t_tex	**sky_arr(t_main *tab)
{
	t_tex	**ret;

	ret = (t_tex**)malloc(sizeof(t_tex*) * 12);
	ret[0] = t_r(tab, "./bin/skybox/sk_snow1.xpm");
	ret[1] = t_r(tab, "./bin/skybox/sky_cosm2.xpm");
	ret[2] = t_r(tab, "./bin/skybox/sky_spiral.xpm");
	ret[3] = t_r(tab, "./bin/skybox/sky_dom.xpm");
	ret[4] = t_r(tab, "./bin/skybox/sky_wood.xpm");
	ret[5] = t_r(tab, "./bin/lvl/mask.xpm");
	ret[6] = t_r(tab, "./bin/lvl/wasted.xpm");
	ret[7] = t_r(tab, "./bin/lvl/menu.xpm");
	ret[8] = t_r(tab, "./bin/lvl/menu_2.xpm");
	ret[9] = t_r(tab, "./bin/lvl/w_0.xpm");
	ret[10] = t_r(tab, "./bin/lvl/w_1.xpm");
	ret[11] = t_r(tab, "./bin/skybox/p.xpm");
	return (ret);
}

void	sky_wall2(t_main *tab, t_tex **ret)
{
	ret[16] = t_r(tab, "./bin/wall/w4.xpm");
	ret[17] = t_r(tab, "./bin/wall/w5.xpm");
	ret[18] = t_r(tab, "./bin/wall/final.xpm");
	ret[19] = t_r(tab, "./bin/floor/gras.xpm");
	ret[20] = t_r(tab, "./bin/floor/snow.xpm");
	ret[21] = t_r(tab, "./bin/floor/sand.xpm");
	ret[22] = t_r(tab, "./bin/wall/dor_on.xpm");
	ret[23] = t_r(tab, "./bin/wall/dor_off.xpm");
}

t_tex	**sky_wall(t_main *tab)
{
	t_tex	**ret;

	ret = (t_tex**)malloc(sizeof(t_tex*) * 24);
	ret[0] = t_r(tab, "./bin/floor/lvl1_1.xpm");
	ret[1] = t_r(tab, "./bin/floor/lvl1_2.xpm");
	ret[2] = t_r(tab, "./bin/wall/lvl1_5_1.xpm");
	ret[3] = t_r(tab, "./bin/wall/lvl1_5_2.xpm");
	ret[4] = t_r(tab, "./bin/wall/lvl1_7_1.xpm");
	ret[5] = t_r(tab, "./bin/wall/lvl1_7_2.xpm");
	ret[6] = t_r(tab, "./bin/wall/lvl1_6_on.xpm");
	ret[7] = t_r(tab, "./bin/wall/lvl1_6_off.xpm");
	ret[8] = t_r(tab, "./bin/wall/lvl1_9_on.xpm");
	ret[9] = t_r(tab, "./bin/wall/lvl1_9_off.xpm");
	ret[10] = t_r(tab, "./bin/wall/lvl1_00.xpm");
	ret[11] = t_r(tab, "./bin/wall/lvl1_11.xpm");
	ret[12] = t_r(tab, "./bin/wall/lvl1_22.xpm");
	ret[13] = t_r(tab, "./bin/wall/w1.xpm");
	ret[14] = t_r(tab, "./bin/wall/w2.xpm");
	ret[15] = t_r(tab, "./bin/wall/w3.xpm");
	sky_wall2(tab, ret);
	return (ret);
}

t_tex	**wp_arr(t_main *tab)
{
	t_tex	**ret;

	ret = (t_tex**)malloc(sizeof(t_tex*) * 11);
	ret[0] = t_r(tab, "./bin/wp/0.xpm");
	ret[1] = t_r(tab, "./bin/wp/1.xpm");
	ret[2] = t_r(tab, "./bin/wp/2.xpm");
	ret[3] = t_r(tab, "./bin/wp/3.xpm");
	ret[4] = t_r(tab, "./bin/wp/4.xpm");
	ret[5] = t_r(tab, "./bin/wp/5.xpm");
	ret[6] = t_r(tab, "./bin/wp/6.xpm");
	ret[7] = t_r(tab, "./bin/wp/7.xpm");
	ret[8] = t_r(tab, "./bin/wp/8.xpm");
	ret[9] = t_r(tab, "./bin/wp/9.xpm");
	ret[10] = t_r(tab, "./bin/wp/10.xpm");
	return (ret);
}
