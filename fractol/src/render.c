/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 07:25:33 by fmontero          #+#    #+#             */
/*   Updated: 2024/11/07 22:46:49 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// static int	get_color(t_fractal *fractal);
void		iterate_img(t_fractal *fractal);

// NO haría falta. En principoio la iteraciónde imagenes sería más eficiente.
// {
// 	int	offset;

// 	offset = (y * img->line_len) + (x * (img->bpp / 8));
// 	*(unsigned int *)(img->pixels + offset) = color;
// }

void	iterate_img(t_fractal *fractal)
{
	t_render_iterators	iters;
	int					bytes_per_pixel = fractal->mlx_interface.img.bpp / 8;

	iters.complex_iter = fractal->fractal_data.vertex;
	iters.complex_step.re = fractal->fractal_data.x_len / (WIDTH - 1);
	iters.complex_step.im = fractal->fractal_data.y_len / (HEIGHT - 1);
	iters.byte_iter = fractal->mlx_interface.img.pixels;
	iters.pixel_y = 0;
	while (iters.pixel_y <= HEIGHT)
	{
		iters.pixel_x = 0;
		while (iters.pixel_x < WIDTH)
		{
			*(unsigned int *)(iters.byte_iter) = fractal->fractal_data.color;
			iters.pixel_x++;
			iters.byte_iter += bytes_per_pixel;		
		}
	iters.pixel_y++;
	iters.byte_iter += fractal->mlx_interface.img.line_len
			- (WIDTH * bytes_per_pixel);
	}
}

// static int	get_color(t_fractal *fractal)
// {
// 	(void)fractal;
// 	return (0xFFFF0000);
// }