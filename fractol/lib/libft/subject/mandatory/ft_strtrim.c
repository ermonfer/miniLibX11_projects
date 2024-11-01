/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:42:39 by fmontero          #+#    #+#             */
/*   Updated: 2024/04/10 23:30:20 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Devuelve una version recortada de s1 donde se han eliminado las secuencias
 * de char contenidas en set al principio y al final de la cadena */

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*begin;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	if (*s1 == '\0')
		return (ft_strdup(""));
	begin = s1;
	while (*++s1 != '\0')
		;
	while (ft_strchr(set, *--s1))
		;
	return (ft_substr(begin, 0, s1 - begin + 1));
}
