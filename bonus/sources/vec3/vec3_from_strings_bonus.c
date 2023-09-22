/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_from_strings_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:26:56 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:26:57 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	vec3_from_strings(char **vec)
{
	return ((t_vec3)
		{
			.x = nc_atod(vec[X]),
			.y = nc_atod(vec[Y]),
			.z = nc_atod(vec[Z]),
		}
	);
}
