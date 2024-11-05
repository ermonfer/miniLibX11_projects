/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-05 07:25:33 by fmontero          #+#    #+#             */
/*   Updated: 2024-11-05 07:25:33 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels + offset) = color;
}

void	iterate_img(t_fractal *fractal)
{
	t_render_iterators iterators;

	iterators.complex_iter = fractal->data.vertex;
	iterators.complex_step.re = fractal->data.x_len / (WIDTH - 1);
	iterators.complex_step.im = fractal->data.y_len / (HEIGHT - 1);
	iterators.byte_iter = fractal->img.pixels;
	iterators.byte_step = () 
	while (y_counter <= HEIGHT)
	{
		x_counter = 0;
		while (x_counter <= WIDTH)
		{
				

		}

	}
}
