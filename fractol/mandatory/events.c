/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:13:52 by fmontero          #+#    #+#             */
/*   Updated: 2024/11/17 17:52:16 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	hook_setter(t_fractal *fractal);
void	redraw(t_fractal *fractal);
int		close_handler(t_mlx_interface *interface);
int		key_move_handler(t_fractal *fractal, t_movement movement);
int		key_handler(int keysym, t_fractal *fractal);

void	hook_setter(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_interface.mlx_window, KeyRelease, KeyReleaseMask,
		key_handler, fractal);
	mlx_hook(fractal->mlx_interface.mlx_window, ButtonPress, ButtonPressMask,
		mouse_push_handler, fractal);
	mlx_hook(fractal->mlx_interface.mlx_window, DestroyNotify,
		StructureNotifyMask, close_handler, fractal);
}

void	redraw(t_fractal *fractal)
{
	iterate_img(fractal);
	mlx_put_image_to_window(fractal->mlx_interface.mlx_connection,
		fractal->mlx_interface.mlx_window,
		fractal->mlx_interface.img.context, 0, 0);
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
	if (keysym == XK_Right)
		key_move_handler(fractal, move_right);
	if (keysym == XK_Left)
		key_move_handler(fractal, move_left);
	if (keysym == XK_Up)
		key_move_handler(fractal, move_up);
	if (keysym == XK_Down)
		key_move_handler(fractal, move_down);
	if (keysym == XK_c)
		change_color_handler(fractal);
	return (0);
}

int	key_move_handler(t_fractal *fractal, t_movement movement)
{
	if (movement == move_right)
		fractal->data.vertex.re += fractal->data.complex_width / 50;
	else if (movement == move_left)
		fractal->data.vertex.re -= fractal->data.complex_width / 50;
	else if (movement == move_up)
		fractal->data.vertex.im += fractal->data.complex_height / 50;
	else if (movement == move_down)
		fractal->data.vertex.im -= fractal->data.complex_height / 50;
	redraw(fractal);
	return (0);
}
