/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:22:43 by fmontero          #+#    #+#             */
/*   Updated: 2024/11/07 22:43:08 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int				main(int argc, char *argv[]);
static void		fractal_init(t_fractal *fractal);
static void		fractal_data_init(t_fractal_data *data);
static void		malloc_error(void);
static void		check_args(int argc, char *argv[], t_fractal *fractal);
static void		mlx_interface_init(t_mlx_interface *interface);

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	fractal.fractal_data.color = 0xFFFF0000;
	check_args(argc, argv, &fractal);
	fractal_init(&fractal);
	iterate_img(&fractal);
	mlx_put_image_to_window(fractal.mlx_interface.mlx_connection,
			fractal.mlx_interface.mlx_window,
			fractal.mlx_interface.img.context, 0, 0);
	mlx_loop(fractal.mlx_interface.mlx_connection);
	mlx_destroy_display(fractal.mlx_interface.mlx_connection);
	free(fractal.mlx_interface.mlx_connection);
	return (EXIT_SUCCESS);
}

static void	check_args(int argc, char *argv[], t_fractal *fractal)
{
	int format_error1;
	int format_error2;

	if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 11) == 0)
	{
		fractal->fractal_data.type = mandel;
		return ;
	}
	if (argc == 4 && ft_strncmp(argv[1], "julia", 6) == 0)
	{
		fractal->fractal_data.type = julia;
		fractal->fractal_data.julia_cte =
				(t_complex){ft_atod_signal(argv[2], &format_error1),
				ft_atod_signal(argv[3], &format_error2)};
		if (format_error1 || format_error2)
			ft_putstr_fd("Error en los parámetros de julia\n");
		else
			return ;
	}
	exit(EXIT_FAILURE);
}

void	fractal_init(t_fractal *fractal)
{
	mlx_interface_init(&fractal->mlx_interface);
	fractal_data_init(&fractal->fractal_data);
	hook_setter(fractal);
}

void	mlx_interface_init(t_mlx_interface *interface)
{
	interface->mlx_connection = mlx_init();
	if (NULL == interface->mlx_connection)
		malloc_error();
	interface->mlx_window = mlx_new_window(interface->mlx_connection,
			WIDTH, HEIGHT, "fractal");
	if (NULL == interface->mlx_window)
	{
		mlx_destroy_display(interface->mlx_connection);
		free(interface->mlx_connection);
		malloc_error();
	}
	interface->img.context = mlx_new_image(interface->mlx_connection,
			WIDTH, HEIGHT);
	if (NULL == interface->img.context)
	{
		mlx_destroy_window(interface->mlx_connection, interface->mlx_window);
		mlx_destroy_display(interface->mlx_connection);
		free(interface->mlx_connection);
		malloc_error();
	}
	interface->img.pixels = mlx_get_data_addr(interface->img.context,
			&interface->img.bpp, &interface->img.line_len, &interface->img.endian);
}

static void	fractal_data_init(t_fractal_data *data)
{
	data->vertex = (t_complex){0, 0};
	data->complex_width = 5;
	data->complex_height = 5;
}

static void	malloc_error(void)
{
	perror("Fallo de malloc\n");
	exit(EXIT_FAILURE);
}
