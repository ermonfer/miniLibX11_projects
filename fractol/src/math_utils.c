/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 06:46:39 by fmontero          #+#    #+#             */
/*   Updated: 2024/11/17 16:52:14 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_complex	complex_sum(t_complex a, t_complex b);
t_complex	complex_square(t_complex z);
double		complex_module(t_complex z);
double		lerp(double target, double old[2], double new[2]);

t_complex	complex_sum(t_complex a, t_complex b)
{
	return ((t_complex){a.re + b.re, a.im + b.im});
}

t_complex	complex_square(t_complex z)
{
	return ((t_complex){(z.re * z.re) - (z.im * z.im), 2 * z.re * z.im});
}

double	lerp(double target, double old[2], double new[2])
{
	return ((new[1] - new[0]) * ((target - old[0]) / (old[1] - old[0]))
		+ new[0]);
}

double	complex_module(t_complex z)
{
	return ((double)(z.re * z.re + z.im * z.im));
}
