/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_tex1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 13:09:38 by vtiterin          #+#    #+#             */
/*   Updated: 2017/01/14 13:09:40 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_tex	**awl_vv3(t_main *tab)
{
	t_tex	**ret;

	ret = (t_tex**)malloc(sizeof(t_tex*) * 17);
	ret[0] = t_r(tab, "./bin/a/vv3/2fc5a2dd90d44e0bd8ec493e15fc711f-0.xpm");
	ret[1] = t_r(tab, "./bin/a/vv3/2fc5a2dd90d44e0bd8ec493e15fc711f-1.xpm");
	ret[2] = t_r(tab, "./bin/a/vv3/2fc5a2dd90d44e0bd8ec493e15fc711f-2.xpm");
	ret[3] = t_r(tab, "./bin/a/vv3/2fc5a2dd90d44e0bd8ec493e15fc711f-3.xpm");
	ret[4] = t_r(tab, "./bin/a/vv3/2fc5a2dd90d44e0bd8ec493e15fc711f-4.xpm");
	ret[5] = t_r(tab, "./bin/a/vv3/2fc5a2dd90d44e0bd8ec493e15fc711f-5.xpm");
	ret[6] = t_r(tab, "./bin/a/vv3/2fc5a2dd90d44e0bd8ec493e15fc711f-6.xpm");
	ret[7] = t_r(tab, "./bin/a/vv3/2fc5a2dd90d44e0bd8ec493e15fc711f-7.xpm");
	ret[8] = t_r(tab, "./bin/a/vv3/2fc5a2dd90d44e0bd8ec493e15fc711f-8.xpm");
	ret[9] = t_r(tab, "./bin/a/vv3/2fc5a2dd90d44e0bd8ec493e15fc711f-9.xpm");
	ret[10] = t_r(tab, "./bin/a/vv3/2fc5a2dd90d44e0bd8ec493e15fc711f-10.xpm");
	ret[11] = t_r(tab, "./bin/a/vv3/2fc5a2dd90d44e0bd8ec493e15fc711f-11.xpm");
	ret[12] = t_r(tab, "./bin/a/vv3/2fc5a2dd90d44e0bd8ec493e15fc711f-12.xpm");
	ret[13] = t_r(tab, "./bin/a/vv3/2fc5a2dd90d44e0bd8ec493e15fc711f-13.xpm");
	ret[14] = t_r(tab, "./bin/a/vv3/2fc5a2dd90d44e0bd8ec493e15fc711f-14.xpm");
	ret[15] = t_r(tab, "./bin/a/vv3/2fc5a2dd90d44e0bd8ec493e15fc711f-15.xpm");
	ret[16] = t_r(tab, "./bin/a/vv3/2fc5a2dd90d44e0bd8ec493e15fc711f-16.xpm");
	return (ret);
}
