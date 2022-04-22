/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:18:44 by mmondell          #+#    #+#             */
/*   Updated: 2022/04/22 11:33:35 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	reset_values(t_fractol *f)
{
	if (f->fractal.type == 1)
		init_mandelbrot(f);
	else if (f->fractal.type == 2)
		init_julia(f);
	else if (f->fractal.type == 3)
		init_burningship(f);
}

void	color_randomizer(t_fractol *f)
{
	f->color.def_color = 0;
	f->color.red = rand() % 150;
	f->color.green = rand() % 150;
	f->color.blue = rand() % 150;
}

int	ft_keypress2(int key, t_fractol *f)
{
	if (key == KEY_J)
		f->fractal.max_iter += 1;
	else if (key == KEY_K)
		f->fractal.max_iter -= 1;
	else if (key == KEY_SPACE)
		color_randomizer(f);
	else if (key == KEY_R)
		reset_values(f);
	else if (key == KEY_ESCAPE)
		exit_programm(f);
	else if (key == KEY_Z)
		f->mlx.show_menu = 1;
	else if (key == KEY_X)
		f->mlx.show_menu = 0;
	fractal_updater(f);
	return (0);
}

/*	
*	Each key pressed on the keyboard is assigned to a code 
*	defined in keys.h. The chosen keys are then mapped to
*	different task for the program.
*/
int	ft_keypress(int key, t_fractol *f)
{
	if (key == KEY_A || key == KEY_LEFTARROW)
	{
		f->map.xmin -= 0.01;
		f->map.xmax -= 0.01;
	}
	else if (key == KEY_D || key == KEY_RIGHTARROW)
	{
		f->map.xmin += 0.01;
		f->map.xmax += 0.01;
	}
	else if (key == KEY_W || key == KEY_UPARROW)
	{
		f->map.ymin -= 0.01;
		f->map.ymax -= 0.01;
	}
	else if (key == KEY_S || key == KEY_DOWNARROW)
	{
		f->map.ymin += 0.01;
		f->map.ymax += 0.01;
	}
	else
		ft_keypress2(key, f);
	fractal_updater(f);
	return (0);
}
