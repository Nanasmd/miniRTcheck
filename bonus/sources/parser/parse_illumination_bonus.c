/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_illumination_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:25:19 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/25 10:14:48 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_ambient_light(t_light *ambient, char **tokens, int *counter)
{
	char	**color;

	if (nc_matrix_size(tokens) != 3)
		return (error_num_args("ambient", "3"), false);
	if (!parse_syntax(tokens, "001"))
		return (error_num_commas("ambient"), false);
	if (!parse_rgb(tokens[2]))
		return (error_misformat_colors("ambient"), false);
	if (nc_atod(tokens[1]) < 0.0 || nc_atod(tokens[1]) > 1.0)
		return (error_ambient_ratio_out_of_bounds("ambient"), false);
	color = nc_split(tokens[2], ',');
	ambient->color = color_from_strings(color);
	ambient->ratio = nc_atod(tokens[1]);
	nc_matrix_delete(color, &free);
	(*counter)++;
	return (true);
}

/*bool	parse_camera(t_camera *cam, char **tokens, int *counter)
{
	char	**color;
	char	**normal;
	t_vec3	vec_min;
	t_vec3	vec_max;
	t_vec3	vec_epsilon;

	vec_min = (t_vec3){-1.0001, -1.0001, -1.0001};
	vec_max = (t_vec3){1.0001, 1.0001, 1.0001};
	vec_epsilon = (t_vec3){EPSILON, EPSILON, EPSILON};
	if (nc_matrix_size(tokens) != 4)
		return (error_num_args("camera", "4"), false);
	if (!parse_syntax(tokens, "0110"))
		return (error_num_commas("camera"), false);
	if (nc_atod(tokens[3]) < 0.0 || nc_atod(tokens[3]) > 180.0)
		return (error_camera_fov_out_of_bounds(), false);
	color = nc_split(tokens[1], ',');
	normal = nc_split(tokens[2], ',');
	cam->center = vec3_from_strings(color);
	cam->normal = vec3_from_strings(normal);
	cam->normal = vec3_add(cam->normal, vec_epsilon);
	cam->fov = nc_atod(tokens[3]);
	nc_matrix_delete(color, &free);
	nc_matrix_delete(normal, &free);
	if (vec3_length(cam->normal) < 1.0 - EPSILON)
		return (error_values_too_small("camera"), false);
	if (!vec3_between(cam->normal, vec_min, vec_max))
		return (error_normal_out_of_bounds("camera"), false);
	cam->normal = vec3_normalize(cam->normal);
	(*counter)++;
	return (true);
}*/

static bool	check_errors(t_camera *cam, char **tokens)
{
	char	**color;
	char	**normal;
	t_vec3	vec_epsilon;

	if (nc_matrix_size(tokens) != 4 || !parse_syntax(tokens, "0110"))
		return (error_num_args("camera", "4"), false);
	color = nc_split(tokens[1], ',');
	normal = nc_split(tokens[2], ',');
	cam->center = vec3_from_strings(color);
	cam->normal = vec3_from_strings(normal);
	vec_epsilon = (t_vec3){EPSILON, EPSILON, EPSILON};
	cam->normal = vec3_add(cam->normal, vec_epsilon);
	nc_matrix_delete(color, &free);
	nc_matrix_delete(normal, &free);
	return (true);
}

static bool	check_normal_and_fov(t_camera *cam, char **tokens)
{
	t_vec3	vec_min;
	t_vec3	vec_max;

	vec_min = (t_vec3){-1.0001, -1.0001, -1.0001};
	vec_max = (t_vec3){1.0001, 1.0001, 1.0001};
	cam->fov = nc_atod(tokens[3]);
	if (cam->fov < 0.0 || cam->fov > 180.0)
		return (error_camera_fov_out_of_bounds(), false);
	if (vec3_length(cam->normal) < 1.0 - EPSILON)
		return (error_values_too_small("camera"), false);
	if (!vec3_between(cam->normal, vec_min, vec_max))
		return (error_normal_out_of_bounds("camera"), false);
	cam->normal = vec3_normalize(cam->normal);
	return (true);
}

bool	parse_camera(t_camera *cam, char **tokens, int *counter)
{
	if (!check_errors(cam, tokens))
		return (false);
	if (!check_normal_and_fov(cam, tokens))
		return (false);
	(*counter)++;
	return (true);
}

bool	parse_light_source(t_vector *lights, char **tokens)
{
	char	**origin;
	char	**color;
	t_light	*light;

	if (nc_matrix_size(tokens) != 4)
		return (error_num_args("light source", "4"), false);
	if (!parse_syntax(tokens, "0101"))
		return (error_num_commas("light source"), false);
	if (!parse_rgb(tokens[3]))
		return (error_misformat_colors("light source"), false);
	if (nc_atod(tokens[2]) < 0.0 || nc_atod(tokens[2]) > 1.0)
		return (error_light_brightness_out_of_bounds(), false);
	origin = nc_split(tokens[1], ',');
	color = nc_split(tokens[3], ',');
	light = light_new(origin, tokens[2], color);
	nc_vector_push(lights, light);
	nc_matrix_delete(origin, &free);
	nc_matrix_delete(color, &free);
	return (true);
}
