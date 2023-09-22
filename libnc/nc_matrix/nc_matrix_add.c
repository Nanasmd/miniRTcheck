/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_matrix_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:28:45 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:28:46 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	*nc_matrix_add(void *matrix, void *data)
{
	size_t	len;

	len = nc_matrix_size(matrix);
	((char **)matrix)[len] = data;
	return (matrix);
}
