/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uns_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:44:43 by fmontero          #+#    #+#             */
/*   Updated: 2024/07/10 15:44:46 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	get_len(unsigned int n);

char	*uns_itoa(unsigned int n)
{
	char			*result;
	unsigned int	len;

	len = get_len(n);
	result = (char *)malloc(len);
	if (result == NULL)
		return (NULL);
	result[--len] = '\0';
	while (n > 9)
	{
		result[--len] = (n % 10) + '0';
		n /= 10;
	}
	result[--len] = n + '0';
	return (result);
}

static unsigned int	get_len(unsigned int n)
{
	unsigned int	i;

	i = 2;
	while (n > 9)
	{
		i++;
		n /= 10;
	}
	return (i);
}
