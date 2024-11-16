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
static unsigned int	mandeljulia(t_complex complex, t_fractal *fractal);
// static unsigned int	get_color(t_complex z, t_fractal *fractal);
static unsigned int	gray_scale(t_complex z, t_fractal *fractal);

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
	iters.complex_step.re = fr->data.complex_width / (WIDTH - 1);
	iters.complex_step.im = -(fr->data.complex_height / (HEIGHT - 1));
	iters.byte_iter = fr->mlx_interface.img.pixels;
	iters.pixel_y = 0;
	while (iters.pixel_y < HEIGHT)
	{
		iters.pixel_x = 0;
		while (iters.pixel_x < WIDTH)
		{
			*((t_uint *)iters.byte_iter) = gray_scale(iters.complex_iter, fr);
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

void	move_image(t_fractal *fr, int dx, int dy)
{
	t_traslation_table	tab;
	int					bytes_per_pixel;
	int					reset_x;

	bytes_per_pixel = fr->mlx_interface.img.bpp / 8;
	if (dx >= 0 && dy >= 0)
		tab = (t_traslation_table){0, 0, 1, 1, WIDTH, HEIGHT - 1,
			fr->mlx_interface.img.pixels};
	else if (dx >= 0 && dy < 0)
		tab = (t_traslation_table){0, HEIGHT - 1, 1, -1, WIDTH - 1, 0,
			fr->mlx_interface.img.pixels
			+ (fr->mlx_interface.img.line_len * (HEIGHT - 1))};
	else if (dx < 0 && dy >= 0)
		tab = (t_traslation_table){WIDTH - 1, 0, -1, 1, 0, HEIGHT - 1,
			fr->mlx_interface.img.pixels + (bytes_per_pixel * (WIDTH - 1))};
	else if (dx < 0 && dy < 0)
		tab = (t_traslation_table){WIDTH - 1, HEIGHT - 1, -1, -1, 0, 0,
			fr->mlx_interface.img.pixels + (bytes_per_pixel * (WIDTH - 1))
			+ (fr->mlx_interface.img.line_len * (HEIGHT - 1))};
	tab.offset =  dx * bytes_per_pixel + dy * fr->mlx_interface.img.line_len;
	reset_x = tab.pixel_x;
	while ((tab.pixel_y + dy) * tab.step_y <= tab.limit_y * tab.step_y)
	{
		tab.pixel_x = reset_x;
		while ((tab.pixel_x + dx) * tab.step_x <= tab.limit_x * tab.step_x)
		{
			*(tab.byte_iter + tab.offset) = *(tab.byte_iter);
			tab.byte_iter += tab.step_x * bytes_per_pixel;
			tab.pixel_x += tab.step_x;
		}
		tab.byte_iter -= tab.step_x * (WIDTH - (dx * tab.step_x))
			* bytes_per_pixel;
		tab.byte_iter += tab.step_y * fr->mlx_interface.img.line_len;
		tab.pixel_y += tab.step_y;
	}
}

unsigned int	mandeljulia(t_complex complex, t_fractal *fractal)
{
	unsigned int	i;
	t_complex		z;
	t_complex		c;

	if (fractal->data.type == mandel)
	{
		z = (t_complex){0, 0};
		c = complex;
	}
	else
	{
		z = complex;
		c = fractal->data.julia_cte;
	}
	i = 0;
	while (i < fractal->data.escape_limit)
	{
		if (z.re * z.re + z.im * z.im > 4)
			break ;
		z = (t_complex){z.re * z.re - z.im * z.im + c.re, 2 * z.re * z.im + c.im};
		i++;
	}
	return (i);
}

// static unsigned int	get_color(t_complex z, t_fractal *fractal)
// {
// 	return ((unsigned int)lerp((double)mandeljulia(z, fractal),
// 			(double []){0, fractal->data.escape_limit},
// 		(double []){WHITE, BLACK}));
// }

static unsigned int	gray_scale(t_complex z, t_fractal *fractal)
{
	unsigned int	intensity;

	intensity = (unsigned char)lerp((double)mandeljulia(z, fractal),
	(double[]){0, fractal->data.escape_limit},
	(double[]){0, 255});
	intensity = 255 - intensity;
	return ((0xFF << 24) | (intensity << 16) | (intensity << 8) | intensity);
}