/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_cossine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:18:12 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:18:13 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	vec3_cossine(t_vec3 v1, t_vec3 v2)
{
	double	dot;
	double	lengths;

	dot = vec3_dot(v1, v2);
	lengths = vec3_length(v1) * vec3_length(v2);
	return (dot / lengths);
}
