/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 07:25:33 by fmontero          #+#    #+#             */
/*   Updated: 2024/11/16 01:14:03 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void				iterate_img(t_fractal *fractal);
// static unsigned int	mandeljulia(t_complex complex, t_fractal *fractal);
// static unsigned int	get_color(t_complex z, t_fractal *fractal);
// static t_uint		gray_scale(t_complex z, t_fractal *fractal);

// NO haría falta. En principoio la iteraciónde imagenes sería más eficiente.
// {
// 	int	offset;

// 	offset = (y * img->line_len) + (x * (img->bpp / 8));
// 	*(unsigned int *)(img->pixels + offset) = color;
// }

void	iterate_img(t_fractal *fr)
{
	t_render_iterators	iters;
	int					bytes_per_pixel;

	bytes_per_pixel = fr->mlx_interface.img.bpp / 8;
	iters.complex_iter = fr->data.vertex;
	iters.complex_step.re = fr->data.complex_width / (double)(WIDTH - 1);
	iters.complex_step.im = -(fr->data.complex_height / (double)(HEIGHT - 1));
	iters.byte_iter = fr->mlx_interface.img.pixels;
	iters.pixel_y = 0;
	while (iters.pixel_y < HEIGHT)
	{
		iters.pixel_x = 0;
		while (iters.pixel_x < WIDTH)
		{
			*((t_uint *)iters.byte_iter) = (t_uint)lerp(0.0,//mandeljulia(((t_complex){-2.0001, 0}), fr),
				(double []){0, fr->data.escape_limit},
				(double []){WHITE, BLACK}); //(t_uint)get_color(iters.complex_iter, fr);
			iters.pixel_x++;
			iters.complex_iter.re += iters.complex_step.re;
			iters.byte_iter += bytes_per_pixel;
		}
		iters.pixel_y++;
		iters.byte_iter += fr->mlx_interface.img.line_len
			- (WIDTH * bytes_per_pixel);
		iters.complex_iter.re -= iters.complex_step.re * WIDTH;
		iters.complex_iter.im += iters.complex_step.im;
	}
}

// unsigned int	mandeljulia(t_complex complex, t_fractal *fractal)
// {
// 	unsigned int	i;
// 	t_complex		z;
// 	t_complex		c;

// 	if (fractal->data.type == mandel)
// 	{
// 		z = (t_complex){0, 0};
// 		c = complex;
// 	}
// 	else
// 	{
// 		z = complex;
// 		c = fractal->data.julia_cte;
// 	}
// 	i = 0;
// 	while (i < fractal->data.escape_limit)
// 	{
// 		if (z.re * z.re + z.im * z.im > 4)
// 			return (i);
// 		z = (t_complex){z.re * z.re - z.im * z.im + c.re, 2 * z.re * z.im + c.im};
// 		i++;
// 	}
// 	return (i);
// }

// static unsigned int	get_color(t_complex z, t_fractal *fractal)
// {
// 	return ((unsigned int)lerp((double)mandeljulia(z, fractal),
// 			(double []){0, fractal->data.escape_limit},
// 		(double []){WHITE, BLACK}));
// }

// static unsigned int	gray_scale(t_complex z, t_fractal *fractal)
// {
// 	unsigned int	intensity;

// 	intensity = (unsigned char)lerp((double)mandeljulia(z, fractal),
// 	(double[]){0, fractal->data.escape_limit},
// 	(double[]){0, 255});
// 	intensity = 255 - intensity;
// 	return ((0xFF << 24) | (intensity << 16) | (intensity << 8) | intensity);
// }