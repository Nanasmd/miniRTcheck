/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:31:58 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:31:59 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

char	*nc_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	end;
	size_t	start;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = nc_strlen(s1);
	while (nc_strchr(set, s1[start]) && s1[start])
		start++;
	while (nc_strchr(set, s1[end]) && end > start)
		end--;
	new = nc_substr(s1, start, (end - start) + 1);
	if (!new)
		return (NULL);
	return (new);
}
