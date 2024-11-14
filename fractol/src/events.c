/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:13:52 by fmontero          #+#    #+#             */
/*   Updated: 2024/11/14 09:57:16 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	hook_setter(t_fractal *fractal);
int		close_handler(t_mlx_interface *interface);
int		key_handler(int keysym, t_fractal *fractal);
int		key_move_handler(t_fractal *fractal, t_movement movement);
int		mouse_push_handler(int button, int x, int y, t_fractal *fractal);
int		click_handler(int x, int y, t_fractal *fractal);
int		mouse_release_handler(int button, int x, int y, t_fractal *fractal);


void	hook_setter(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_interface.mlx_window, KeyPress, KeyPressMask,
		key_handler, fractal);
	mlx_hook(fractal->mlx_interface.mlx_window, ButtonPress, ButtonPressMask,
		mouse_push_handler, fractal);
	mlx_hook(fractal->mlx_interface.mlx_window, ButtonRelease, ButtonReleaseMask,
		mouse_release_handler, fractal);
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
		key_move_handler(fractal, move_right);
	if (keysym == XK_Left || keysym == XK_h)
		key_move_handler(fractal, move_left);
	if (keysym == XK_Up || keysym == XK_k)
		key_move_handler(fractal, move_up);
	if (keysym == XK_Down || keysym == XK_j)
		key_move_handler(fractal, move_down);
	return (0);
}

int	key_move_handler(t_fractal *fractal, t_movement movement)
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

int	mouse_push_handler(int button, int x, int y, t_fractal *fractal)
{
	t_complex cursor;

	if (button == Button1)
	{
		click_handler(x, y, fractal);
		return (0);
	}
	cursor.re = lerp(x, (double []){0, WIDTH},
	(double []){fractal->data.vertex.re, fractal->data.vertex.re
	+ fractal->data.complex_width});
	cursor.im = lerp(y, (double []){0, HEIGHT},
	(double []){fractal->data.vertex.im, fractal->data.vertex.im
	- fractal->data.complex_height});
	if (button == Button4)
	{
		if (fractal->data.button4_ctr++ < 1)
			return (0);
		fractal->data.button4_ctr = 0;
		fractal->data.vertex.re = (fractal->data.vertex.re - cursor.re)
			* fractal->data.zoom + cursor.re;
		fractal->data.vertex.im = (fractal->data.vertex.im - cursor.im)
			* fractal->data.zoom + cursor.im;
		fractal->data.complex_width *= fractal->data.zoom;
		fractal->data.complex_height *= fractal->data.zoom;
	}
	else if (button == Button5)
	{
		if (fractal->data.button5_ctr++ < 1)
			return (0);
		fractal->data.button5_ctr = 0;
		fractal->data.vertex.re = (fractal->data.vertex.re - cursor.re)
			/ fractal->data.zoom + cursor.re;
		fractal->data.vertex.im = (fractal->data.vertex.im - cursor.im)
			/ fractal->data.zoom + cursor.im;
		fractal->data.complex_width /= fractal->data.zoom;
		fractal->data.complex_height /= fractal->data.zoom;
	}
	iterate_img(fractal);
	mlx_put_image_to_window(fractal->mlx_interface.mlx_connection,
		fractal->mlx_interface.mlx_window,
		fractal->mlx_interface.img.context, 0, 0);
	return (0);
}

int click_handler(int x, int y, t_fractal *fractal)
{
	fractal->data.last_x = x;
	fractal->data.last_y = y;
    return (0);
}

int mouse_release_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == Button1)
	{
		fractal->data.vertex.re -= (x - fractal->data.last_x) * fractal->data.complex_width / (WIDTH - 1);
		fractal->data.vertex.im += (y - fractal->data.last_y) * fractal->data.complex_height / (HEIGHT - 1);
		iterate_img(fractal);
		mlx_put_image_to_window(fractal->mlx_interface.mlx_connection,
								fractal->mlx_interface.mlx_window,
								fractal->mlx_interface.img.context, 0, 0);
	}
	return (0);
}

// t_complex	get_complex(int x, int y, t_fractal *fractal)
// {
// 	return ((t_complex){lerp(x, (double []){0, WIDTH},
// 		(double []){fractal->data.vertex.re, fractal->data.vertex.re
// 		+ fractal->data.complex_width}),
// 		lerp(y, (double []){0, HEIGHT},
// 		(double []){fractal->data.vertex.im, fractal->data.vertex.im
// 		- fractal->data.complex_height})});
// }
