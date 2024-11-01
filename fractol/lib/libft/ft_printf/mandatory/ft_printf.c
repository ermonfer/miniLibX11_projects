/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:02:04 by fmontero          #+#    #+#             */
/*   Updated: 2024/07/20 19:46:49 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_conversion(const char specifier, va_list *args);
static int	print_specifications(const char **start, va_list *args);
static int	printfree(char *s);
static char	*strdup_s(char *s);

int	ft_printf(const char *format, ...)
{
	int				total;
	va_list			args;
	int				written;

	va_start(args, format);
	total = print_specifications(&format, &args);
	if (total == -1)
		return (-1);
	written = write(1, format, ft_strlen(format));
	if (written == -1)
		return (-1);
	total += written;
	va_end(args);
	return (total);
}

static int	print_specifications(const char **start, va_list *args)
{
	int			total;
	const char	*cursor;
	int			written;

	total = 0;
	cursor = ft_strchr(*start, '%');
	while (cursor)
	{
		written = write(1, *start, cursor - *start);
		if (written == -1)
			return (-1);
		total += written;
		written = print_conversion(*(cursor + 1), args);
		if (written == -1)
			return (-1);
		total += written;
		*start = cursor + 2;
		cursor = ft_strchr(*start, '%');
	}
	return (total);
}

int	print_conversion(const char spec, va_list *args)
{
	if (spec == '%')
		return (write(1, (char []){'%'}, 1));
	else if (spec == 'c')
		return (write(1, (char []){va_arg(*args, int)}, 1));
	else if (spec == 's')
		return (printfree(strdup_s(va_arg(*args, char *))));
	else if (spec == 'd' || spec == 'i')
		return (printfree(ft_itoa(va_arg(*args, int))));
	else if (spec == 'u')
		return (printfree(uns_itoa(va_arg(*args, unsigned int))));
	else if (spec == 'x' || spec == 'X')
		return (printfree(hex_itoa(va_arg(*args, unsigned int), spec)));
	else if (spec == 'p')
		return (printfree(ptoa(va_arg(*args, void *))));
	else if (spec == '\0')
		return (-1);
	else
		return (printfree(ft_strdup((char []){'%', spec, '\0'})));
}

static int	printfree(char *s)
{
	int	written;

	if (s == NULL)
		return (-1);
	written = write(1, s, ft_strlen(s));
	free(s);
	return (written);
}

static char	*strdup_s(char *s)
{
	if (s == NULL)
		return (ft_strdup("(null)"));
	return (ft_strdup(s));
}
