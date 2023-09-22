/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_inter_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:23:43 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:23:44 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	sphere_intersect(t_sphere *sp, t_ray *ray, t_hit *inter)
{
	t_vec3		co;
	t_equation	equation;

	equation.t1 = -1.0f;
	co = vec3_sub(ray->origin, sp->center);
	equation.a = vec3_dot(ray->direction, ray->direction);
	equation.b = 2.0f * vec3_dot(co, ray->direction);
	equation.c = vec3_dot(co, co) - pow(sp->radius, 2);
	if (solve(&equation) > 0 && \
		(equation.t1 > EPSILON || equation.t2 > EPSILON))
	{
		if (equation.t1 > EPSILON)
			inter->t = equation.t1;
		else
			inter->t = equation.t2;
		inter->color = sp->color;
		return (true);
	}
	return (false);
}
