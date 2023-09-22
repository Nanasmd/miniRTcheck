/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:31:15 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:31:16 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

size_t	nc_strlcat(char *dst, const char *src, size_t size)
{
	size_t	k;
	size_t	dst_len;
	size_t	src_len;

	k = 0;
	dst_len = nc_strlen(dst);
	src_len = nc_strlen(src);
	if (dst_len >= size)
		return (size + nc_strlen(src));
	while (src[k] != '\0' && k < size - dst_len - 1)
	{
		dst[dst_len + k] = src[k];
		k++;
	}
	dst[dst_len + k] = '\0';
	return (dst_len + src_len);
}
