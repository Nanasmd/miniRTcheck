/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:16:20 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/25 10:08:25 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_plane	plane_from_numbers(t_vec3 center, t_vec3 normal, t_color color)
{
	t_plane	plane;

	plane = (t_plane)
	{
		.center = center,
		.normal = normal,
		.color = color
	};
	return (plane);
}

bool	plane_from_strings(t_plane *plane, char **tokens)
{
	char	**c;
	char	**n;
	char	**cl;
	t_vec3	vec_epsilon;

	c = nc_split(tokens[1], ',');
	n = nc_split(tokens[2], ',');
	cl = nc_split(tokens[3], ',');
	vec_epsilon = (t_vec3){EPSILON, EPSILON, EPSILON};
	*plane = plane_from_numbers(vec3_from_strings(c),
			vec3_from_strings(n), color_from_strings(cl));
	plane->normal = vec3_normalize(plane->normal);
	plane->normal = vec3_add(plane->normal, vec_epsilon);
	nc_matrix_delete(c, &free);
	nc_matrix_delete(n, &free);
	nc_matrix_delete(cl, &free);
	if (vec3_length(plane->normal) < 0 - EPSILON)
		return (false);
	if (!is_vec3_in_range(plane->normal, -1.1, 1.1))
		return (error("3D norm vec out of bounds in plane [-1.0,1.0]"), false);
	return (true);
}
