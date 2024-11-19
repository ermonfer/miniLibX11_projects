/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:55:26 by fmontero          #+#    #+#             */
/*   Updated: 2024/11/17 17:45:14 by fmontero         ###   ########.fr       */
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
# define INITIAL_ESCAPE_LIMIT 80U
# define INITIAL_VERTEX_RE -2.15
# define INITIAL_VERTEX_IM 1.5
# define INITIAL_COMPLEX_WIDTH 3.0
# define INITIAL_COMPLEX_HEIGHT 3.0
# define ZOOM_FACTOR 1.05
# define ERROR_MESSAGE "Valid inputs:\nmandelbrot\njulia c.re c.im\ntricorn\n"

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

typedef unsigned int		t_uint;
typedef struct s_fractal	t_fractal;

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
	julia,
	tricorn
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
	unsigned int	escape_limit;
	t_complex		vertex;
	double			complex_width;
	double			complex_height;
	t_complex		julia_cte;
	double			zoom;
	int				last_x;
	int				last_y;
	unsigned char	button4_ctr;
	unsigned char	button5_ctr;
	unsigned int	(*color_map)(t_complex z, t_fractal *fractal);
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

typedef struct s_traslation_table
{
	int			pixel_x;
	int			pixel_y;
	int			step_x;
	int			step_y;
	int			limit_x;
	int			limit_y;
	char		*byte_iter;
	t_complex	complex_iter;
	t_complex	complex_step;
	int			offset;
}	t_traslation_table;

typedef struct s_temperature_map_data
{
	unsigned int	color;
	double			intensity;
	double			t;
	int				segment;
	int				local_t;
	double			*beg;
	double			*end;
	double			r;
	double			g;
	double			b;
}	t_temperature_map_data;

double			lerp(double target, double old[2], double new[2]);

void			hook_setter(t_fractal *fractal);
void			iterate_img(t_fractal *fractal);
unsigned int	get_color(t_complex z, t_fractal *fractal);
unsigned int	gray_scale(t_complex z, t_fractal *fractal);
unsigned int	temperature_map(t_complex z, t_fractal *fractal);

void			increase_escape_limit_handler(t_fractal *data);
void			decrease_escape_limit_handler(t_fractal *data);
int				reset_vertex_handler(t_fractal *fractal);
void			reset_escape_limit_handler(t_fractal *fractal);
void			change_color_handler(t_fractal *fractal);

int				mouse_push_handler(int button, int x, int y,
					t_fractal *fractal);
int				mouse_release_handler(int button, int x, int y,
					t_fractal *fractal);
int				drag_handler(int x, int y, t_fractal *fractal);
void			zoom_in_handler(t_complex cursor, t_fractal *fractal);
void			zoom_out_handler(t_complex cursor, t_fractal *fractal);
#endif
