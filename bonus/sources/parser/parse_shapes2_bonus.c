/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:19:11 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/25 10:20:00 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_texture(t_vector *shapes, char **tokens)
{
	t_shape	*last;

	if (nc_matrix_size(tokens) < 2)
		return (error_num_args("checkerboard", "2"), false);
	if (!parse_plane(shapes, tokens))
		return (false);
	last = nc_vector_last(shapes);
	last->is_textured = true;
	return (true);
}

bool	parse_cone(t_vector *shapes, char **tokens)
{
	bool	ok;
	t_cone	cone;
	t_shape	*shape;
	t_vec3	vec_min;
	t_vec3	vec_max;

	vec_min = (t_vec3){-1.0001, -1.0001, -1.0001};
	vec_max = (t_vec3){1.0001, 1.0001, 1.0001};
	if (nc_matrix_size(tokens) != 8)
		return (error_num_args("cone", "8"), false);
	if (!parse_syntax(tokens, "01100100"))
		return (error_num_commas("cone"), false);
	if (!parse_rgb(tokens[5]))
		return (error_misformat_colors("cone"), false);
	ok = cone_from_strings(&cone, tokens);
	if (!ok)
		return (error_values_too_small("cone"), false);
	if (!vec3_between(cone.normal, vec_min, vec_max))
		return (error_normal_out_of_bounds("cylinder"), false);
	shape = shape_new(&cone, CONE, shapes->size, tokens + 6);
	nc_vector_push(shapes, shape);
	return (true);
}
