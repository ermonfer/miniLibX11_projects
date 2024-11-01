/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:15:14 by fmontero          #+#    #+#             */
/*   Updated: 2024/04/19 20:49:14 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	if (*needle == '\0')
		return ((char *)(haystack));
	needle_len = ft_strlen(needle);
	while (*haystack != '\0' && needle_len <= len--)
	{
		if (ft_strncmp(haystack, needle, needle_len) == 0)
			return ((char *)(haystack));
		haystack++;
	}
	return (NULL);
}
