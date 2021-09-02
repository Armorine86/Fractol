/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:34:42 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/02 10:40:20 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
**	Function to dynamically change the values of 
**	z_real and z_im in the fractal formula to
**	morph the fractal with the mouse position
*/
int	mouse_mover(int x, int y, t_fractol *f)
{
	f->mouse.x_pos = x;
	f->mouse.y_pos = y;
	f->c.z_real = f->mouse.x_pos;
	f->c.z_im = f->mouse.y_pos;
	fractal_updater(f);
	return (0);
}

int	zoom_out(int x, int y, t_fractol *f)
{
	f->mouse.x = x * (f->map.xmax - f->map.xmin) / WINW + f->map.xmin;
	f->mouse.y = y * (f->map.ymax - f->map.ymin) / WINH + f->map.ymin;
	f->map.xmax = f->map.xmax * 0.9 + f->mouse.x * 0.1;
	f->map.xmin = f->map.xmin * 0.9 + f->mouse.x * 0.1;
	f->map.ymax = f->map.ymax * 0.9 + f->mouse.y * 0.1;
	f->map.ymin = f->map.ymin * 0.9 + f->mouse.y * 0.1;
	f->fractal.scale += 0.5;
	fractal_updater(f);
	return (0);
}

/*
**	Mathematic formula to keep the scale of the fractal
**	as you zoom in and out.
**	mouse_x and mouse_y get the pointer coordinates to zoom
**	at cursor position
*/
int	zoom_in(int x, int y, t_fractol *f)
{
	f->mouse.x = x * (f->map.xmax - f->map.xmin) / WINW + f->map.xmin;
	f->mouse.y = y * (f->map.ymax - f->map.ymin) / WINH + f->map.ymin;
	f->map.xmax = f->map.xmax * 1.1 + f->mouse.x * -0.1;
	f->map.xmin = f->map.xmin * 1.1 + f->mouse.x * -0.1;
	f->map.ymax = f->map.ymax * 1.1 + f->mouse.y * -0.1;
	f->map.ymin = f->map.ymin * 1.1 + f->mouse.y * -0.1;
	f->fractal.scale -= 0.5;
	fractal_updater(f);
	return (0);
}

/*
**	Mouse events for Wheel zoom and the mouse_look feature
*/
int	mouse_hooks(int key, int x, int y, t_fractol *f)
{
	if (f->mouse.move == 1)
		mouse_mover(x, y, f);
	if (key == MOUSE_UP_SCRLL)
		zoom_in(x, y, f);
	if (key == MOUSE_DOWN_SCRLL)
		zoom_out(x, y, f);
	return (0);
}
