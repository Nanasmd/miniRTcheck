/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message3_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 20:35:22 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/24 21:42:25 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	error_camera_fov_out_of_bounds(void)
{
	error("FOV coefficient out of bounds [0.0,1.0]");
}

void	error_light_brightness_out_of_bounds(void)
{
	error("Light brightness out of bounds [0.0,1.0]");
}

float	ratio(void)
{
	return (16.0 / 9.0);
}

int	height(void)
{
	return (WIDTH / ratio());
}
