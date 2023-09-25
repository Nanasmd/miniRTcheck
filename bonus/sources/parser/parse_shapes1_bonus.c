/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:25:23 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/25 10:19:32 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* bool	parse_plane(t_vector *shapes, char **tokens)
{
	bool	ok;
	t_plane	plane;bool	parse_texture(t_vector *shapes, char **tokens)
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
	t_shape	*shape;
	t_vec3	vec_min;
	t_vec3	vec_max;

	vec_min = (t_vec3){-1.0001, -1.0001, -1.0001};
	vec_max = (t_vec3){1.0001, 1.0001, 1.0001};
	if (nc_matrix_size(tokens) != 6)
		return (error_num_args("plane", "6"), false);
	if (!parse_syntax(tokens, "011100"))
		return (error_num_commas("plane"), false);
	if (!parse_rgb(tokens[3]))
		return (error_misformat_colors("plane"), false);
	if (nc_atod(tokens[4]) < 0.0 || nc_atod(tokens[4]) > 1.0)
		return (error_ks_out_of_bounds("plane"), false);
	if (nc_atod(tokens[5]) < 0.0)
		return (error_shiniess_out_of_bounds("plane"), false);
	ok = plane_from_strings(&plane, tokens);
	if (!ok)
		return (error_values_too_small("plane"), false);
	if (!vec3_between(plane.normal, vec_min, vec_max))
		return (error_normal_out_of_bounds("plane"), false);
	shape = shape_new(&plane, PLANE, shapes->size, tokens + 4);
	nc_vector_push(shapes, shape);
	return (true);
}
*/
static bool	plane_errors(char **tokens)
{
	if (nc_matrix_size(tokens) != 6)
		return (error_num_args("plane", "6"), false);
	if (!parse_syntax(tokens, "011100"))
		return (error_num_commas("plane"), false);
	if (!parse_rgb(tokens[3]))
		return (error_misformat_colors("plane"), false);
	if (nc_atod(tokens[4]) < 0.0 || nc_atod(tokens[4]) > 1.0)
		return (error_ks_out_of_bounds("plane"), false);
	if (nc_atod(tokens[5]) < 0.0)
		return (error_shiniess_out_of_bounds("plane"), false);
	return (true);
}

bool	parse_plane(t_vector *shapes, char **tokens)
{
	bool	ok;
	t_plane	plane;
	t_shape	*shape;
	t_vec3	vec_min;
	t_vec3	vec_max;

	vec_min = (t_vec3){-1.0001, -1.0001, -1.0001};
	vec_max = (t_vec3){1.0001, 1.0001, 1.0001};
	if (!plane_errors(tokens))
		return (false);
	ok = plane_from_strings(&plane, tokens);
	if (!ok)
		return (error_values_too_small("plane"), false);
	if (!vec3_between(plane.normal, vec_min, vec_max))
		return (error_normal_out_of_bounds("plane"), false);
	shape = shape_new(&plane, PLANE, shapes->size, tokens + 4);
	nc_vector_push(shapes, shape);
	return (true);
}

bool	parse_sphere(t_vector *shapes, char **tokens)
{
	bool		ok;
	t_sphere	sphere;
	t_shape		*shape;

	if (nc_matrix_size(tokens) != 6)
		return (error_num_args("sphere", "6"), false);
	if (!parse_syntax(tokens, "010100"))
		return (error_num_commas("sphere"), false);
	if (!parse_rgb(tokens[3]))
		return (error_misformat_colors("sphere"), false);
	if (nc_atod(tokens[4]) < 0.0 || nc_atod(tokens[4]) > 1.0)
		return (error_ks_out_of_bounds("sphere"), false);
	if (nc_atod(tokens[5]) < 0.0)
		return (error_shiniess_out_of_bounds("sphere"), false);
	ok = sphere_from_strings(&sphere, tokens);
	if (!ok)
		return (error_values_too_small("plane"), false);
	shape = shape_new(&sphere, SPHERE, shapes->size, tokens + 4);
	nc_vector_push(shapes, shape);
	return (true);
}

/*bool	parse_cylinder(t_vector *shapes, char **tokens)
{
	bool		ok;
	t_cylinder	cylinder;
	t_shape		*shape;
	t_vec3		vec_min;
	t_vec3		vec_max;

	vec_min = (t_vec3){-1.0001, -1.0001, -1.0001};
	vec_max = (t_vec3){1.0001, 1.0001, 1.0001};
	if (nc_matrix_size(tokens) != 8)
		return (error_num_args("cylinder", "8"), false);
	if (!parse_syntax(tokens, "01100100"))
		return (error_num_commas("cylinder"), false);
	if (!parse_rgb(tokens[5]))
		return (error_misformat_colors("cylinder"), false);
	if (nc_atod(tokens[6]) < 0.0 || nc_atod(tokens[6]) > 1.0)
		return (error_ks_out_of_bounds("cylinder"), false);
	if (nc_atod(tokens[7]) < 0.0)
		return (error_shiniess_out_of_bounds("cylinder"), false);
	ok = cylinder_from_strings(&cylinder, tokens);
	if (!ok)
		return (error_values_too_small("plane"), false);
	if (!vec3_between(cylinder.normal, vec_min, vec_max))
		return (error_normal_out_of_bounds("cylinder"), false);
	shape = shape_new(&cylinder, CYLINDER, shapes->size, tokens + 6);
	nc_vector_push(shapes, shape);
	return (true);
}
*/

static bool	cylinder_errors(char **tokens)
{
	if (nc_matrix_size(tokens) != 8)
		return (error_num_args("cylinder", "8"), false);
	if (!parse_syntax(tokens, "01100100"))
		return (error_num_commas("cylinder"), false);
	if (!parse_rgb(tokens[5]))
		return (error_misformat_colors("cylinder"), false);
	if (nc_atod(tokens[6]) < 0.0 || nc_atod(tokens[6]) > 1.0)
		return (error_ks_out_of_bounds("cylinder"), false);
	if (nc_atod(tokens[7]) < 0.0)
		return (error_shiniess_out_of_bounds("cylinder"), false);
	return (true);
}

bool	parse_cylinder(t_vector *shapes, char **tokens)
{
	bool		ok;
	t_cylinder	cylinder;
	t_shape		*shape;
	t_vec3		vec_min;
	t_vec3		vec_max;

	vec_min = (t_vec3){-1.0001, -1.0001, -1.0001};
	vec_max = (t_vec3){1.0001, 1.0001, 1.0001};
	if (!cylinder_errors(tokens))
		return (false);
	ok = cylinder_from_strings(&cylinder, tokens);
	if (!ok)
		return (error_values_too_small("plane"), false);
	if (!vec3_between(cylinder.normal, vec_min, vec_max))
		return (error_normal_out_of_bounds("cylinder"), false);
	shape = shape_new(&cylinder, CYLINDER, shapes->size, tokens + 6);
	nc_vector_push(shapes, shape);
	return (true);
}
