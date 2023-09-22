/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:31:44 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:31:45 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

char	*nc_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	if ((!big || !little) && len == 0)
		return (NULL);
	i = 0;
	little_len = nc_strlen(little);
	if (!little[0])
		return ((char *)big);
	while (big[i] != '\0' && i <= len - little_len && len > 0)
	{
		if (big[i] == little[0])
			if (!nc_memcmp(big + i, little, little_len))
				return ((char *)big + i);
		i++;
	}
	return (NULL);
}
