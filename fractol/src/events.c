/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:13:52 by fmontero          #+#    #+#             */
/*   Updated: 2024/11/05 15:13:15 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	hook_setter(t_fractal *fractal);
int		close_handler(t_mlx_interface *interface);
int		key_handler(int keysym, t_fractal *fractal);

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
	return (0);
}
