/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lerp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-19 16:02:28 by fmontero          #+#    #+#             */
/*   Updated: 2024-11-19 16:02:28 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extra.h"

double	ft_lerp(double target, double old[2], double new[2])
{
	return ((new[1] - new[0]) * ((target - old[0]) / (old[1] - old[0]))
		+ new[0]);
}
