/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-18 19:32:12 by fmontero          #+#    #+#             */
/*   Updated: 2024-11-18 19:32:12 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		reset_vertex_handler(t_fractal *fractal);
void	reset_escape_limit_handler(t_fractal *fractal);
void	increase_escape_limit_handler(t_fractal *data);
void	decrease_escape_limit_handler(t_fractal *data);
void	change_color_handler(t_fractal *fractal);

int	reset_vertex_handler(t_fractal *fractal)
{
	fractal->data.vertex = (t_complex){INITIAL_VERTEX_RE, INITIAL_VERTEX_IM};
	fractal->data.complex_width = INITIAL_COMPLEX_WIDTH;
	fractal->data.complex_height = INITIAL_COMPLEX_HEIGHT;
	redraw(fractal);
	return (0);
}

void	reset_escape_limit_handler(t_fractal *fractal)
{
	fractal->data.escape_limit = INITIAL_ESCAPE_LIMIT;
	redraw(fractal);
}

void	increase_escape_limit_handler(t_fractal *fractal)
{
	fractal->data.escape_limit += 20;
	redraw(fractal);
}

void	decrease_escape_limit_handler(t_fractal *fractal)
{
	if (fractal->data.escape_limit > 20U)
	{
		fractal->data.escape_limit -= 20U;
		redraw(fractal);
	}
}

void	change_color_handler(t_fractal *fractal)
{
	if (fractal->data.color_map == get_color)
		fractal->data.color_map = gray_scale;
	else if (fractal->data.color_map == gray_scale)
		fractal->data.color_map = temperature_map;
	else if (fractal->data.color_map == temperature_map)
		fractal->data.color_map = get_color;
	redraw(fractal);
}
