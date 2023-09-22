/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:23:10 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:23:11 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	sphere_from_strings(t_sphere *sp, char **tokens)
{
	char		**c;
	char		**cl;

	c = nc_split(tokens[1], ',');
	cl = nc_split(tokens[3], ',');
	*sp = (t_sphere)
	{
		.center = vec3_from_strings(c),
		.radius = nc_atod(tokens[2]) / 2.0,
		.color = color_from_strings(cl),
	};
	nc_matrix_delete(c, &free);
	nc_matrix_delete(cl, &free);
	if (sp->radius < EPSILON)
		return (false);
	return (true);
}
