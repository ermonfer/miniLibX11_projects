/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:13:52 by fmontero          #+#    #+#             */
/*   Updated: 2024/11/07 22:57:05 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	hook_setter(t_fractal *fractal);
int		close_handler(t_mlx_interface *interface);
int		key_handler(int keysym, t_fractal *fractal);
int		move_handler(t_fractal *fractal, t_movement movement);

void	hook_setter(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_interface.mlx_window, KeyPress, KeyPressMask,
		key_handler, fractal);
	mlx_hook(fractal->mlx_interface.mlx_window, DestroyNotify,
		StructureNotifyMask, close_handler, fractal);
}

int	close_handler(t_mlx_interface *interface)
{
	mlx_destroy_image(interface->mlx_connection,
		interface->img.context);
	mlx_destroy_window(interface->mlx_connection,
		interface->mlx_window);
	mlx_loop_end(interface->mlx_connection);
	return (0);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(&fractal->mlx_interface);
	if (keysym == XK_Right || keysym == XK_l)
		move_handler(fractal, move_right);
	if (keysym == XK_Left || keysym == XK_h)
		move_handler(fractal, move_left);
	if (keysym == XK_Up || keysym == XK_k)
		move_handler(fractal, move_up);
	if (keysym == XK_Down || keysym == XK_j)
		move_handler(fractal, move_down);
	return (0);
}

int	move_handler(t_fractal *fractal, t_movement movement)
{
	if (movement == move_right)
		fractal->data.vertex.re -= fractal->data.complex_width / 50;
	else if (movement == move_left)
		fractal->data.vertex.re += fractal->data.complex_width / 50;
	else if (movement == move_up)
		fractal->data.vertex.im -= fractal->data.complex_height / 50;
	else if (movement == move_down)
		fractal->data.vertex.im += fractal->data.complex_height / 50;
	iterate_img(fractal);
	mlx_put_image_to_window(fractal->mlx_interface.mlx_connection,
		fractal->mlx_interface.mlx_window,
		fractal->mlx_interface.img.context, 0, 0);
	return (0);
}
