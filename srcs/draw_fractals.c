/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 09:58:16 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/02 10:58:50 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	create_threads(t_fractol *f)
{
	t_fractol	cpy[6];
	pthread_t	t_id[6];
	int			i;

	i = 0;
	while (i < 6)
	{
		ft_memcpy((void *)&cpy[i], (void *)f, sizeof(t_fractol));
		cpy[i].thread.x = ((double)(1.00 / 6)*WINW) * i;
		cpy[i].thread.max = ((double)(1.00 / 6)*WINW) * (i + 1);
		cpy[i].thread.y = 0;
		i++;
	}
	i = 0;
	while (i < 6)
	{
		pthread_create(&t_id[i], NULL, pixel_draw, &cpy[i]);
		i++;
	}
	while (i >= 0)
	{
		pthread_join(t_id[i], NULL);
		i--;
	}
}

/*
**	Function that updates the value seen in the window dynamically
*/
void	fractal_updater(t_fractol *f)
{
	if (f->fractal.max_iter <= 1)
		f->fractal.max_iter = 1;
	create_threads(f);
	mlx_put_image_to_window(f->mlx.init, f->mlx.win, f->mlx.img, 0, 0);
	text_to_image(f);
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
void	*pixel_draw(void *cpy)
{
	t_fractol	*f;
	int			temp_x;
	int			color;

	f = (t_fractol *)cpy;
	f->thread.y = 0;
	temp_x = f->thread.x;
	while (f->thread.y < WINH)
	{
		f->thread.x = temp_x;
		while (f->thread.x < f->thread.max)
		{
			if (f->fractal.type == 1)
				color = mandelbrot(f, f->thread.x, f->thread.y);
			else if (f->fractal.type == 2)
				color = julia(f, f->thread.x, f->thread.y);
			else if (f->fractal.type == 3)
				color = burning_ship(f, f->thread.x, f->thread.y);
			put_pixel(f, f->thread.x, f->thread.y, color);
			f->thread.x++;
		}
		f->thread.y++;
	}
	return (cpy);
}
