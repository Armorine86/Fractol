/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 09:45:11 by mmondell          #+#    #+#             */
/*   Updated: 2021/07/09 10:03:53 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
**	Initiates all different fractals base values 
**	to be rightly seen in the window 
**	such as Colors, max iterations, position in the plane, etc.
*/
void	init_mandelbrot(t_fractol *f)
{
	f->mlx.show_menu = 0;
	f->fractal.max_iter = 60;
	f->mouse.x_pos = WINW / 2;
	f->mouse.y_pos = WINH / 2;
	f->map.xmin = -2.2f;
	f->map.xmax = 1.2f;
	f->map.ymax = 1.2f;
	f->map.ymin = -1.2f;
	f->color.red = 12;
	f->color.green = 2;
	f->color.blue = 24;
	f->fractal.scale = 1.1f;
	f->fractal.type = 1;
	f->color.def_color = 1;
}

void	init_julia(t_fractol *f)
{
	f->mlx.show_menu = 0;
	f->fractal.max_iter = 60;
	f->map.xmin = -1.7f;
	f->map.xmax = 1.7f;
	f->map.ymax = 1.5f;
	f->map.ymin = -1.5f;
	f->color.red = 12;
	f->color.green = 4;
	f->color.blue = 2;
	f->fractal.scale = 1;
	f->fractal.type = 2;
	f->color.def_color = 1;
}

void	init_burningship(t_fractol *f)
{
	f->mlx.show_menu = 0;
	f->fractal.max_iter = 60;
	f->map.xmin = -1.8f;
	f->map.xmax = 1.5f;
	f->map.ymax = 0.7f;
	f->map.ymin = -1.7f;
	f->color.red = 161;
	f->color.green = 49;
	f->color.blue = 28;
	f->fractal.scale = 1;
	f->fractal.type = 3;
	f->color.def_color = 1;
}
