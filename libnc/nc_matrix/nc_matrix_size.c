/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_matrix_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:29:21 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:29:21 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

size_t	nc_matrix_size(void *matrix)
{
	size_t	i;

	i = 0;
	while (((void **)matrix)[i])
		i++;
	return (i);
}

size_t	nc_matrix_sizenb(char **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
	{
		if (nc_strlen(matrix[i]) > 10)
			return (11);
		i++;
	}
	return (i);
}
