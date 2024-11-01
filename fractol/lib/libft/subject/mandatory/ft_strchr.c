/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:59:21 by fmontero          #+#    #+#             */
/*   Updated: 2024/08/04 17:54:07 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const unsigned char		*us;
	unsigned char			uc;

	if (s == NULL)
		return (NULL);
	us = (const unsigned char *)s;
	uc = (unsigned char)c;
	while (*us != uc)
	{
		if (*us++ == '\0')
			return (NULL);
	}
	return ((char *)us);
}
