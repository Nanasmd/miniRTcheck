/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:27:27 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/25 11:13:29 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_graphics(t_world *w)
{
	w->disp.mlx = mlx_init();
	if (!w->disp.mlx)
		message(w, ERROR_MALLOC);
	w->disp.win = mlx_new_window(w->disp.mlx, WIDTH, height(), "miniRT");
	if (!w->disp.win)
		message(w, ERROR_MALLOC);
	w->disp.img = mlx_new_image(w->disp.mlx, WIDTH, height());
	if (!w->disp.img)
		message(w, ERROR_MALLOC);
	w->disp.addr = mlx_get_data_addr(w->disp.img, &w->disp.bpp,
			&w->disp.line_length, &w->disp.endian);
	if (!w->disp.addr)
		message(w, ERROR_MALLOC);
	w->disp.menu = mlx_new_image(w->disp.mlx, WIDTH / 6, height());
	if (!w->disp.img)
		message(w, ERROR_MALLOC);
}

int	quit(t_world *world)
{
	destroy_world(&world);
	exit(EXIT_SUCCESS);
}

int	on_keypress(int keycode, t_world *w)
{
	if (keycode == ESC)
		quit(w);
	return (keycode);
}

int	main(int argc, char **argv)
{
	t_world	*world;

	if (argc != 2)
		message(NULL, ERROR_USAGE);
	world = parse(argv[1]);
	init_viewport(world);
	init_graphics(world);
	multithread(world);
	mlx_hook(world->disp.win, KeyPress, KeyPressMask, on_keypress, world);
	mlx_hook(world->disp.win, DestroyNotify, StructureNotifyMask, quit, world);
	mlx_loop(world->disp.mlx);
	destroy_world(&world);
	return (0);
}
