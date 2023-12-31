/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:24:18 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:24:19 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_menu_state	handle_camera_direction(int keycode, t_world *w)
{
	if (keycode == ONE)
		w->camera.normal = vec3_new(0, 0, 1);
	else if (keycode == TWO)
		w->camera.normal = vec3_new(0, 0, -1);
	else if (keycode == THREE)
		w->camera.normal = vec3_new(0, 1, 0);
	else if (keycode == FOUR)
		w->camera.normal = vec3_new(0, -1, 0);
	else if (keycode == FIVE)
		w->camera.normal = vec3_new(1, 0, 0);
	else if (keycode == SIX)
		w->camera.normal = vec3_new(-1, 0, 0);
	else if (keycode == Q)
		return (display_main_menu(w), MENU_OPENED);
	else
		return (CHANGE_CAMERA);
	init_viewport(w);
	multithread(w);
	display_camera_menu(w);
	return (CHANGE_CAMERA);
}

t_menu_state	handle_camera_changes(int keycode, t_world *w)
{
	if (keycode == W)
		w->camera.center.z += MOVE;
	else if (keycode == S)
		w->camera.center.z -= MOVE;
	else if (keycode == A)
		w->camera.center.x -= MOVE;
	else if (keycode == D)
		w->camera.center.x += MOVE;
	else if (keycode == UP)
		w->camera.center.y += MOVE;
	else if (keycode == DOWN)
		w->camera.center.y -= MOVE;
	else if (keycode == LEFT)
		w->camera.normal = vec3_rotate(w->camera.normal, Y, -ROTATE);
	else if (keycode == RIGHT)
		w->camera.normal = vec3_rotate(w->camera.normal, Y, ROTATE);
	else
		return (handle_camera_direction(keycode, w));
	init_viewport(w);
	multithread(w);
	display_camera_menu(w);
	return (CHANGE_CAMERA);
}

void	display_camera_info2(t_world *w)
{
	display(w, (t_xy){10, 270}, 0xFFFF00, "1");
	display(w, (t_xy){10, 290}, 0xFFFF00, "2");
	display(w, (t_xy){10, 310}, 0xFFFF00, "3");
	display(w, (t_xy){10, 330}, 0xFFFF00, "4");
	display(w, (t_xy){10, 350}, 0xFFFF00, "5");
	display(w, (t_xy){10, 370}, 0xFFFF00, "6");
	display(w, (t_xy){10, 400}, 0xFF0000, "Q");
	display(w, (t_xy){20, 270}, 0xFFFFFF, " - Look Front");
	display(w, (t_xy){20, 290}, 0xFFFFFF, " - Look Back");
	display(w, (t_xy){20, 310}, 0xFFFFFF, " - Look Up");
	display(w, (t_xy){20, 330}, 0xFFFFFF, " - Look Down");
	display(w, (t_xy){20, 350}, 0xFFFFFF, " - Look Right");
	display(w, (t_xy){20, 370}, 0xFFFFFF, " - Look Left");
	display(w, (t_xy){20, 400}, 0xFFFFFF, " - Previous menu");
}

void	display_camera_info(t_world *w)
{
	display(w, (t_xy){10, 90,}, 0xFFFF00, "W");
	display(w, (t_xy){10, 110}, 0xFFFF00, "S");
	display(w, (t_xy){10, 130}, 0xFFFF00, "A");
	display(w, (t_xy){10, 150}, 0xFFFF00, "D");
	display(w, (t_xy){10, 180}, 0xFFFF00, "UP");
	display(w, (t_xy){10, 200}, 0xFFFF00, "DOWN");
	display(w, (t_xy){10, 220}, 0xFFFF00, "LEFT");
	display(w, (t_xy){10, 240}, 0xFFFF00, "RIGHT");
	display(w, (t_xy){20, 90}, 0xFFFFFF, " - Move Foward");
	display(w, (t_xy){20, 110}, 0xFFFFFF, " - Move Backwards");
	display(w, (t_xy){20, 130}, 0xFFFFFF, " - Move Left");
	display(w, (t_xy){20, 150}, 0xFFFFFF, " - Move Right");
	display(w, (t_xy){25, 180}, 0xFFFFFF, " - Go Up");
	display(w, (t_xy){45, 200}, 0xFFFFFF, " - Go Down");
	display(w, (t_xy){45, 220}, 0xFFFFFF, " - Rotate Left");
	display(w, (t_xy){55, 240}, 0xFFFFFF, " - Rotate Right");
}

void	display_camera_menu(t_world *w)
{
	mlx_put_image_to_window(w->disp.mlx, w->disp.win, w->disp.menu, 0, 0);
	display_menu_title(w);
	display(w, (t_xy){10, 53}, 0xFFFFFF, "CAMERA");
	display(w, (t_xy){9, 64}, 0xFFA160, "------");
	display_camera_info(w);
	display_camera_info2(w);
}
