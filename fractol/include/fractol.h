/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-31 14:55:26 by fmontero          #+#    #+#             */
/*   Updated: 2024-10-31 14:55:26 by fmontero         ###   ########.fr       */
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

# define WIDTH 800
# define HEIGHT 800
# define ERROR_MESSAGE "mensaje de error generico"

typedef struct	s_complex
{
	double re;
	double im;
}	t_complex;


typedef struct	s_img
{
	void	*img_ptr;
	char	*pixels;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
}	t_fractal;

void	fractal_init(t_fractal *fractal);
void	hook_setter(t_fractal *fractal);
#endif
