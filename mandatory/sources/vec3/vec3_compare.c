/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_compare.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:18:07 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/24 17:05:33 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	vec3_compare(t_vec3 v1, t_vec3 v2)
{
	return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z);
}

bool	is_vec3_in_range(t_vec3 vec, double min, double max)
{
	return (vec.x >= min && vec.x <= max
		&& vec.y >= min && vec.y <= max
		&& vec.z >= min && vec.z <= max);
}
