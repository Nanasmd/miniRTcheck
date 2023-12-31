/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_matrix_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:29:10 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:29:10 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	*nc_matrix_new(size_t lines, size_t columns)
{
	void	*matrix;
	size_t	i;

	i = -1;
	matrix = nc_calloc(lines + 1, sizeof(char *));
	if (!matrix || !columns)
		return (matrix);
	while (++i < lines)
		((char **)matrix)[i] = nc_calloc(columns + 1, sizeof(char));
	return (matrix);
}
