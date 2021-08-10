/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:22:09 by mmondell          #+#    #+#             */
/*   Updated: 2021/07/09 09:35:48 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
**	Mathematic formula for the Burning Ship fractal
**	z_real and z_im have been tinkered to exactly equals 0
** 	so when you type ./fractol <fractal>, the image is seen as intended
*/
int	burning_ship(t_fractol *f, int x, int y)
{
	double		tmp_z;

	f->fractal.iter = 0;
	f->c.z_real = (f->mouse.x_pos - WINW) / ((double) WINW * 2) + 0.25;
	f->c.z_im = (f->mouse.y_pos - WINH) / ((double) WINH) + 0.5;
	f->c.c_real = f->map.xmin + (f->map.xmax - f->map.xmin)
		* x / WINW;
	f->c.c_im = f->map.ymin + (f->map.ymax - f->map.ymin)
		* y / WINH;
	while (f->fractal.iter < f->fractal.max_iter)
	{
		tmp_z = ((f->c.z_real * f->c.z_real)
				- (f->c.z_im * f->c.z_im)) + f->c.c_real;
		f->c.z_im = fabsl(2.0 * f->c.z_real * f->c.z_im + f->c.c_im);
		f->c.z_real = fabsl(tmp_z);
		if ((f->c.z_real * f->c.z_real)
			 + (f->c.z_im * f->c.z_im) > 4.0f)
			break ;
		f->fractal.iter++;
	}
	return (f->fractal.iter);
}
