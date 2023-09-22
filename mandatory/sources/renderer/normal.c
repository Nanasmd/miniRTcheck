/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:17:27 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:17:28 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	sphere_normal(t_hit *inter, t_ray *ray)
{
	t_vec3	point;
	t_vec3	normal;

	point = ray_at(ray, inter->t);
	normal = vec3_sub(point, inter->shape->data.sp.center);
	return (normal);
}

t_vec3	cylinder_normal(t_hit *inter, t_ray *ray)
{
	t_vec3	point;
	t_vec3	normal;

	point = ray_at(ray, inter->t);
	normal = vec3_sub(point, inter->a);
	if (vec3_compare(inter->a, inter->shape->data.cy.cap1))
		normal = vec3_scale(inter->shape->data.cy.normal, -1);
	else if (vec3_compare(inter->a, inter->shape->data.cy.cap2))
		normal = inter->shape->data.cy.normal;
	return (normal);
}

t_vec3	shape_normal(t_hit *inter, t_ray *ray)
{
	if (inter->shape->type == PLANE)
		return (inter->shape->data.pl.normal);
	else if (inter->shape->type == SPHERE)
		return (sphere_normal(inter, ray));
	else
		return (cylinder_normal(inter, ray));
}
