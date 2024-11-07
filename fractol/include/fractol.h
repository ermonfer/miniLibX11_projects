/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:55:26 by fmontero          #+#    #+#             */
/*   Updated: 2024/11/07 22:42:14 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <unistd.h>
# include <math.h>
# include <errno.h>
# include "../mlx_linux/mlx.h"
# include "../lib/libft/include/libft.h"

# define WIDTH 800
# define HEIGHT 800
# define ERROR_MESSAGE "mensaje de error generico"

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_img
{
	void	*context;
	char	*pixels;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef enum e_fractal_type
{
	mandel,
	julia
}	t_fractal_type;

typedef struct s_fractal_data
{
	int color;
	t_fractal_type	type;
// 	double		escape;
	t_complex	vertex;
	double		x_len;
	double		y_len;
// 	//double	zoom; ???
// 	t_complex	z;
// 	t_complex	c;
}	t_fractal_data;

typedef struct s_mlx_interface
{
	void			*mlx_connection;
	void			*mlx_window;
	t_img			img;
}	t_mlx_interface;

typedef struct s_fractal
{
	t_mlx_interface	mlx_interface;
	t_fractal_data	fractal_data;
}	t_fractal;


typedef struct s_render_iterators
{
	t_complex	complex_iter;
	t_complex	complex_step;
	char		*byte_iter;
	int			pixel_x;
	int			pixel_y;
}	t_render_iterators;

void	hook_setter(t_fractal *fractal);
void	iterate_img(t_fractal *fractal);
#endif
