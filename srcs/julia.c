/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:21:43 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/02 08:51:34 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
 *	Mathematic formula for the julia fractal
 *	z_real and z_im have been tinkered so that Julia
 *	gives a look that I liked.
 */
int julia(t_fractol *f, int x, int y)
{
	long double tmp_c;

	f->c.z_real = (f->mouse.x_pos - WINW) / ((long double)WINW * 2) - 0.204756;
	f->c.z_im = (f->mouse.y_pos - WINH) / ((long double)WINH) + 0.63;
	f->fractal.iter = 0;
	f->c.c_real = f->map.xmin + (f->map.xmax - f->map.xmin) * x / WINW;
	f->c.c_im = f->map.ymin + (f->map.ymax - f->map.ymin) * y / WINH;
	while (f->fractal.iter < f->fractal.max_iter)
	{
		tmp_c = (f->c.c_real * f->c.c_real) - (f->c.c_im * f->c.c_im) + f->c.z_real;
		f->c.c_im = 2 * f->c.c_real * f->c.c_im + f->c.z_im;
		f->c.c_real = tmp_c;
		if ((f->c.c_real * f->c.c_real) + (f->c.c_im * f->c.c_im) > 4.0f)
			break;
		f->fractal.iter++;
	}
	return (f->fractal.iter);
}
