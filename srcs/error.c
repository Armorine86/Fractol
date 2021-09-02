/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 12:59:08 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/02 11:09:48 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
*	List of parameters and commands if you type
*	a wrong parameter in the terminal.
*/
void	show_manual(void)
{
	ft_putstr("\n\033[32m------------------\n");
	ft_putstr("\033[32mAvailable Fractals\n");
	ft_putstr("\033[32m------------------\n");
	ft_putstr("\n\033[34m./fractol <fractal>\n\n");
	ft_putstr("\033[36mmandelbrot || julia || burningship\n");
	ft_putstr("Add \033[4mmouse_look\033[0m after the name, \
	and see what it does! :)\n");
	ft_putstr("I.E: \033[34m./fractol \033[31mmandelbrot mouse_look\n\033[0m");
	ft_putstr("\033[35m\n/--------------------------\\\n");
	ft_putstr("| LIST OF COMMANDS         |\n");
	ft_putstr("|--------------------------|\n");
	ft_putstr("| Z - OPEN MENU            |\n");
	ft_putstr("| R - RESET FRACTAL        |\n");
	ft_putstr("| J - INCREASE ITERATIONS  |\n");
	ft_putstr("| K - DECREASE ITERATIONS  |\n");
	ft_putstr("| WHEEL - ZOOM IN AND OUT  |\n");
	ft_putstr("| SPACE - RANDOM COLORS    |\n");
	ft_putstr("| ESC - EXIT PROGRAM       |\n");
	ft_putstr("\\--------------------------/\n\n");
	exit (0);
}

/*
*	Function that return an error code depending on what went wrong
*/
int	error_type(int n)
{
	if (n == -1)
		ft_putstr("Memory Allocation failed");
	else if (n == -2)
		ft_putstr("Mlx initialisation failed");
	else if (n == -3)
	{
		ft_putstr("\nBad parameter entry\n");
		ft_putstr("Please choose a valid fractal\n");
		ft_putstr("./fractol <fractal> mandelbrot | julia | burningship\n\n");
	}
	exit (n);
}
