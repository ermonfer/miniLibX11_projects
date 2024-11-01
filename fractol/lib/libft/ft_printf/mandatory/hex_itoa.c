/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:33:13 by fmontero          #+#    #+#             */
/*   Updated: 2024/07/12 17:28:09 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	hex_get_len(uintptr_t n);
static char			hex_digit(unsigned char n, char font_size);

char	*hex_itoa(unsigned int n, char specifier)
{
	char			*result;
	unsigned int	len;

	len = hex_get_len(n);
	result = malloc(len);
	if (result == NULL)
		return (NULL);
	specifier += 'a' - 'x';
	result[--len] = '\0';
	while (--len > 0)
	{
		result[len] = hex_digit(n & 0xf, specifier);
		n >>= 4;
	}
	result[len] = hex_digit(n, specifier);
	return (result);
}

char	*ptoa(void *ptr)
{
	int			len;
	char		*str;
	uintptr_t	n;

	if (ptr == NULL)
		return (ft_strdup("(nil)"));
	n = (uintptr_t)ptr;
	len = hex_get_len(n) + 2;
	str = malloc(len);
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	str[1] = 'x';
	str[--len] = '\0';
	while (--len > 1)
	{
		str[len] = hex_digit(n & 0xf, 'a');
		n >>= 4;
	}
	return (str);
}

static char	hex_digit(unsigned char n, char font_size)
{
	if (n > 9)
		return (n - 10 + font_size);
	else
		return (n + '0');
}

static unsigned int	hex_get_len(uintptr_t n)
{
	unsigned int	i;

	i = 2;
	while (n > 15)
	{
		i++;
		n >>= 4;
	}
	return (i);
}
