/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:17:56 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/24 21:20:42 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	message(t_world *world, char *text)
{
	destroy_world(&world);
	printf("Error\n%s\n", text);
	exit(EXIT_FAILURE);
}

// Old Macros
// # define HERE 		printf("HERE\n");
// # define ERROR(m)	printf("Error\n%s\n", m)

// New Functions
void	here(void)
{
	printf("HERE\n");
}

void	error(const char *message)
{
	printf("Error\n%s\n", message);
}

// New Functions

float	ratio(void)
{
	return (16.0 / 9.0);
}

int	height(void)
{
	return (WIDTH / ratio());
}
