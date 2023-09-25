/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_bonus2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:32:09 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/24 19:50:06 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	error_misformat_colors(const char *x)
{
	printf("Error\n");
	printf("Colors misformatting in %s\n", x);
}

void	error_normal_out_of_bounds(const char *x)
{
	printf("Error\n");
	printf("Normal vector fields \
		out of bounds in %s[-1.0,1.0]\n", x);
}

void	error_ks_out_of_bounds(const char *x)
{
	printf("Error\n");
	printf("Specular coefficient out of bounds in %s [0.0,1.0]\n", x);
}

void	error_shiniess_out_of_bounds(const char *x)
{
	printf("Error\n");
	printf("Shininess out of bounds in %s [0.0,+∞[\n", x);
}

void	error_values_too_small(const char *x)
{
	printf("Error\n");
	printf("Values are too small in %s\n", x);
}
