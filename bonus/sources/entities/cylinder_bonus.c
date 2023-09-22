/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:22:53 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:22:54 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	cylinder_from_strings(t_cylinder *cy, char **tokens)
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
	cy->normal = vec3_normalize(cy->normal);
	return (true);
}
