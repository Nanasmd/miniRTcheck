/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:16:11 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/25 09:53:24 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*bool	cylinder_from_strings(t_cylinder *cy, char **tokens)
{
	char		**c;
	char		**n;
	char		**cl;

	c = nc_split(tokens[1], ',');
	n = nc_split(tokens[2], ',');
	cl = nc_split(tokens[5], ',');
	*cy = (t_cylinder)
	{
		.radius = nc_atod(tokens[3]) / 2.0,
		.height = nc_atod(tokens[4]),
		.center = vec3_from_strings(c),
		.normal = vec3_from_strings(n),
		.color = color_from_strings(cl),
	};
	nc_matrix_delete(c, &free);
	nc_matrix_delete(n, &free);
	nc_matrix_delete(cl, &free);
	if (vec3_length(cy->normal) < 1.0 - EPSILON \
		|| cy->radius < EPSILON || cy->height < EPSILON)
		return (false);
	if (!is_vec3_in_range(cy->normal, -1.0, 1.0))
		return (error("3D norm vec out of range in cylinder"), false);
	cy->normal = vec3_normalize(cy->normal);
	cy->cap1 = vec3_add(cy->center, vec3_scale(cy->normal, -cy->height / 2.0));
	cy->cap2 = vec3_add(cy->center, vec3_scale(cy->normal, cy->height / 2.0));
	return (true);
}*/

static t_cylinder	cylinder_from_numbers(t_vec3 center,
		t_vec3 normal, t_color color, double *doubles)
{
	static t_cylinder	cy;

	cy = (t_cylinder)
	{
		.radius = doubles[0],
		.height = doubles[1],
		.center = center,
		.normal = normal,
		.color = color
	};
	return (cy);
}

bool	cylinder_from_strings(t_cylinder *cy, char **tokens)
{
	char		**c;
	char		**n;
	char		**cl;
	double		doubles[2];

	c = nc_split(tokens[1], ',');
	n = nc_split(tokens[2], ',');
	cl = nc_split(tokens[5], ',');
	doubles[0] = nc_atod(tokens[3]) / 2.0;
	doubles[1] = nc_atod(tokens[4]);
	*cy = cylinder_from_numbers(vec3_from_strings(c), vec3_from_strings(n),
			color_from_strings(cl), (double *)&doubles);
	nc_matrix_delete(c, &free);
	nc_matrix_delete(n, &free);
	nc_matrix_delete(cl, &free);
	if (vec3_length(cy->normal) < 1.0 - EPSILON \
		|| cy->radius < EPSILON || cy->height < EPSILON)
		return (false);
	if (!is_vec3_in_range(cy->normal, -1.0, 1.0))
		return (error("3D norm vec out of range in cylinder"), false);
	cy->normal = vec3_normalize(cy->normal);
	cy->cap1 = vec3_add(cy->center, vec3_scale(cy->normal, -cy->height / 2.0));
	cy->cap2 = vec3_add(cy->center, vec3_scale(cy->normal, cy->height / 2.0));
	return (true);
}
