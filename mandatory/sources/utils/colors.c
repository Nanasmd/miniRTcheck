/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 11:44:20 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/24 20:31:38 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	blue(void)
{
	return ((t_color){0, 0, 0, 255});
}

t_color	black(void)
{
	return ((t_color){0, 0, 0, 0});
}

t_color	white(void)
{
	return ((t_color){0, 255, 255, 255});
}

t_color	red(void)
{
	return ((t_color){0, 255, 0, 0});
}
