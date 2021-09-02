/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 21:03:36 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/02 11:12:47 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <pthread.h>
# include "../includes/keys.h"
# include "../includes/mousekeys.h"
# include "../libft/libft.h"

# define WINW (1280)
# define WINH (720)

/*
*	s_mlx are the required minilibx arguments
*	init = initialise connection between software and display 
*	img = pointer to image data
*	win = pointer to created window 
*/
typedef struct s_mlx
{
	void	*init;
	void	*img;
	void	*win;
	char	*data;
	int		line_s;
	int		endian;
	int		bpp;
	int		show_menu;
}				t_mlx;

/*
*	Coordinates of the fractal inside the plane
*/
typedef struct s_map
{
	double	xmin;
	double	xmax;
	double	ymax;
	double	ymin;
}				t_map;

/*
*	Colors the fractals (24-bits RGB)
*/
typedef struct s_color
{
	int	def_color;
	int	red;
	int	green;
	int	blue;
}				t_color;

/*
*	Some info for the fractal
*	type = Type of the fractal passed in the arguments
*	max_iter = Maximum iteration for the fractals.
*			   More iterations = more details.
*	iter = Number of iterations before value escapes to infinity
*		   Colors depends on the number of iterations.
*/
typedef struct s_type
{
	int		type;
	int		max_iter;
	int		iter;
	double	scale;
}				t_type;

/*
*	Struct for the mouse info needed for Events and Mouse_look feature
*/
typedef struct s_mouse
{
	double	x;
	double	y;
	int		move;
	int		x_pos;
	int		y_pos;
}				t_mouse;

/*
*	Real and Imaginary parts of each variable for the
*	fractals algorithms
*	f(z) = z^2 + c
*/
typedef struct s_complex
{
	long double		z_real;
	long double		z_im;
	long double		c_real;
	long double		c_im;
}				t_complex;

typedef struct s_threads
{
	double	x;
	double	y;
	double	max;
}	t_threads;

/* 
*	The master Struct that contains all the other structures 
*/
typedef struct s_fractol
{
	t_map			map;
	t_complex		c;
	t_mlx			mlx;
	t_color			color;
	t_type			fractal;
	t_mouse			mouse;
	t_threads		thread;
}				t_fractol;

/*
*	General Functions
*/

void		create_mlx_link(t_fractol *f, char **argv);
void		argument_checker(t_fractol *f, char **argv, int argc);
void		fractal_checker(t_fractol *f, char *fractal);
void		put_pixel(t_fractol *f, int x, int y, int iter);
void		*pixel_draw(void *cpy);
void		exit_programm(t_fractol *f);
void		color_randomizer(t_fractol *f);
void		fractal_updater(t_fractol *f);
void		show_menu(t_fractol *f);
void		text_to_image(t_fractol *f);
void		show_manual(void);
void		mouse_mover_values(t_fractol *f);
int			error_type(int n);
int			mouse_hooks(int key, int x, int y, t_fractol *f);
int			mouse_mover(int x, int y, t_fractol *f);
int			ft_keypress(int key, t_fractol *f);
int			ft_keypress2(int key, t_fractol *f);
int			zoom_out(int x, int y, t_fractol *f);
int			zoom_in(int x, int y, t_fractol *f);

/*  
*	FRACTALS INITIAL VALUES FUNCTIONS
*/
void		init_mandelbrot(t_fractol *f);
void		init_julia(t_fractol *f);
void		init_burningship(t_fractol *f);

/*
*	FRACTALS ALGO
*/
int			mandelbrot(t_fractol *f, int x, int y);
int			julia(t_fractol *f, int x, int y);
int			burning_ship(t_fractol *f, int x, int y);

#endif