/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:22:43 by fmontero          #+#    #+#             */
/*   Updated: 2024/11/17 17:04:37 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void		fractal_init(t_fractal *fractal);
void		fractal_data_init(t_fractal_data *data);
void		malloc_error(void);
void		check_args(int argc, char *argv[], t_fractal *fractal);
void		mlx_interface_init(t_mlx_interface *interface);

void	check_args(int argc, char *argv[], t_fractal *fractal)
{
	int	format_error[2];

	if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 11) == 0)
	{
		fractal->data.type = mandel;
		return ;
	}
	else if (argc == 4 && ft_strncmp(argv[1], "julia", 6) == 0)
	{
		fractal->data.type = julia;
		fractal->data.julia_cte
			= (t_complex){ft_atod_signal(argv[2], &format_error[0]),
			ft_atod_signal(argv[3], &format_error[1])};
		if (!format_error[0] && !format_error[1])
			return ;
	}
	ft_putstr_fd(ERROR_MESSAGE, 2);
	exit(EXIT_FAILURE);
}

void	fractal_init(t_fractal *fractal)
{
	mlx_interface_init(&fractal->mlx_interface);
	fractal_data_init(&fractal->data);
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
			&interface->img.bpp, &interface->img.line_len,
			&interface->img.endian);
}

void	fractal_data_init(t_fractal_data *data)
{
	data->vertex = (t_complex){INITIAL_VERTEX_RE, INITIAL_VERTEX_IM};
	data->complex_width = INITIAL_COMPLEX_WIDTH;
	data->complex_height = INITIAL_COMPLEX_HEIGHT;
	data->zoom = ZOOM_FACTOR;
	data->escape_limit = INITIAL_ESCAPE_LIMIT;
	data->button4_ctr = 2;
	data->button5_ctr = 2;
	data->color_map = get_color;
}

void	malloc_error(void)
{
	ft_putstr_fd("Fallo de malloc\n", 2);
	exit(EXIT_FAILURE);
}
