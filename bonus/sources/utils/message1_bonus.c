/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:26:23 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/24 20:15:31 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	message(t_world *world, char *text)
{
	destroy_world(&world);
	if (text)
		error(text);
	exit(EXIT_FAILURE);
}

void	display(t_world *w, t_xy xy, int color, char *text)
{
	mlx_string_put(w->disp.mlx, w->disp.win, xy.x, xy.y, color, text);
}

void	error(const char *m)
{
	printf("Error\n%s\n", m);
}

void	error_num_args(const char *x, const char *n)
{
	printf("Error\n");
	printf("Wrong number of args in %s (need %s)\n", x, n);
}

void	error_num_commas(const char *x)
{
	printf("Error\n");
	printf("Too many/few commas in %s\n", x);
}
