/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_illumination.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:16:51 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/24 21:26:09 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_ambient_light(t_light *ambient, char **tokens, int counters[3])
{
	char	**color;

	if (nc_matrix_size(tokens) != 3)
		return (error("Wrong number of args in ambient (need 3)"), false);
	if (!parse_syntax(tokens, "001"))
		return (error("Misconfiguration in commas/numbers in ambient"), false);
	if (!parse_rgb(tokens[2]))
		return (error("Colors misformatting in ambient"), false);
	if (nc_atod(tokens[1]) < 0.0 || nc_atod(tokens[1]) > 1.0)
		return (error("Ambient ratio out of bounds [0,1.0]"), false);
	color = nc_split(tokens[2], ',');
	ambient->ratio = nc_atod(tokens[1]);
	ambient->color = color_from_strings(color);
	nc_matrix_delete(color, &free);
	counters[0]++;
	return (true);
}

bool	parse_camera(t_camera *cam, char **tokens, int counters[3])
{
	char	**color;
	char	**normal;
	t_vec3	vec_epsilon;

	vec_epsilon = (t_vec3){EPSILON, EPSILON, EPSILON};
	if (nc_matrix_size(tokens) != 4)
		return (error("Wrong number of args in camera (need 4)"), false);
	if (!parse_syntax(tokens, "0110"))
		return (error("Misconfiguration in commas/numbers in camera"), false);
	color = nc_split(tokens[1], ',');
	normal = nc_split(tokens[2], ',');
	cam->center = vec3_from_strings(color);
	cam->normal = vec3_from_strings(normal);
	cam->normal = vec3_add(cam->normal, vec_epsilon);
	nc_matrix_delete(color, &free);
	nc_matrix_delete(normal, &free);
	if (vec3_length(cam->normal) < 1.0 - EPSILON)
		return (error("Normal vector is too small in camera"), false);
	cam->normal = vec3_normalize(cam->normal);
	cam->fov = nc_atod(tokens[3]);
	if (cam->fov < 0.0 || cam->fov > 180.0)
		return (error("FOV out of bounds [0, 180]"), false);
	counters[1]++;
	return (true);
}

bool	parse_light_source(t_vector *lights, char **tokens, int counters[3])
{
	char	**origin;
	char	**color;
	t_light	*light;

	if (nc_matrix_size(tokens) != 4)
		return (error("Wrong number of args in light (need 4)"), false);
	if (!parse_syntax(tokens, "0101"))
		return (error("Misconfiguration in commas/numbers in light"), false);
	if (!parse_rgb(tokens[3]))
		return (error("Colors misformatting in light"), false);
	if (nc_atod(tokens[2]) < 0.0 || nc_atod(tokens[2]) > 1.0)
		return (error("Light brightness out of bounds [0,1.0]"), false);
	origin = nc_split(tokens[1], ',');
	color = nc_split(tokens[3], ',');
	light = light_new(origin, tokens[2], color);
	nc_vector_push(lights, light);
	nc_matrix_delete(origin, &free);
	nc_matrix_delete(color, &free);
	counters[2]++;
	return (true);
}
