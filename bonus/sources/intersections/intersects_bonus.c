/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersects_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:23:30 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:23:31 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	intersects(t_shape *shape, t_ray *ray, t_hit *inter)
{
	if (shape->type == SPHERE)
		return (sphere_intersect(&shape->data.sp, ray, inter));
	else if (shape->type == PLANE)
		return (plane_intersect(&shape->data.pl, ray, inter));
	else if (shape->type == CYLINDER)
		return (cylinder_intersect(&shape->data.cy, ray, inter));
	else if (shape->type == CONE)
		return (cone_intersect(&shape->data.co, ray, inter));
	return (false);
}
