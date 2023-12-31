/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_display_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:24:50 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:24:51 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	display_menu_title(t_world *w)
{
	display(w, (t_xy){6, 0}, 0xFFA160, "-----");
	display(w, (t_xy){12, 13}, 0xFFFFFF, "MENU");
	display(w, (t_xy){6, 26}, 0xFFA160, "-----");
	display(w, (t_xy){0, 11}, 0xFFA160, "|");
	display(w, (t_xy){54, 11}, 0xFFA160, "|");
}

void	display_main_menu(t_world *w)
{
	w->menu.i = 0;
	mlx_put_image_to_window(w->disp.mlx, w->disp.win, w->disp.menu, 0, 0);
	display_menu_title(w);
	display_menu_entites(w);
}

void	display_menu_entites(t_world *w)
{
	display(w, (t_xy){10, 53}, 0xFFFFFF, "LIST OF OBJECTS");
	display(w, (t_xy){6, 64}, 0xFFA160, "----------------");
	display(w, (t_xy){5, 85}, 0xFFFF00, "1");
	display(w, (t_xy){5, 105}, 0xFFFF00, "2");
	display(w, (t_xy){5, 125}, 0xFFFF00, "3");
	display(w, (t_xy){25, 85}, 0xFFFFFF, "- CAMERA");
	display(w, (t_xy){25, 105}, 0xFFFFFF, "- AMBIENT LIGHT");
	display(w, (t_xy){25, 125}, 0xFFFFFF, "- LIGHTS");
	search_shapes(w);
	display(w, (t_xy){5, 145 + (++w->menu.i * 20 + 15)}, 0xFFFF00,
		"FOR MORE INFO");
	display(w, (t_xy){5, 145 + (w->menu.i * 20 + 35)}, 0xFFFF00,
		"PRESS A NUMBER");
	display(w, (t_xy){5, 145 + (++w->menu.i * 20 + 50)}, 0xFF0000, "Q");
	display(w, (t_xy){25, 145 + (w->menu.i * 20 + 50)}, 0xFFFFFF,
		"- Quit Menu");
}
