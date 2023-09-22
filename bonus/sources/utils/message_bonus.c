/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:26:23 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:26:24 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	message(t_world *world, char *text)
{
	destroy_world(&world);
	if (text)
		ERROR(text);
	exit(EXIT_FAILURE);
}

void	display(t_world *w, t_xy xy, int color, char *text)
{
	mlx_string_put(w->disp.mlx, w->disp.win, xy.x, xy.y, color, text);
}
