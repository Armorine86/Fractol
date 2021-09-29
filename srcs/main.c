/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 10:39:15 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/09 09:55:48 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
*	Check for mouse_look arguments and makes sure
*	the third argument is actually a valid one
*	if not, it shows the manual for valid parameters
*/
void	argument_checker(t_fractol *f, char **argv, int argc)
{
	if (argc == 3 && !ft_strncmp(argv[2], "mouse_look", 11))
	{
		f->mouse.move = 1;
		mlx_hook(f->mlx.win, 6, 3, mouse_mover, f);
	}
	else if (argc == 3 && ft_strncmp(argv[2], "mouse_look", 11))
		show_manual();
	else
		fractal_checker(f, argv[1]);
}

/*
*	Basic function to kill Image and Window and
*	Exit the programm
*/
void	exit_programm(t_fractol *f)
{
	mlx_destroy_image(f->mlx.init, f->mlx.img);
	mlx_destroy_window(f->mlx.init, f->mlx.win);
	free (f);
	exit (0);
}

/*
*	Compares argument passed in program parameters
*	And if equals = 0, init all the base values of
*	the different fractals
*/
void	fractal_checker(t_fractol *f, char *fractal)
{
	if (!ft_strncmp(fractal, "mandelbrot", 11))
		init_mandelbrot(f);
	else if (!ft_strncmp(fractal, "julia", 6))
		init_julia(f);
	else if (!ft_strncmp(fractal, "burningship", 12))
		init_burningship(f);
	else
		error_type(-3);
}

/*
*	Creates all the mlx pointers and dependencies
*	Assign pointers to all mlx functions in the mlx struct.
*/
void	create_mlx_link(t_fractol *f, char **argv)
{
	f->mlx.init = mlx_init();
	if (!f->mlx.init)
		error_type(-2);
	f->mlx.win = mlx_new_window(f->mlx.init, WINW, WINH, argv[1]);
	if (!f->mlx.win)
		error_type(-2);
	f->mlx.img = mlx_new_image(f->mlx.init, WINW, WINH);
	if (!f->mlx.img)
		error_type(-2);
	f->mlx.data = mlx_get_data_addr(f->mlx.img, &f->mlx.bpp,
			&f-> mlx.line_s, &f->mlx.endian);
}

/*
*	MAIN FUNCTION
*/
int	main(int argc, char **argv)
{
	t_fractol	*f;

	if (argc >= 2 && argc <= 3)
	{
		f = (t_fractol *)malloc(sizeof(t_fractol));
		if (!f)
			error_type(-1);
		fractal_checker(f, argv[1]);
		create_mlx_link(f, argv);
		argument_checker(f, argv, argc);
		fractal_updater(f);
		mlx_hook(f->mlx.win, 2, 3, ft_keypress, f);
		mlx_mouse_hook(f->mlx.win, mouse_hooks, f);
		show_menu(f);
		mlx_loop(f->mlx.init);
	}
	else
		show_manual();
	return (0);
}
