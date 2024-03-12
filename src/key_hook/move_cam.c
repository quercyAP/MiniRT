/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:14:04 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	trans_slow(mlx_key_data_t d_key, t_camera *cam)
{
	double	delta_move;

	delta_move = 0.01;
	if (d_key.key == MLX_KEY_LEFT)
		camera_translate(cam, -delta_move, 0, 0);
	else if (d_key.key == MLX_KEY_RIGHT)
		camera_translate(cam, delta_move, 0, 0);
	else if (d_key.key == MLX_KEY_UP)
		camera_translate(cam, 0, 0, delta_move);
	else if (d_key.key == MLX_KEY_DOWN)
		camera_translate(cam, 0, 0, -delta_move);
	else if (d_key.key == MLX_KEY_PAGE_UP)
		camera_translate(cam, 0, delta_move, 0);
	else if (d_key.key == MLX_KEY_PAGE_DOWN)
		camera_translate(cam, 0, -delta_move, 0);
}

static void	trans_fast(mlx_key_data_t d_key, t_camera *cam)
{
	double	delta_move;

	delta_move = 1.0;
	if (d_key.key == MLX_KEY_LEFT)
		camera_translate(cam, -delta_move, 0, 0);
	else if (d_key.key == MLX_KEY_RIGHT)
		camera_translate(cam, delta_move, 0, 0);
	else if (d_key.key == MLX_KEY_UP)
		camera_translate(cam, 0, 0, delta_move);
	else if (d_key.key == MLX_KEY_DOWN)
		camera_translate(cam, 0, 0, -delta_move);
	else if (d_key.key == MLX_KEY_PAGE_UP)
		camera_translate(cam, 0, delta_move, 0);
	else if (d_key.key == MLX_KEY_PAGE_DOWN)
		camera_translate(cam, 0, -delta_move, 0);
}

static void	rot_fast(mlx_key_data_t d_key, t_camera *cam)
{
	double	delta_move;

	delta_move = 1.0;
	if (d_key.key == MLX_KEY_D)
		camera_rotate_z(cam, delta_move);
	else if (d_key.key == MLX_KEY_A)
		camera_rotate_z(cam, -delta_move);
	else if (d_key.key == MLX_KEY_W)
		camera_rotate_x(cam, -delta_move);
	else if (d_key.key == MLX_KEY_S)
		camera_rotate_x(cam, delta_move);
}

static void	rot_slow(mlx_key_data_t d_key, t_camera *cam)
{
	double	delta_move;

	delta_move = 0.01;
	if (d_key.key == MLX_KEY_D)
		camera_rotate_z(cam, delta_move);
	else if (d_key.key == MLX_KEY_A)
		camera_rotate_z(cam, -delta_move);
	else if (d_key.key == MLX_KEY_W)
		camera_rotate_x(cam, -delta_move);
	else if (d_key.key == MLX_KEY_S)
		camera_rotate_x(cam, delta_move);
}

void	move_cam(mlx_key_data_t d_key, void *param)
{
	t_camera	*cam;
	double		delta_move;

	delta_move = 0.01;
	cam = &(((t_data *)param)->camera);
	if (d_key.modifier == MLX_SHIFT)
	{
		rot_fast(d_key, cam);
		trans_fast(d_key, cam);
	}
	else
	{
		rot_slow(d_key, cam);
		trans_slow(d_key, cam);
	}
	draw((t_data *)param);
}
