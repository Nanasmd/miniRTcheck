/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:31:37 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:31:38 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

char	*nc_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mapped;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	mapped = (char *)malloc(nc_strlen(s) + 1);
	if (!mapped)
		return (NULL);
	while (s[i])
	{
		mapped[i] = f(i, s[i]);
		i++;
	}
	mapped[i] = '\0';
	return (mapped);
}
