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

double		lerp(double target, double old[2], double new[2]);

double	lerp(double target, double old[2], double new[2])
{
	return ((new[1] - new[0]) * ((target - old[0]) / (old[1] - old[0]))
		+ new[0]);
}
