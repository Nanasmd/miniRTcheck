/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:17:07 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/23 11:54:37 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	identifying(t_world *world, char **tokens, int count[3], char *checkid)
{
	if (!nc_strcmp("A", tokens[0]))
	{
		*checkid = *tokens[0];
		return (parse_ambient_light(&world->ambient, tokens, count));
	}
	else if (!nc_strcmp("C", tokens[0]))
	{
		*checkid = *tokens[0];
		return (parse_camera(&world->camera, tokens, count));
	}
	else if (!nc_strcmp("L", tokens[0]))
	{
		*checkid = *tokens[0];
		return (parse_light_source(world->lights, tokens, count));
	}
	else if (!nc_strcmp("pl", tokens[0]))
		return (parse_plane(world->shapes, tokens));
	else if (!nc_strcmp("sp", tokens[0]))
		return (parse_sphere(world->shapes, tokens));
	else if (!nc_strcmp("cy", tokens[0]))
		return (parse_cylinder(world->shapes, tokens));
	else
		return (error("Error parsing entities"), false);
	return (true);
}

void	parse_map(t_world *world, char **map, int counters[3])
{
	int		i;
	bool	ok;
	char	**tokens;
	char	checkid[4];

	i = -1;
	checkid[0] = '\0';
	checkid[1] = '\0';
	checkid[2] = '\0';
	checkid[3] = '\0';
	while (map[++i])
	{
		tokens = nc_split(map[i], ' ');
		ok = identifying(world, tokens, counters, &checkid[i]);
		nc_matrix_delete(tokens, &free);
		if (!ok)
			message(world, ERROR_SYNTAX);
	}
	if (nc_strlen(checkid) != 3)
		message(world, ERROR_SYNTAX);
}

t_world	*parse(char *filename)
{
	t_world	*world;
	int		counters[3];

	nc_bzero(counters, 3 * sizeof(int));
	if (!is_filename_valid(filename))
		message(NULL, ERROR_NOT_RT);
	world = world_new();
	if (!world)
		message(NULL, ERROR_MALLOC);
	world->map = read_map(world, filename);
	if (nc_matrix_size(world->map) == 0)
		message(world, ERROR_EMPTY_MAP);
	parse_map(world, world->map, counters);
	if (counters[1] == 0)
		message(world, ERROR_NO_CAMERA);
	if (counters[0] > 1 || counters[1] > 1 || counters[2] > 1)
		message(world, ERROR_TOO_MANY);
	return (world);
}
