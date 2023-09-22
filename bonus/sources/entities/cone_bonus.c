/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:22:49 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:22:50 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	cone_from_strings(t_cone *co, char **tokens)
{
	char	**c;
	char	**n;
	char	**cl;

	c = nc_split(tokens[1], ',');
	n = nc_split(tokens[2], ',');
	cl = nc_split(tokens[5], ',');
	*co = (t_cone)
	{
		.radius = nc_atod(tokens[3]),
		.height = nc_atod(tokens[4]),
		.tip = vec3_from_strings(c),
		.normal = vec3_from_strings(n),
		.color = color_from_strings(cl),
	};
	nc_matrix_delete(c, &free);
	nc_matrix_delete(n, &free);
	nc_matrix_delete(cl, &free);
	if (vec3_length(co->normal) < 1.0 - EPSILON || co->radius < EPSILON
		|| co->height < EPSILON)
		return (false);
	co->normal = vec3_normalize(co->normal);
	return (true);
}
