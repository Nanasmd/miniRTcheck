/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_inter_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:23:38 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:23:39 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	plane_intersect(t_plane *pl, t_ray *ray, t_hit *inter)
{
	t_vec3		co;
	t_equation	equation;

	if (vec3_dot(ray->direction, pl->normal) != 0.0)
	{
		co = vec3_sub(ray->origin, pl->center);
		equation.a = 0;
		equation.b = vec3_dot(ray->direction, pl->normal);
		equation.c = vec3_dot(co, pl->normal);
		solve(&equation);
		if (equation.t1 > EPSILON)
		{
			inter->t = equation.t1;
			inter->color = pl->color;
			return (true);
		}
	}
	return (false);
}
