/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-01 16:48:58 by fmontero             #+#             */
/*   Updated: 2024-11-01 16:48:58 by fmontero         ##   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>

int				main(int argc, char *argv[]);
static void		fractal_init(t_fractal *fractal, t_fractal_type type);
void			fractal_ctxt(t_fractal *fractal);
static void		malloc_error(void);

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	fractal_init(&fractal, argv[1]);
	mlx_loop(fractal.mlx_connection);
	return (0);
}

void	fractal_init(t_fractal *fractal, t_fractal_type type)
{
	fractal->mlx_connection = mlx_init();
	if (NULL == fractal->mlx_connection)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT,
			"fractal");
	if (NULL == fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH,
			HEIGHT);
	if (NULL == fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.pixels = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	fractal->type = type;
	data_init(fractal);
	hook_setter(fractal);
}

static void data_init(t_fractal *fractal)
{
	
}

static void	malloc_error(void)
{
	perror("Fallo de malloc\n");
	exit(EXIT_FAILURE);
}
