/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_debug_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:22:40 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:22:41 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	world_print(t_world *world)
{
	printf("\n\t================ DEBUG ================\n\n");
	ambient_print(&world->ambient);
	camera_print(&world->camera);
	nc_vector_print(world->lights);
	nc_vector_print(world->shapes);
	printf("Right Vector:\n  ");
	vec3_print(world->right);
	printf("Up Vector:\n  ");
	vec3_print(world->up);
	printf("Viewport:\n");
	printf("  Height: %lf\n", world->hview);
	printf("  Width: %lf\n", world->wview);
	printf("\n\t=======================================\n\n");
}
