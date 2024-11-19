/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-18 19:37:29 by fmontero          #+#    #+#             */
/*   Updated: 2024-11-18 19:37:29 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		mouse_push_handler(int button, int x, int y, t_fractal *fractal);
int		mouse_release_handler(int button, int x, int y, t_fractal *fractal);
int		drag_handler(int x, int y, t_fractal *fractal);
void	zoom_in_handler(t_complex cursor, t_fractal *fractal);
void	zoom_out_handler(t_complex cursor, t_fractal *fractal);

int	mouse_push_handler(int button, int x, int y, t_fractal *fractal)
{
	t_complex	cursor;

	cursor.re = fractal->data.vertex.re + fractal->data.complex_width / 2;
	cursor.im = fractal->data.vertex.im + fractal->data.complex_height / 2;
	if (button == Button4)
		zoom_in_handler(cursor, fractal);
	else if (button == Button5)
		zoom_out_handler(cursor, fractal);
	redraw(fractal);
	return (0);
}

int	drag_handler(int x, int y, t_fractal *fractal)
{
	fractal->data.last_x = x;
	fractal->data.last_y = y;
	return (0);
}

void	zoom_in_handler(t_complex cursor, t_fractal *fractal)
{
	if (fractal->data.button4_ctr++ < 3)
		return ;
	fractal->data.button4_ctr = 0;
	fractal->data.vertex.re = (fractal->data.vertex.re - cursor.re)
		* fractal->data.zoom + cursor.re;
	fractal->data.vertex.im = (fractal->data.vertex.im - cursor.im)
		* fractal->data.zoom + cursor.im;
	fractal->data.complex_width *= fractal->data.zoom;
	fractal->data.complex_height *= fractal->data.zoom;
}

void	zoom_out_handler(t_complex cursor, t_fractal *fractal)
{
	if (fractal->data.button5_ctr++ < 3)
		return ;
	fractal->data.button5_ctr = 0;
	fractal->data.vertex.re = (fractal->data.vertex.re - cursor.re)
		/ fractal->data.zoom + cursor.re;
	fractal->data.vertex.im = (fractal->data.vertex.im - cursor.im)
		/ fractal->data.zoom + cursor.im;
	fractal->data.complex_width /= fractal->data.zoom;
	fractal->data.complex_height /= fractal->data.zoom;
}
