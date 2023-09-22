/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:18:41 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:18:42 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	vec3_normalize(t_vec3 vec)
{
	return (vec3_scale(vec, 1.0 / vec3_length(vec)));
}
