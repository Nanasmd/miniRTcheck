/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightsource_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:22:57 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:22:58 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_light	*light_new(char **c, char *ratio, char **cl)
{
	t_light	*bulb;

	bulb = nc_calloc(1, sizeof(t_light));
	if (!bulb)
		return (NULL);
	*bulb = (t_light)
	{
		.center = vec3_from_strings(c),
		.ratio = nc_atod(ratio),
		.color = color_from_strings(cl),
	};
	return (bulb);
}

t_light	*light_copy(t_light *bulb)
{
	t_light	*copy;

	copy = nc_calloc(1, sizeof(t_light));
	if (!copy)
		return (NULL);
	*copy = *bulb;
	return (copy);
}
