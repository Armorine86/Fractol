/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 09:58:16 by mmondell          #+#    #+#             */
/*   Updated: 2021/07/09 10:02:30 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
**	Function that updates the value seen in the window dynamically
*/
void	fractal_updater(t_fractol *f)
{
	if (f->fractal.max_iter <= 1)
		f->fractal.max_iter = 1;
	next_image(f);
	text_to_image(f);
}

/*
**	Function to clear the image and replace it with a new one
**	at every loop iterations
*/
void	next_image(t_fractol *f)
{
	mlx_clear_window(f->mlx.init, f->mlx.win);
	pixel_draw(f);
	mlx_put_image_to_window(f->mlx.init, f->mlx.win, f->mlx.img, 0, 0);
}

/*
**	Limits the pixel draw to the min and max size of the window
**	if the iteration equals the number of the fractal max iteration
**	paint the pixel black. (The actual fractal set)
**	otherwise give each RGB a different color value.
**	RGB values have been tinkered to give a color I liked
*/
void	put_pixel(t_fractol *f, int x, int y, int iter)
{
	if (x >= 0 && x <= WINW && y >= 0 && y <= WINH)
	{
		if (iter == f->fractal.max_iter)
		{
			f->mlx.data[(x * 4) + (y * WINW * 4) + 2] = f->color.red * 0;
			f->mlx.data[(x * 4) + (y * WINW * 4) + 1] = f->color.green * 0;
			f->mlx.data[(x * 4) + (y * WINW * 4)] = f->color.blue * 0;
		}
		else
		{
			f->mlx.data[(x * 4) + (y * WINW * 4) + 2] = f->color.red
				+ (iter * 2) % 256;
			f->mlx.data[(x * 4) + (y * WINW * 4) + 1] = f->color.green
				+ (iter * 5) % 256;
			f->mlx.data[(x * 4) + (y * WINW * 4)] = f->color.blue
				+ (iter * 3) % 256;
		}
	}
}

/*
**	Function to draw each pixel starting at top left corner (0, 0)
**	and giving a different color depending on the number of iterations
**	of starting coordinates before it escapes to inifinty.
**	That gives the fractals the beautiful colors.
*/
void	pixel_draw(t_fractol *f)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < WINH)
	{
		x = 0;
		while (x < WINW)
		{
			if (f->fractal.type == 1)
				color = mandelbrot(f, x, y);
			else if (f->fractal.type == 2)
				color = julia(f, x, y);
			else if (f->fractal.type == 3)
				color = burning_ship(f, x, y);
			put_pixel(f, x, y, color);
			x++;
		}
		y++;
	}
}
