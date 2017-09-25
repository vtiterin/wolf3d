/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_tc2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 18:51:55 by vtiterin          #+#    #+#             */
/*   Updated: 2017/01/14 18:51:56 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_tex	**awl_q1(t_main *tab)
{
	t_tex	**ret;

	ret = (t_tex**)malloc(sizeof(t_tex*) * 9);
	ret[0] = t_r(tab, "./bin/q/1/993a2212c9a94f8b94efa70f55a63df0-0.xpm");
	ret[1] = t_r(tab, "./bin/q/1/993a2212c9a94f8b94efa70f55a63df0-1.xpm");
	ret[2] = t_r(tab, "./bin/q/1/993a2212c9a94f8b94efa70f55a63df0-2.xpm");
	ret[3] = t_r(tab, "./bin/q/1/993a2212c9a94f8b94efa70f55a63df0-3.xpm");
	ret[4] = t_r(tab, "./bin/q/1/993a2212c9a94f8b94efa70f55a63df0-4.xpm");
	ret[5] = t_r(tab, "./bin/q/1/993a2212c9a94f8b94efa70f55a63df0-5.xpm");
	ret[6] = t_r(tab, "./bin/q/1/993a2212c9a94f8b94efa70f55a63df0-6.xpm");
	ret[7] = t_r(tab, "./bin/q/1/993a2212c9a94f8b94efa70f55a63df0-7.xpm");
	ret[8] = t_r(tab, "./bin/q/1/993a2212c9a94f8b94efa70f55a63df0-8.xpm");
	return (ret);
}

void	f_awl_q2(t_main *tab, t_tex **ret)
{
	ret[20] = t_r(tab, "./bin/q/2/442d757e9d1b44b0f2ac136545b10030-20.xpm");
	ret[21] = t_r(tab, "./bin/q/2/442d757e9d1b44b0f2ac136545b10030-21.xpm");
	ret[22] = t_r(tab, "./bin/q/2/442d757e9d1b44b0f2ac136545b10030-22.xpm");
	ret[23] = t_r(tab, "./bin/q/2/442d757e9d1b44b0f2ac136545b10030-23.xpm");
	ret[24] = t_r(tab, "./bin/q/2/442d757e9d1b44b0f2ac136545b10030-24.xpm");
	ret[25] = t_r(tab, "./bin/q/2/442d757e9d1b44b0f2ac136545b10030-25.xpm");
	ret[26] = t_r(tab, "./bin/q/2/442d757e9d1b44b0f2ac136545b10030-26.xpm");
	ret[27] = t_r(tab, "./bin/q/2/442d757e9d1b44b0f2ac136545b10030-27.xpm");
	ret[28] = t_r(tab, "./bin/q/2/442d757e9d1b44b0f2ac136545b10030-28.xpm");
}

t_tex	**awl_q2(t_main *tab)
{
	t_tex	**ret;

	ret = (t_tex**)malloc(sizeof(t_tex*) * 29);
	ret[0] = t_r(tab, "./bin/q/2/442d757e9d1b44b0f2ac136545b10030-0.xpm");
	ret[1] = t_r(tab, "./bin/q/2/442d757e9d1b44b0f2ac136545b10030-1.xpm");
	ret[2] = t_r(tab, "./bin/q/2/442d757e9d1b44b0f2ac136545b10030-2.xpm");
	ret[3] = t_r(tab, "./bin/q/2/442d757e9d1b44b0f2ac136545b10030-3.xpm");
	ret[4] = t_r(tab, "./bin/q/2/442d757e9d1b44b0f2ac136545b10030-4.xpm");
	ret[5] = t_r(tab, "./bin/q/2/442d757e9d1b44b0f2ac136545b10030-5.xpm");
	ret[6] = t_r(tab, "./bin/q/2/442d757e9d1b44b0f2ac136545b10030-6.xpm");
	ret[7] = t_r(tab, "./bin/q/2/442d757e9d1b44b0f2ac136545b10030-7.xpm");
	ret[8] = t_r(tab, "./bin/q/2/442d757e9d1b44b0f2ac136545b10030-8.xpm");
	ret[9] = t_r(tab, "./bin/q/2/442d757e9d1b44b0f2ac136545b10030-9.xpm");
	ret[10] = t_r(tab, "./bin/q/2/442d757e9d1b44b0f2ac136545b10030-10.xpm");
	ret[11] = t_r(tab, "./bin/q/2/442d757e9d1b44b0f2ac136545b10030-11.xpm");
	ret[12] = t_r(tab, "./bin/q/2/442d757e9d1b44b0f2ac136545b10030-12.xpm");
	ret[13] = t_r(tab, "./bin/q/2/442d757e9d1b44b0f2ac136545b10030-13.xpm");
	ret[14] = t_r(tab, "./bin/q/2/442d757e9d1b44b0f2ac136545b10030-14.xpm");
	ret[15] = t_r(tab, "./bin/q/2/442d757e9d1b44b0f2ac136545b10030-15.xpm");
	ret[16] = t_r(tab, "./bin/q/2/442d757e9d1b44b0f2ac136545b10030-16.xpm");
	ret[17] = t_r(tab, "./bin/q/2/442d757e9d1b44b0f2ac136545b10030-17.xpm");
	ret[18] = t_r(tab, "./bin/q/2/442d757e9d1b44b0f2ac136545b10030-18.xpm");
	ret[19] = t_r(tab, "./bin/q/2/442d757e9d1b44b0f2ac136545b10030-19.xpm");
	f_awl_q2(tab, ret);
	return (ret);
}

void	f_awl_q3(t_main *tab, t_tex **ret)
{
	ret[14] = t_r(tab, "./bin/q/3/98f461354f5542daa5f683bee978afa3-14.xpm");
	ret[15] = t_r(tab, "./bin/q/3/98f461354f5542daa5f683bee978afa3-15.xpm");
	ret[16] = t_r(tab, "./bin/q/3/98f461354f5542daa5f683bee978afa3-16.xpm");
	ret[17] = t_r(tab, "./bin/q/3/98f461354f5542daa5f683bee978afa3-17.xpm");
	ret[18] = t_r(tab, "./bin/q/3/98f461354f5542daa5f683bee978afa3-18.xpm");
	ret[19] = t_r(tab, "./bin/q/3/98f461354f5542daa5f683bee978afa3-19.xpm");
	ret[20] = t_r(tab, "./bin/q/3/98f461354f5542daa5f683bee978afa3-20.xpm");
	ret[21] = t_r(tab, "./bin/q/3/98f461354f5542daa5f683bee978afa3-21.xpm");
}

t_tex	**awl_q3(t_main *tab)
{
	t_tex	**ret;

	ret = (t_tex**)malloc(sizeof(t_tex*) * 22);
	ret[0] = t_r(tab, "./bin/q/3/98f461354f5542daa5f683bee978afa3-0.xpm");
	ret[1] = t_r(tab, "./bin/q/3/98f461354f5542daa5f683bee978afa3-1.xpm");
	ret[2] = t_r(tab, "./bin/q/3/98f461354f5542daa5f683bee978afa3-2.xpm");
	ret[3] = t_r(tab, "./bin/q/3/98f461354f5542daa5f683bee978afa3-3.xpm");
	ret[4] = t_r(tab, "./bin/q/3/98f461354f5542daa5f683bee978afa3-4.xpm");
	ret[5] = t_r(tab, "./bin/q/3/98f461354f5542daa5f683bee978afa3-5.xpm");
	ret[6] = t_r(tab, "./bin/q/3/98f461354f5542daa5f683bee978afa3-6.xpm");
	ret[7] = t_r(tab, "./bin/q/3/98f461354f5542daa5f683bee978afa3-7.xpm");
	ret[8] = t_r(tab, "./bin/q/3/98f461354f5542daa5f683bee978afa3-8.xpm");
	ret[9] = t_r(tab, "./bin/q/3/98f461354f5542daa5f683bee978afa3-9.xpm");
	ret[10] = t_r(tab, "./bin/q/3/98f461354f5542daa5f683bee978afa3-10.xpm");
	ret[11] = t_r(tab, "./bin/q/3/98f461354f5542daa5f683bee978afa3-11.xpm");
	ret[12] = t_r(tab, "./bin/q/3/98f461354f5542daa5f683bee978afa3-12.xpm");
	ret[13] = t_r(tab, "./bin/q/3/98f461354f5542daa5f683bee978afa3-13.xpm");
	f_awl_q3(tab, ret);
	return (ret);
}
