/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_rotate_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:27:13 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:27:14 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	vec3_rotate(t_vec3 vec, int axis, double angle)
{
	t_vec3	rotated;

	rotated = vec;
	if (axis == X)
	{
		rotated.y = vec.y * cos(angle) - vec.z * sin(angle);
		rotated.z = vec.y * sin(angle) + vec.z * cos(angle);
	}
	else if (axis == Y)
	{
		rotated.x = vec.x * cos(angle) + vec.z * sin(angle);
		rotated.z = -vec.x * sin(angle) + vec.z * cos(angle);
	}
	else if (axis == Z)
	{
		rotated.x = vec.x * cos(angle) - vec.y * sin(angle);
		rotated.y = vec.x * sin(angle) + vec.y * cos(angle);
	}
	return (vec3_normalize(rotated));
}
