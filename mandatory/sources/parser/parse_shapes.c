/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:16:57 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/24 21:34:40 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_plane(t_vector *shapes, char **tokens)
{
	bool	ok;
	t_plane	plane;
	t_shape	*shape;

	if (nc_matrix_size(tokens) != 4)
		return (error("Wrong number of args in plane (need 4)"), false);
	if (!parse_syntax(tokens, "0111"))
		return (error("Misconfiguration in commas/numbers in plane"), false);
	if (!parse_rgb(tokens[3]))
		return (error("Colors misformatting in plane"), false);
	ok = plane_from_strings(&plane, tokens);
	if (!ok)
		return (error("Values are incorrect in plane"), false);
	shape = shape_new(&plane, PLANE, shapes->size);
	nc_vector_push(shapes, shape);
	return (true);
}

bool	parse_sphere(t_vector *shapes, char **tokens)
{
	bool		ok;
	t_sphere	sphere;
	t_shape		*shape;

	if (nc_matrix_size(tokens) != 4)
		return (error("Wrong number of args in sphere (need 4)"), false);
	if (!parse_syntax(tokens, "0101"))
		return (error("Misconfiguration in commas/numbers in sphere"), false);
	if (!parse_rgb(tokens[3]))
		return (error("Colors misformatting in sphere"), false);
	ok = sphere_from_strings(&sphere, tokens);
	if (!ok)
		return (error("Values are too small in sphere"), false);
	shape = shape_new(&sphere, SPHERE, shapes->size);
	nc_vector_push(shapes, shape);
	return (true);
}

bool	parse_cylinder(t_vector *shapes, char **tokens)
{
	bool		ok;
	t_cylinder	cylinder;
	t_shape		*shape;

	if (nc_matrix_size(tokens) != 6)
		return (error("Wrong number of args in cylinder (need 6)"), false);
	if (!parse_syntax(tokens, "011001"))
		return (error("Misconfiguration in commas/numbers in cylinder"), false);
	if (!parse_rgb(tokens[5]))
		return (error("Colors misformatting in cylinder"), false);
	ok = cylinder_from_strings(&cylinder, tokens);
	if (!ok)
		return (error("Values are incorrect in cylinder"), false);
	shape = shape_new(&cylinder, CYLINDER, shapes->size);
	nc_vector_push(shapes, shape);
	return (true);
}
