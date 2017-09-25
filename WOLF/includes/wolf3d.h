/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 16:11:00 by vtiterin          #+#    #+#             */
/*   Updated: 2017/01/14 16:11:03 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <time.h>
# define D_MAX 9999.0
# define CH 1024
# define CW 1280
# define RAD(x) ((x) > 0 ? (x) * M_PI / 180 : 0)
# define ABS(x) ((x) < 0 ? -(x) : (x))

typedef struct		s_tex
{
	void			*wall;
	char			*wbuf;
	int				wsize;
	int				wcolor;
	int				wendian;
	int				ww;
	int				wh;
}					t_tex;

typedef struct		s_lvl0
{
	int				c_wall;
	int				c_flor;
	int				c_cel;
	int				ist;
}					t_lvl0;

typedef struct		s_lvl2
{
	int				vv1;
	int				vv2;
	int				vv3;
	int				zz1;
	int				zz2;
	int				zz3;
	t_tex			**a_vv1;
	t_tex			**a_vv2;
	t_tex			**a_vv3;
	t_tex			**a_zz1;
	t_tex			**a_zz2;
	t_tex			**a_zz3;
	int				count;
}					t_lvl2;

typedef struct		s_lvl3
{
	int				vv1;
	int				vv2;
	int				vv3;
	int				vv4;
	int				vv5;
	int				vv6;
	int				vv7;
	int				vv8;
	t_tex			**a_vv1;
	t_tex			**a_vv2;
	t_tex			**a_vv3;
	t_tex			**a_vv4;
	t_tex			**a_vv5;
	t_tex			**a_vv6;
	t_tex			**a_vv7;
	t_tex			**a_vv8;
}					t_lvl3;

typedef struct		s_spr
{
	double			x;
	double			y;
	int				txt;
	double			dst;
}					t_spr;

typedef struct		s_sky
{
	double			xm_ini;
	double			ym_ini;
	int				wh_y;
	int				x;
	int				y;
	double			ym;
	double			xm;
}					t_sky;

typedef struct		s_main
{
	int				fps;
	int				fps2;
	int				time;
	t_lvl0			*lvl0;
	t_lvl2			*lvl2;
	t_lvl3			*lvl3;
	int				lvl;
	char			**map_lvl0;
	char			**map_lvl1;
	char			**map_lvl2;
	char			**map_lvl3;
	int				mask;
	int				z_pov;
	double			hp;
	int				cons;
	int				ini_l1;
	double			fov;
	double			ugl;
	int				up;
	int				left;
	int				right;
	int				down;
	int				str_l;
	int				str_r;
	void			*win;
	void			*mlx;
	void			*image;
	char			*ibuf;
	int				isize;
	int				icolor;
	int				iendian;
	char			**map;
	int				mw;
	int				mh;
	double			px;
	double			py;
	double			pov;
	void			*wall;
	char			*wbuf;
	int				wsize;
	int				wcolor;
	int				wendian;
	int				ww;
	int				wh;
	int				i_img;
	double			i_imgd;
	double			g;
	double			v;
	int				gy;
	int				vx;
	t_tex			**w_arr;
	t_tex			**f_arr;
	t_tex			**r_arr;
	t_tex			*w;
	t_tex			*f;
	int				tmpx;
	double			fxwg;
	double			fywg;
	double			fxwv;
	double			fywv;
	double			fxwm;
	double			fywm;
	int				wp_b;
	t_tex			**wp_arr;
	int				wp;
	t_tex			**awl_arr;
	int				awl;
	double			st_xm;
	double			st_ym;
}					t_main;

typedef struct		s_ray
{
	double			ddist;
	double			cosa;
	double			tana;
	double			sina;
	double			d_gor;
	double			d_vert;
	int				dx;
	int				dy;
	double			ddx;
	double			ddy;
	int				wall;
	int				roof;
	double			angle;
	int				x;
	int				h;
}					t_ray;

int					maph(char **map);
int					close_hook(t_main *tab);
void				ft_im_up(t_main *tab);
void				ft_im_down(t_main *tab);
int					r(double f);
void				ft_im_left(t_main *tab);
void				ft_im_right(t_main *tab);
void				ft_strafe_l(t_main *tab);
void				ft_strafe_r(t_main *tab);
double				true_angl(double angl);
void				ini_sky(t_main *tab, t_sky *sk, int sky);
void				ft_win_sky(t_main *tab, int sky, double angl);
void				wr_wepon(t_main *tab, int wp);
void				wr_mask(t_main *tab, int wp);
void				wr_menu(t_main *tab, int wp);
double				ray_up(t_main *tab, t_ray *ray);
double				ray_down(t_main *tab, t_ray *ray);
double				gor(t_main *tab, t_ray *ray, double angle);
double				ray_right(t_main *tab, t_ray *ray);
double				ray_left(t_main *tab, t_ray *ray);
double				vert(t_main *tab, t_ray *ray, double angle);
void				ft_up_str(char **buf, int l, char *line);
char				*read_matrix(char *arvg);
char				**cr_map(char *arg);
t_tex				*t_r(t_main *tab, char *file);
t_tex				**sky_arr(t_main *tab);
void				sky_wall2(t_main *tab, t_tex **ret);
t_tex				**sky_wall(t_main *tab);
t_tex				**wp_arr(t_main *tab);
t_tex				**awl_vv3(t_main *tab);
t_tex				**awl_vv1(t_main *tab);
t_tex				**awl_vv2(t_main *tab);
t_tex				**awl_zz1(t_main *tab);
t_tex				**awl_zz2(t_main *tab);
t_tex				**awl_zz3(t_main *tab);
void				wr_map(t_main *tab);
void				ch_draw(t_ray *ray, t_main *tab, int i, double angl);
void				ch_draw_v(t_ray *ray, t_main *tab, int i, double angl);
void				ch_draw_g(t_ray *ray, t_main *tab, int i, double angl);
void				draw(t_ray *ray, t_main *tab, int i);
void				wr_floor(t_ray *ray, t_main *tab, int i, int y);
void				fps(t_main *tab);
void				mowing(t_main *tab);
void				ft_ini(t_main *tab);
void				ft_ini2(t_main *tab);
int					expose_hook(t_main *tab);
int					motion_hook(int x, int y, t_main *tab);
int					mouse_hook(int button, int x, int y, t_main *tab);
int					key_hook_p(int keycode, t_main *tab);
void				my_key_func(int keycode, t_main *tab, int i);
void				lvl_up(t_main *tab);
int					key_hook_r(int keycode, t_main *tab);
void				for_lvl2(t_main *tab);
void				draw_all(t_ray *ray, t_main *tab, int i);
void				f_draw_all(t_ray *ray, t_main *tab, int i);
void				wr_map0(t_main *tab);
void				ch_draw0g(t_ray *ray, t_main *tab, int i, double angl);
void				ch_draw0v(t_ray *ray, t_main *tab, int i, double angl);
void				ch_draw0(t_ray *ray, t_main *tab, int i, double angl);
t_lvl0				*ini_lvl0(t_main *tab);
void				expose_lvl0(t_main *tab);
void				wallg_lvl1(t_main *tab);
void				wallv_lvl1(t_main *tab);
void				floor_lvl1(t_main *tab, double x, double y);
void				ini_lvl1(t_main *tab);
void				shootlvl1(t_main *tab);
void				f_expose_lvl1(t_main *tab);
void				expose_lvl1(t_main *tab);
void				ch_anim(t_main *tab, int *i, int len, t_tex	**anim);
void				wallg_lvl2_2(t_main *tab);
void				wallg_lvl2(t_main *tab);
void				wallv_lvl2_2(t_main *tab);
void				wallv_lvl2(t_main *tab);
void				floor_lvl2(t_main *tab, double x, double y);
t_lvl2				*ini_lvl2(t_main *tab);
void				f_shootlvl2(t_main *tab, double px, double py);
void				shootlvl2(t_main *tab);
void				f_expose_lvl2(t_main *tab);
void				expose_lvl2(t_main *tab);
void				expose_lvl3(t_main *tab);
void				f_expose_lvl3(t_main *tab);
t_lvl3				*ini_lvl3(t_main *tab);
void				wallv_lvl3(t_main *tab);
void				wallg_lvl3(t_main *tab);
t_tex				**awl_q1(t_main *tab);
t_tex				**awl_q2(t_main *tab);
t_tex				**awl_q3(t_main *tab);
t_tex				**awl_q4(t_main *tab);
t_tex				**awl_q5(t_main *tab);
t_tex				**awl_q6(t_main *tab);
t_tex				**awl_q7(t_main *tab);
t_tex				**awl_q8(t_main *tab);

#endif
