/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 09:48:48 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 15:49:26 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WIN_WIDTH 1000
# define WIN_HEIGHT 700
# define ERROR_ENUM_NB 10
# define EPSILON 1e-4

# include <math.h>
# include <stdio.h>
# include "libft.h"
# include "MLX42.h"
# include "typedef.h"
# include "color/color_add.h"
# include "color/color_dim.h"
# include "color/color_mult.h"
# include "color/new_color.h"
# include "color/str_to_color.h"
# include "debug/debug.h"
# include "debug/print_amb_light.h"
# include "debug/print_cam.h"
# include "debug/print_cylinder.h"
# include "debug/print_light.h"
# include "debug/print_object.h"
# include "debug/print_parser.h"
# include "debug/print_plan.h"
# include "debug/print_sphere.h"
# include "debug/print_triangle.h"
# include "debug/utils/print_angle.h"
# include "debug/utils/print_color.h"
# include "debug/utils/print_point3.h"
# include "debug/utils/print_vec3.h"
# include "free/free_d_pars.h"
# include "free/free_data.h"
# include "init/init.h"
# include "init/init_all_pixel.h"
# include "init/init_amb_light.h"
# include "init/init_bg.h"
# include "init/init_camera.h"
# include "init/init_lights.h"
# include "init/init_mlx.h"
# include "init/init_object.h"
# include "init/objects/init_cylinders.h"
# include "init/objects/init_plans.h"
# include "init/objects/init_spheres.h"
# include "init/objects/init_triangles.h"
# include "key_hook/key_hook.h"
# include "key_hook/move_cam.h"
# include "key_hook/rt_exit.h"
# include "lights/amb_light/new_amb_light.h"
# include "lights/light/is_lighted.h"
# include "lights/light/is_shadowed.h"
# include "lights/light/new_light.h"
# include "parser/check/amb_light_check.h"
# include "parser/check/app_param_check.h"
# include "parser/check/camera_check.h"
# include "parser/check/cylinder_check.h"
# include "parser/check/file_check.h"
# include "parser/check/light_check.h"
# include "parser/check/plan_check.h"
# include "parser/check/sphere_check.h"
# include "parser/check/token_check.h"
# include "parser/check/triangle_check.h"
# include "parser/check/utils/angle_check.h"
# include "parser/check/utils/color_check.h"
# include "parser/check/utils/coord_check.h"
# include "parser/check/utils/float_check.h"
# include "parser/check/utils/intensity_check.h"
# include "parser/check/utils/vec_check.h"
# include "parser/error/add_error.h"
# include "parser/error/error_init.h"
# include "parser/error/print_error.h"
# include "parser/init/parser_init.h"
# include "parser/parser.h"
# include "parser/utils/find_pars_line.h"
# include "parser/utils/splitter.h"
# include "point/new_point3.h"
# include "point/point_from_orig_vec.h"
# include "point/str_to_point3.h"
# include "put_all_pixels/draw.h"
# include "put_all_pixels/get_hit_rec.h"
# include "put_all_pixels/put_all_pixels.h"
# include "put_all_pixels/specular.h"
# include "ray/new_ray.h"
# include "ray/new_ray_at_pixel.h"
# include "ray/point_at_ray.h"
# include "scene_object/camera/cam_vec_calc.h"
# include "scene_object/camera/camera_rotate_x.h"
# include "scene_object/camera/camera_rotate_z.h"
# include "scene_object/camera/camera_translate.h"
# include "scene_object/cylinder/hit_cylinder.h"
# include "scene_object/cylinder/new_cylinder.h"
# include "scene_object/plan/hit_plan.h"
# include "scene_object/plan/new_plan.h"
# include "scene_object/sphere/hit_sphere.h"
# include "scene_object/sphere/new_sphere.h"
# include "scene_object/triangle/hit_triangle.h"
# include "scene_object/triangle/new_triangle.h"
# include "vector/get_angle_axe_x.h"
# include "vector/get_angle_axe_z.h"
# include "vector/new_vec3.h"
# include "vector/str_to_vec3.h"
# include "vector/vector_add.h"
# include "vector/vector_cross.h"
# include "vector/vector_div.h"
# include "vector/vector_dot.h"
# include "vector/vector_from_2pts.h"
# include "vector/vector_get_normale.h"
# include "vector/vector_mult.h"
# include "vector/vector_normalize.h"
# include "vector/vector_rot_axe_x.h"
# include "vector/vector_rot_axe_z.h"
# include "vector/vector_sub.h"

#endif