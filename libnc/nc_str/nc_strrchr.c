/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:31:53 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:31:54 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

char	*nc_strrchr(const char *s, int c)
{
	size_t	i;

	i = nc_strlen(s);
	while (1)
	{
		if (s[i] == c)
			return ((char *)s + i);
		if (i == 0)
			return (NULL);
		i--;
	}
}
