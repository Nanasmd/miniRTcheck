/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:11:59 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/24 19:55:06 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	green(void)
{
	return ((t_color){0, 0, 255, 0});
}

t_color	yellow(void)
{
	return ((t_color){0, 255, 255, 0});
}

t_color	pink(void)
{
	return ((t_color){0, 255, 0, 255});
}

t_color	cyan(void)
{
	return ((t_color){0, 0, 255, 255});
}

void	error_ambient_ratio_out_of_bounds(const char *x)
{
	printf("Error\nAmbient coefficient out of bounds in %s [0.0,1.0]\n", x);
}
