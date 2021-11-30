/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 08:14:34 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/30 15:30:04 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
*	simple function to prevent leaks the mlx_string_put
*/
char	*strjoin_free(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	free(s2);
	return (str);
}

/*
*	Always visible information in the top and lower left
*	corners of the window.
*	Shows the number of iterations, the zoom level and RGB values.
*/
void	text_to_image(t_fractol *f)
{
	char	*str;
	str = strjoin_free("ITERATIONS: ", ft_itoa(f->fractal.max_iter));
	mlx_string_put(f->mlx.init, f->mlx.win, 10, 675, 0xFFFFFF, str);
	free (str);
	str = strjoin_free("ZOOM LEVEL: ", ft_itoa(f->fractal.scale));
	mlx_string_put(f->mlx.init, f->mlx.win, 10, 695, 0xFFFFFF, str);
	free (str);
	str = strjoin_free("RED  : ", ft_itoa(f->color.red));
	mlx_string_put(f->mlx.init, f->mlx.win, 10, 20, 0xFFFFFF, str);
	free (str);
	str = strjoin_free("GREEN: ", ft_itoa(f->color.green));
	mlx_string_put(f->mlx.init, f->mlx.win, 10, 35, 0xFFFFFF, str);
	free (str);
	str = strjoin_free("BLUE : ", ft_itoa(f->color.blue));
	mlx_string_put(f->mlx.init, f->mlx.win, 10, 50, 0xFFFFFF, str);
	free (str);
	show_menu(f);
}

/*
*	Function to, by default, only show "Z - SHOW MENU"
*	in the lower left corner.
*	Pressing X brings up the control menu
*/
void	show_menu(t_fractol *f)
{
	char	*str;

	 if (f->mlx.show_menu== 0)
	{
		str = "Z - SHOW MENU";
		mlx_string_put(f->mlx.init, f->mlx.win, 10, 600, 0xFFFFFF, str);
	}
	else
	{
		str = "X - HIDE MENU";
		mlx_string_put(f->mlx.init, f->mlx.win, 10, 600, 0xFFFFFF, str);
		str = "ARROWS | WASD - MOVE FRACTAL";
		mlx_string_put(f->mlx.init, f->mlx.win, 980, 30, 0xFFFFFF, str);
		str = "J - INCREASE ITERATIONS";
		mlx_string_put(f->mlx.init, f->mlx.win, 980, 50, 0xFFFFFF, str);
		str = "K - DECREASE ITERATIONS";
		mlx_string_put(f->mlx.init, f->mlx.win, 980, 70, 0xFFFFFF, str);
		str = "SPACE - RANDOM COLORS";
		mlx_string_put(f->mlx.init, f->mlx.win, 980, 90, 0xFFFFFF, str);
		str = "R - RESET FRACTAL";
		mlx_string_put(f->mlx.init, f->mlx.win, 980, 110, 0xFFFFFF, str);
		str = "ESC - EXIT PROGRAM";
		mlx_string_put(f->mlx.init, f->mlx.win, 980, 130, 0xFFFFFF, str);
	}
}
