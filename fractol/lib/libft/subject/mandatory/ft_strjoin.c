/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:41:33 by fmontero          #+#    #+#             */
/*   Updated: 2024/08/04 18:04:40 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new;
	size_t	lens1;
	size_t	lens2;

	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	new = malloc(lens1 + lens2 + 1);
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, s1, lens1);
	ft_memcpy(new + lens1, s2, lens2);
	new[lens1 + lens2] = '\0';
	return (new);
}
