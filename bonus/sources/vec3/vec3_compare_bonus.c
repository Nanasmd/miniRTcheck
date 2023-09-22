/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_compare_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:26:39 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:26:40 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	vec3_compare(t_vec3 v1, t_vec3 v2)
{
	return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z);
}