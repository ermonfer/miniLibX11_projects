/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:29:04 by fmontero          #+#    #+#             */
/*   Updated: 2024/08/04 17:55:54 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	length;

	if (s == NULL)
		return (NULL);
	length = ft_strlen(s);
	if (start >= length)
		return (ft_strdup(""));
	if (length < len + start)
		len = length - start;
	subs = (char *)malloc(len + 1);
	if (subs == NULL)
		return (NULL);
	s += start;
	length = 0;
	while (len-- > 0)
		subs[length++] = *s++;
	subs[length] = '\0';
	return (subs);
}
