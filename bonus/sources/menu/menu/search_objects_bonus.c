/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_objects_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:25:00 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:25:01 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	search_for_spheres(t_world *w)
{
	uint32_t	i;
	t_shape		*shape;

	i = -1;
	shape = NULL;
	while (++i < w->shapes->size)
	{
		shape = nc_vector_at(w->shapes, i);
		if (shape->type != SPHERE)
			continue ;
		display(w, (t_xy){5, 125 + (++w->menu.i * 20)}, 0xFFFF00, "4");
		display(w, (t_xy){25, 125 + (w->menu.i * 20)}, 0xFFFFFF, "- SPHERE");
		return ;
	}
}

void	search_for_planes(t_world *w)
{
	uint32_t	i;
	t_shape		*shape;

	i = -1;
	shape = NULL;
	while (++i < w->shapes->size)
	{
		shape = nc_vector_at(w->shapes, i);
		if (shape->type != PLANE)
			continue ;
		display(w, (t_xy){5, 125 + (++w->menu.i * 20)}, 0xFFFF00, "5");
		display(w, (t_xy){25, 125 + (w->menu.i * 20)}, 0xFFFFFF, "- PLANE");
		return ;
	}
}

void	search_for_cylinders(t_world *w)
{
	uint32_t	i;
	t_shape		*shape;

	i = -1;
	shape = NULL;
	while (++i < w->shapes->size)
	{
		shape = nc_vector_at(w->shapes, i);
		if (shape->type != CYLINDER)
			continue ;
		display(w, (t_xy){5, 125 + (++w->menu.i * 20)}, 0xFFFF00, "6");
		display(w, (t_xy){25, 125 + (w->menu.i * 20)}, 0xFFFFFF, "- CYLINDER");
		return ;
	}
}

void	search_for_cones(t_world *w)
{
	uint32_t	i;
	t_shape		*shape;

	i = -1;
	shape = NULL;
	while (++i < w->shapes->size)
	{
		shape = nc_vector_at(w->shapes, i);
		if (shape->type != CONE)
			continue ;
		display(w, (t_xy){5, 125 + (++w->menu.i * 20)}, 0xFFFF00, "7");
		display(w, (t_xy){25, 125 + (w->menu.i * 20)}, 0xFFFFFF, "- CONE");
		return ;
	}
}

void	search_shapes(t_world *w)
{
	search_for_spheres(w);
	search_for_planes(w);
	search_for_cylinders(w);
	search_for_cones(w);
}
