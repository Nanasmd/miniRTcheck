/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:26:18 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/24 20:20:13 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	compute_shapes_constants(t_vector *shapes)
{
	t_shape		*shape;
	t_cylinder	*cy;
	t_cone		*co;
	uint32_t	i;

	i = -1;
	while (++i < shapes->size)
	{
		shape = nc_vector_at(shapes, i);
		if (shape->type == CYLINDER)
		{
			cy = &shape->data.cy;
			cy->cap1 = vec3_add(cy->center, \
				vec3_scale(cy->normal, -cy->height / 2.0));
			cy->cap2 = vec3_add(cy->center, \
				vec3_scale(cy->normal, cy->height / 2.0));
		}
		else if (shape->type == CONE)
		{
			co = &shape->data.co;
			co->angle = atan(co->radius / co->height) + EPSILON;
			co->base = vec3_add(co->tip, vec3_scale(co->normal, co->height));
		}
	}
}

float	radians(float degrees)
{
	return ((degrees * PI) / 180.0f);
}

float	degrees(float radians)
{
	return ((radians * 180.0f) / PI);
}

double	determinant(t_equation *eq)
{
	double	delta;

	delta = pow(eq->b, 2) - (4 * eq->a * eq->c);
	if (delta < 0)
		return (-1);
	return (delta);
}

double	solve(t_equation *eq)
{
	double	delta;

	if (eq->a == 0.0 && eq->b != 0.0)
	{
		eq->t1 = -eq->c / eq->b;
		return (0);
	}
	else
	{
		delta = determinant(eq);
		if (delta < 0)
			return (-1);
		eq->t1 = (-eq->b - sqrt(delta)) / (2 * eq->a);
		eq->t2 = (-eq->b + sqrt(delta)) / (2 * eq->a);
		return (delta);
	}
}
