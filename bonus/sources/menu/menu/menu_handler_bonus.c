/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_handler_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:24:56 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:24:57 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_menu_state	handle_closed_menu(int keycode, t_world *w)
{
	if (keycode != M)
		return (MENU_CLOSED);
	display_main_menu(w);
	return (MENU_OPENED);
}

t_menu_state	handle_opened_menu(int keycode, t_world *w)
{
	if (keycode == ONE)
		return (display_camera_menu(w), CHANGE_CAMERA);
	else if (keycode == TWO)
		return (display_amb_light_menu(w), CHANGE_AMBIENT_LIGHT);
	else if (keycode == THREE)
		return (display_light_choice_menu(w), CHOOSE_LIGHT);
	else if (keycode == FOUR)
		return (display_sphere_choice_menu(w), CHOOSE_SPHERE);
	else if (keycode == FIVE)
		return (display_plane_choice_menu(w), CHOOSE_PLANE);
	else if (keycode == SIX)
		return (display_cylinder_choice_menu(w), CHOOSE_CYLINDER);
	else if (keycode == SEVEN)
		return (display_cone_choice_menu(w), CHOOSE_CONE);
	else if (keycode == Q)
		return (multithread(w), MENU_CLOSED);
	return (MENU_OPENED);
}
