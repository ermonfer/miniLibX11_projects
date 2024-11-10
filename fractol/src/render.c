/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 07:25:33 by fmontero          #+#    #+#             */
/*   Updated: 2024/11/10 23:00:48 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void			iterate_img(t_fractal *fractal);
static unsigned int	mandeljulia(t_complex complex, t_fractal *fractal);
static unsigned int	get_color(t_complex z, t_fractal *fractal);
// static unsigned int	gray_scale(t_complex z, t_fractal *fractal);

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
	iters.complex_step.re = fractal->fractal_data.complex_width / (WIDTH - 1);
	iters.complex_step.im = fractal->fractal_data.complex_height / (HEIGHT - 1);
	iters.byte_iter = fractal->mlx_interface.img.pixels;
	iters.pixel_y = 0;
	while (iters.pixel_y <= HEIGHT)
	{
		iters.pixel_x = 0;
		while (iters.pixel_x <= WIDTH)
		{
			*(unsigned int *)(iters.byte_iter) =
					get_color(iters.complex_iter, fractal);
			iters.pixel_x++;
			iters.complex_iter.re += iters.complex_step.re;
			iters.byte_iter += bytes_per_pixel;		
		}
	iters.pixel_y++;
	iters.byte_iter += fractal->mlx_interface.img.line_len
			- ((WIDTH + 1) * bytes_per_pixel);
	iters.complex_iter.re -= iters.complex_step.re * (WIDTH + 1);
	iters.complex_iter.im += iters.complex_step.im;
	}
}

unsigned int	mandeljulia(t_complex complex, t_fractal *fractal)
{
	unsigned int	i;
	t_complex 		z;
	t_complex 		c;

	 if (fractal->fractal_data.type == mandel)
	 {
		z = (t_complex){0, 0};
		c = complex;
	 }
	 if (fractal->fractal_data.type == julia)
	 {
		z = complex;
		c = fractal->fractal_data.julia_cte;
	 }
	 i = 0;
	 while (i < fractal->fractal_data.escape_limit)
	 {
		if (complex_module(z) > 4)
			break;
		z = complex_sum(complex_square(z), c);
		i++;
	 }
	 return (i);
}

static unsigned int	get_color(t_complex z, t_fractal *fractal)
{
	return ((unsigned int)lerp((double)mandeljulia(z, fractal),
			(double[]){0, fractal->fractal_data.escape_limit},
			(double[]){WHITE, BLACK}));
}

// static unsigned int	gray_scale(t_complex z, t_fractal *fractal)
// {
// 	unsigned int	intensity;

// 	intensity = (unsigned int)lerp((double)mandeljulia(z, fractal),
// 	(double[]){0, fractal->fractal_data.escape_limit},
// 	(double[]){0, 255});
// 	intensity = 255 - intensity;
// 	return ((0xFF << 24) | (intensity << 16) | (intensity << 8) | intensity);
// }