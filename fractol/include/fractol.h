/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:55:26 by fmontero          #+#    #+#             */
/*   Updated: 2024/11/14 09:06:41 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <unistd.h>
# include "../mlx_linux/mlx.h"
# include "../lib/libft/include/libft.h"
# include "../lib/libft/include/extra.h"

# define WIDTH 900
# define HEIGHT 900
# define ESCAPE_VALUE 100
# define ZOOM_FACTOR 1.05
# define ERROR_MESSAGE "mensaje de error generico"

# define BLACK       		0xFF000000
# define WHITE       		0xFFFFFFFF
# define NEON_ORANGE     	0xFFFF6600
# define PSYCHEDELIC_PURPLE	0xFF660066
# define AQUA_DREAM			0xFF33CCCC
# define HOT_PINK        	0xFFE55982 
# define CYAN_ELECTRIC		0xFFFF2CFF
# define MCDONALDS			0xFFFFC72C
# define SUPER_YELLOW		0xFFFCBE11
# define PNKY_PASTEL		0xFFFFC4D6
# define CUTE_GREEN			0xFFC1E378
# define BRAT_GREEN			0xFF8ACE00
# define NOMAI_PURPLE		0xFF787EFE

typedef unsigned int	t_uint;

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

typedef enum e_movement
{
	move_right,
	move_left,
	move_up,
	move_down
}	t_movement;

typedef struct s_fractal_data
{
	t_fractal_type	type;
	double			escape_limit;
	t_complex		vertex;
	double			complex_width;
	double			complex_height;
	t_complex		julia_cte;
	double			zoom;
	int				last_x;
	int				last_y;
	unsigned char	button4_ctr;
	unsigned char	button5_ctr;
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
	t_fractal_data	data;
}	t_fractal;

typedef struct s_render_iterators
{
	t_complex	complex_iter;
	t_complex	complex_step;
	char		*byte_iter;
	int			pixel_x;
	int			pixel_y;
}	t_render_iterators;

void		hook_setter(t_fractal *fractal);
void		iterate_img(t_fractal *fractal);
t_complex	complex_sum(t_complex a, t_complex b);
t_complex	complex_square(t_complex z);
double		complex_module(t_complex z);
double		lerp(double target, double old[2], double new[2]);
#endif
