/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-08 17:58:22 by fmontero          #+#    #+#             */
/*   Updated: 2024-11-08 17:58:22 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/extra.h"

static double	decimal_part(char str[], int *format_error);

double	ft_atod_signal(char str[], int *format_error)
{
	int 	sign;
	double	result;

	*format_error = 0;
	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	result = 0;
	while (ft_isdigit(*str))
		result = result * 10 + (*str++ - '0');
	if (*str == '\0')
		return (result);
	if (*str == '.')
		str++;
	else
	{
		*format_error = 1;
		return (result);
	}
	return (sign * (result + decimal_part(str, format_error)));
}

static double	decimal_part(char str[], int *format_error)
{
	double	result;
	double	decimal_place;

	result = 0;
	decimal_place = 0.1;
	while (ft_isdigit(*str))
	{
		result += (*str - '0') * decimal_place;
		decimal_place *= 0.1; 
		str++;
	}
	if (!(ft_isspace(*str) || *str == '\0'))
		*format_error = 1;
	return (result);
}
