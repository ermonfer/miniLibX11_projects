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
