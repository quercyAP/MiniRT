/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:30:38 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 15:56:15 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}				t_vec3;

typedef struct s_triple
{
	double	a;
	double	b;
	double	c;
}				t_triple;

typedef t_vec3	t_point3;

enum	e_type
{
	SPHERE,
	PLAN,
	CYLINDER,
	TRIANGLE
};

typedef union u_color
{
	uint32_t			c;
	struct s_abgrTag
	{
		unsigned char	a;
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
	}			abgr;
}			t_color;

typedef struct s_hit_rec
{
	double		dist;
	double		dist1;
	t_point3	hit_pt;
	t_vec3		normal;
	t_color		color;
	bool		inside;
}				t_hit_rec;

typedef struct s_ray
{
	t_point3	origin;
	t_vec3		vec_dir;
}				t_ray;

typedef struct s_camera
{
	t_point3	origin;
	t_vec3		vec_orient;
	double		fov;
	double		focal_length;
	double		viewport_width;
	double		viewport_height;
	double		image_ratio;
	double		x_axis_rot;
	double		z_axis_rot;
	t_vec3		vec_vp_vert;
	t_vec3		vec_vp_horiz;
	t_point3	vp_llc;
	t_point3	vp_lrc;
	t_point3	vp_ulc;
	t_point3	vp_urc;
	t_point3	vp_center;
}				t_camera;

typedef struct s_amb_light
{
	double	intensity;
	t_color	color;
}				t_amb_light;

typedef struct s_light
{
	int			id;
	t_point3	origin;
	double		intensity;
	t_color		color;
}				t_light;

typedef struct s_sphere
{
	int				id;
	enum e_type		type;
	t_point3		origin;
	double			diameter;
	double			radius;
	t_color			color;
}				t_sphere;

typedef struct s_plan
{
	int				id;
	enum e_type		type;
	t_point3		origin;
	t_vec3			vec_orient;
	t_color			color;
}				t_plan;

typedef struct s_cylinder
{
	int				id;
	enum e_type		type;
	t_point3		origin;
	t_vec3			vec_axis;
	double			diameter;
	double			radius;
	double			height;
	t_color			color;
}				t_cylinder;

typedef struct s_triangle
{
	int			id;
	t_point3	pt0;
	t_point3	pt1;
	t_point3	pt2;
	t_vec3		normal;
	t_color		color;
	enum e_type	type;
}				t_triangle;

typedef struct s_data
{
	t_camera	camera;
	t_amb_light	amb_light;
	t_list		*lst_light;
	t_list_mixt	*lst_object;
	uint32_t	win_width;
	uint32_t	win_height;
	t_color		**all_pixel;
	t_color		**bg;
	mlx_t		*mlx;
	mlx_image_t	*image;
}				t_data;

enum	e_pars_error
{
	TOKEN_ER,
	TOO_MANY_TOKEN_ER,
	TOO_FEW_TOKEN_ER,
	INVALID_RANGE_ER,
	INVALID_FORMAT_ER,
	INVALID_LENGTH_ER,
	TOO_MANY_PARAM_ER,
	TOO_FEW_PARAM_ER,
	INVALID_NOTDIGIT_ER
};

typedef struct s_list_error
{
	struct s_list_error		*next;
	enum e_pars_error		error;
	char					*arg;
	int						line_nb;
}			t_list_error;
typedef struct s_d_pars
{
	t_list_error			*lst_error;
	char					**strerror_tab;
	t_list					*lst_pars;
	int						nb_amblight;
	int						nb_cam;
}				t_d_pars;

typedef struct s_pars_line
{
	int						id;
	char					*raw_line;
	char					**token_tab;
	t_d_pars				*d_pars;
}				t_pars_line;

#endif
