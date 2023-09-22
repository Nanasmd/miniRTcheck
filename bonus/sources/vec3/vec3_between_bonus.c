/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_between_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:26:34 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:26:35 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	vec3_between(t_vec3 vec, t_vec3 min, t_vec3 max)
{
	return (
		(min.x <= vec.x && vec.x <= max.x) && \
		(min.y <= vec.y && vec.y <= max.y) && \
		(min.z <= vec.z && vec.z <= max.z)
	);
}
