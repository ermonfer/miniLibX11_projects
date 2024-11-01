/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:47:58 by fmontero          #+#    #+#             */
/*   Updated: 2024/08/02 20:26:24 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		words_count(char const *s, char c);
static char		**fill_result(char **result, char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**result;

	result = (char **)malloc((words_count(s, c) + 1) * sizeof (char *));
	if (result == NULL)
		return (NULL);
	if (fill_result(result, s, c) == NULL)
	{
		free(result);
		return (NULL);
	}
	return (result);
}

static int	words_count(char const *s, char c)
{
	int		words;

	words = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			words++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	return (words);
}

static char	**fill_result(char **result, char const *s, char c)
{
	int				i;
	char const		*word_beg;

	i = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		word_beg = s;
		s = ft_strchr(s, c);
		if (s == NULL)
			s = ft_strchr(word_beg, '\0');
		result[i] = ft_substr(word_beg, 0, s - word_beg);
		if (result[i] == NULL)
		{
			while (--i >= 0)
				free(result[i]);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
