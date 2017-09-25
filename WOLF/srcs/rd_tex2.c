/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_tex2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 13:13:39 by vtiterin          #+#    #+#             */
/*   Updated: 2017/01/14 13:13:41 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_tex	**awl_vv1(t_main *tab)
{
	t_tex	**ret;

	ret = (t_tex**)malloc(sizeof(t_tex*) * 18);
	ret[0] = t_r(tab, "./bin/a/vv1/7a1c40fb762847c8c9860f713feaf8ec-0.xpm");
	ret[1] = t_r(tab, "./bin/a/vv1/7a1c40fb762847c8c9860f713feaf8ec-1.xpm");
	ret[2] = t_r(tab, "./bin/a/vv1/7a1c40fb762847c8c9860f713feaf8ec-2.xpm");
	ret[3] = t_r(tab, "./bin/a/vv1/7a1c40fb762847c8c9860f713feaf8ec-3.xpm");
	ret[4] = t_r(tab, "./bin/a/vv1/7a1c40fb762847c8c9860f713feaf8ec-4.xpm");
	ret[5] = t_r(tab, "./bin/a/vv1/7a1c40fb762847c8c9860f713feaf8ec-5.xpm");
	ret[6] = t_r(tab, "./bin/a/vv1/7a1c40fb762847c8c9860f713feaf8ec-6.xpm");
	ret[7] = t_r(tab, "./bin/a/vv1/7a1c40fb762847c8c9860f713feaf8ec-7.xpm");
	ret[8] = t_r(tab, "./bin/a/vv1/7a1c40fb762847c8c9860f713feaf8ec-8.xpm");
	ret[9] = t_r(tab, "./bin/a/vv1/7a1c40fb762847c8c9860f713feaf8ec-9.xpm");
	ret[10] = t_r(tab, "./bin/a/vv1/7a1c40fb762847c8c9860f713feaf8ec-10.xpm");
	ret[11] = t_r(tab, "./bin/a/vv1/7a1c40fb762847c8c9860f713feaf8ec-11.xpm");
	ret[12] = t_r(tab, "./bin/a/vv1/7a1c40fb762847c8c9860f713feaf8ec-12.xpm");
	ret[13] = t_r(tab, "./bin/a/vv1/7a1c40fb762847c8c9860f713feaf8ec-13.xpm");
	ret[14] = t_r(tab, "./bin/a/vv1/7a1c40fb762847c8c9860f713feaf8ec-14.xpm");
	ret[15] = t_r(tab, "./bin/a/vv1/7a1c40fb762847c8c9860f713feaf8ec-15.xpm");
	ret[16] = t_r(tab, "./bin/a/vv1/7a1c40fb762847c8c9860f713feaf8ec-16.xpm");
	ret[17] = t_r(tab, "./bin/a/vv1/7a1c40fb762847c8c9860f713feaf8ec-17.xpm");
	return (ret);
}

t_tex	**awl_vv2(t_main *tab)
{
	t_tex	**ret;

	ret = (t_tex**)malloc(sizeof(t_tex*) * 14);
	ret[0] = t_r(tab, "./bin/a/vv2/eda977ec5f954f8fb227ebf15d8c8c8a-0.xpm");
	ret[1] = t_r(tab, "./bin/a/vv2/eda977ec5f954f8fb227ebf15d8c8c8a-1.xpm");
	ret[2] = t_r(tab, "./bin/a/vv2/eda977ec5f954f8fb227ebf15d8c8c8a-2.xpm");
	ret[3] = t_r(tab, "./bin/a/vv2/eda977ec5f954f8fb227ebf15d8c8c8a-3.xpm");
	ret[4] = t_r(tab, "./bin/a/vv2/eda977ec5f954f8fb227ebf15d8c8c8a-4.xpm");
	ret[5] = t_r(tab, "./bin/a/vv2/eda977ec5f954f8fb227ebf15d8c8c8a-5.xpm");
	ret[6] = t_r(tab, "./bin/a/vv2/eda977ec5f954f8fb227ebf15d8c8c8a-6.xpm");
	ret[7] = t_r(tab, "./bin/a/vv2/eda977ec5f954f8fb227ebf15d8c8c8a-7.xpm");
	ret[8] = t_r(tab, "./bin/a/vv2/eda977ec5f954f8fb227ebf15d8c8c8a-8.xpm");
	ret[9] = t_r(tab, "./bin/a/vv2/eda977ec5f954f8fb227ebf15d8c8c8a-9.xpm");
	ret[10] = t_r(tab, "./bin/a/vv2/eda977ec5f954f8fb227ebf15d8c8c8a-10.xpm");
	ret[11] = t_r(tab, "./bin/a/vv2/eda977ec5f954f8fb227ebf15d8c8c8a-11.xpm");
	ret[12] = t_r(tab, "./bin/a/vv2/eda977ec5f954f8fb227ebf15d8c8c8a-12.xpm");
	ret[13] = t_r(tab, "./bin/a/vv2/eda977ec5f954f8fb227ebf15d8c8c8a-13.xpm");
	return (ret);
}

t_tex	**awl_zz1(t_main *tab)
{
	t_tex	**ret;

	ret = (t_tex**)malloc(sizeof(t_tex*) * 9);
	ret[0] = t_r(tab, "./bin/a/zz1/bcab650063a34d0edc864da3592b8503-0.xpm");
	ret[1] = t_r(tab, "./bin/a/zz1/bcab650063a34d0edc864da3592b8503-1.xpm");
	ret[2] = t_r(tab, "./bin/a/zz1/bcab650063a34d0edc864da3592b8503-2.xpm");
	ret[3] = t_r(tab, "./bin/a/zz1/bcab650063a34d0edc864da3592b8503-3.xpm");
	ret[4] = t_r(tab, "./bin/a/zz1/bcab650063a34d0edc864da3592b8503-4.xpm");
	ret[5] = t_r(tab, "./bin/a/zz1/bcab650063a34d0edc864da3592b8503-5.xpm");
	ret[6] = t_r(tab, "./bin/a/zz1/bcab650063a34d0edc864da3592b8503-6.xpm");
	ret[7] = t_r(tab, "./bin/a/zz1/bcab650063a34d0edc864da3592b8503-7.xpm");
	ret[8] = t_r(tab, "./bin/a/zz1/bcab650063a34d0edc864da3592b8503-8.xpm");
	return (ret);
}

t_tex	**awl_zz2(t_main *tab)
{
	t_tex	**ret;

	ret = (t_tex**)malloc(sizeof(t_tex*) * 15);
	ret[0] = t_r(tab, "./bin/a/zz2/8e73c66694554fe6976b7339c2de4535-0.xpm");
	ret[1] = t_r(tab, "./bin/a/zz2/8e73c66694554fe6976b7339c2de4535-1.xpm");
	ret[2] = t_r(tab, "./bin/a/zz2/8e73c66694554fe6976b7339c2de4535-2.xpm");
	ret[3] = t_r(tab, "./bin/a/zz2/8e73c66694554fe6976b7339c2de4535-3.xpm");
	ret[4] = t_r(tab, "./bin/a/zz2/8e73c66694554fe6976b7339c2de4535-4.xpm");
	ret[5] = t_r(tab, "./bin/a/zz2/8e73c66694554fe6976b7339c2de4535-5.xpm");
	ret[6] = t_r(tab, "./bin/a/zz2/8e73c66694554fe6976b7339c2de4535-6.xpm");
	ret[7] = t_r(tab, "./bin/a/zz2/8e73c66694554fe6976b7339c2de4535-7.xpm");
	ret[8] = t_r(tab, "./bin/a/zz2/8e73c66694554fe6976b7339c2de4535-8.xpm");
	ret[9] = t_r(tab, "./bin/a/zz2/8e73c66694554fe6976b7339c2de4535-9.xpm");
	ret[10] = t_r(tab, "./bin/a/zz2/8e73c66694554fe6976b7339c2de4535-10.xpm");
	ret[11] = t_r(tab, "./bin/a/zz2/8e73c66694554fe6976b7339c2de4535-11.xpm");
	ret[12] = t_r(tab, "./bin/a/zz2/8e73c66694554fe6976b7339c2de4535-12.xpm");
	ret[13] = t_r(tab, "./bin/a/zz2/8e73c66694554fe6976b7339c2de4535-13.xpm");
	ret[14] = t_r(tab, "./bin/a/zz2/8e73c66694554fe6976b7339c2de4535-14.xpm");
	return (ret);
}

t_tex	**awl_zz3(t_main *tab)
{
	t_tex	**ret;

	ret = (t_tex**)malloc(sizeof(t_tex*) * 4);
	ret[0] = t_r(tab, "./bin/a/zz3/a6347cecf8dc4cf2d2c2438c07761ef4-0.xpm");
	ret[1] = t_r(tab, "./bin/a/zz3/a6347cecf8dc4cf2d2c2438c07761ef4-1.xpm");
	ret[2] = t_r(tab, "./bin/a/zz3/a6347cecf8dc4cf2d2c2438c07761ef4-2.xpm");
	ret[3] = t_r(tab, "./bin/a/zz3/a6347cecf8dc4cf2d2c2438c07761ef4-3.xpm");
	return (ret);
}
