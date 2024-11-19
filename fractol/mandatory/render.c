/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 07:25:33 by fmontero          #+#    #+#             */
/*   Updated: 2024/11/17 16:58:07 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void				iterate_img(t_fractal *fractal);
static unsigned int	mandeljulia(t_complex complex, t_fractal *fractal);
unsigned int		get_color(t_complex z, t_fractal *fractal);
unsigned int		gray_scale(t_complex z, t_fractal *fractal);
unsigned int		temperature_map(t_complex z, t_fractal *fractal);

void	iterate_img(t_fractal *fr)
{
	t_render_iterators	iters;
	int					bytes_pp;

	bytes_pp = fr->mlx_interface.img.bpp / 8;
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
			*((unsigned int *) iters.byte_iter)
				= fr->data.color_map(iters.complex_iter, fr);
			iters.pixel_x++;
			iters.complex_iter.re += iters.complex_step.re;
			iters.byte_iter += bytes_pp;
		}
		iters.pixel_y++;
		iters.byte_iter += fr->mlx_interface.img.line_len - (WIDTH * bytes_pp);
		iters.complex_iter.re -= iters.complex_step.re * WIDTH;
		iters.complex_iter.im += iters.complex_step.im;
	}
}

unsigned int	mandeljulia(t_complex complex, t_fractal *fractal)
{
	unsigned int	i;
	t_complex		z;
	t_complex		c;

	if (fractal->data.type == mandel || fractal->data.type == tricorn)
	{
		z = (t_complex){0, 0};
		c = complex;
	}
	else
	{
		z = complex;
		c = fractal->data.julia_cte;
	}
	i = 0U;
	while (++i < fractal->data.escape_limit)
	{
		if (fractal->data.type == tricorn)
			z.im = -z.im;
		if ((z.re * z.re) + (z.im * z.im) >= 4.0)
			return (--i);
		z = (t_complex){z.re * z.re - z.im * z.im + c.re,
			2 * z.re * z.im + c.im};
	}
	return (i);
}

unsigned int	get_color(t_complex z, t_fractal *fractal)
{
	return ((unsigned int)ft_lerp((double)mandeljulia(z, fractal),
			(double []){0, fractal->data.escape_limit},
		(double []){WHITE, BLACK}));
}

unsigned int	gray_scale(t_complex z, t_fractal *fractal)
{
	unsigned int	intensity;

	intensity = (unsigned char)ft_lerp((double)mandeljulia(z, fractal),
			(double []){0, fractal->data.escape_limit}, (double []){0, 255});
	return ((0xFF << 24) | (intensity << 16) | (intensity << 8) | intensity);
}

unsigned int	temperature_map(t_complex z, t_fractal *fractal)
{
	t_temperature_map_data	dt;
	static double			path[6][3] = {{1.0, 1.0, 1.0}, {0.0, 0.5, 1.0},
	{1.0, 1.0, 0.0}, {1.0, 0.5, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};

	dt.intensity = (double)mandeljulia(z, fractal);
	dt.t = ft_lerp(dt.intensity,
			(double []){0, fractal->data.escape_limit}, (double []){0, 1});
	dt.segment = (int)(dt.t * (6 - 1));
	dt.local_t = (dt.t * (6 - 1)) - dt.segment;
	dt.beg = path[dt.segment];
	dt.end = path[dt.segment + 1];
	dt.r = ft_lerp(dt.local_t,
			(double []){0, 1}, (double []){dt.beg[0], dt.end[0]});
	dt.g = ft_lerp(dt.local_t,
			(double []){0, 1}, (double []){dt.beg[1], dt.end[1]});
	dt.b = ft_lerp(dt.local_t,
			(double []){0, 1}, (double []){dt.beg[2], dt.end[2]});
	dt.color = ((unsigned char)(dt.r * 255) << 16)
		| ((unsigned char)(dt.g * 255) << 8)
		| (unsigned char)(dt.b * 255) | (0xFF << 24);
	return (dt.color);
}
