/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:01:55 by fmontero          #+#    #+#             */
/*   Updated: 2024/04/18 11:10:45 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*r;
	unsigned char	*us;

	us = (unsigned char *)s;
	r = NULL;
	while (*us != '\0')
	{
		if (*us == (unsigned char)c)
			r = (char *)us;
		us++;
	}
	if ((unsigned char)c == '\0')
		r = (char *)us;
	return (r);
}
