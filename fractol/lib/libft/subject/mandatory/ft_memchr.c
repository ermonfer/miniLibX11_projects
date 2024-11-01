/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 23:56:38 by fmontero          #+#    #+#             */
/*   Updated: 2024/04/08 19:16:26 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*r;
	unsigned char		ch;

	r = (const unsigned char *)s;
	ch = (unsigned char)c;
	while (n-- > 0)
	{
		if (*r++ == ch)
			return ((void *)--r);
	}
	return (NULL);
}
