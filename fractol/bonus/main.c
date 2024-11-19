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

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

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
