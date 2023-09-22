/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:31:03 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:31:04 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

char	*nc_strdup(const char *s)
{
	char	*dup;
	size_t	size;

	size = nc_strlen(s) + 1;
	dup = (char *)malloc(size);
	if (!dup)
		return (NULL);
	nc_memcpy(dup, s, size);
	return (dup);
}
