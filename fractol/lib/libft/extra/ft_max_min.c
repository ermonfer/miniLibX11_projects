/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:30:50 by fmontero          #+#    #+#             */
/*   Updated: 2024/10/01 18:01:09 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extra.h"

int	ft_maxint(int a, int b)
{
	if (b > a)
		return (b);
	return (a);
}

int	ft_minint(int a, int b)
{
	if (b < a)
		return (b);
	return (a);
}
