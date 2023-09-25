/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:17:37 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/24 20:59:18 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_viewport(t_world *w)
{
	t_vec3	upguide;

	upguide = (t_vec3){0.0, 1.0, 0.0};
	w->wview = tan(radians(w->camera.fov / 2.0));
	w->hview = w->wview / ratio();
	w->right = vec3_normalize(vec3_cross(w->camera.normal, upguide));
	w->up = vec3_normalize(vec3_cross(w->camera.normal, w->right));
	w->right = vec3_normalize(vec3_cross(w->camera.normal, w->up));
}

t_vec3	pixels_to_viewport(int x, int y)
{
	t_vec3	converted;
	double	width;
	double	height;

	width = WIDTH;
	height = WIDTH / ratio();
	converted.x = ((2.0f * x) / width) - 1;
	converted.y = ((2.0f * y) / height) - 1;
	converted.z = 0;
	return (converted);
}

t_ray	make_ray(t_world *w, t_vec3 factors)
{
	t_ray	ray;
	t_vec3	vertical;
	t_vec3	horizontal;
	t_vec3	res;

	vertical = vec3_scale(w->up, factors.y * w->hview);
	horizontal = vec3_scale(w->right, factors.x * w->wview);
	res = vec3_add(vertical, horizontal);
	res = vec3_add(res, w->camera.normal);
	res = vec3_add(res, w->camera.center);
	ray.origin = w->camera.center;
	ray.direction = vec3_normalize(vec3_sub(res, ray.origin));
	return (ray);
}

t_vec3	ray_at(t_ray *ray, double t)
{
	return (vec3_add(ray->origin, vec3_scale(ray->direction, t)));
}
