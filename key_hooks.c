/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 13:33:57 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/09/05 13:34:00 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	keys_move(int key, t_mass *m)
{
	int x;
	int y;

	y = -1;
	while (++y < m->m_y)
	{
		x = -1;
		while (++x < m->m_x)
		{
			key == 125 ? m->map[y][x].y += 10 : 0;
			key == 126 ? m->map[y][x].y -= 10 : 0;
			key == 123 ? m->map[y][x].x -= 10 : 0;
			key == 124 ? m->map[y][x].x += 10 : 0;
		}
	}
}

void	key_zoom(int key, t_mass *m)
{
	int	x;
	int	y;

	y = -1;
	while (++y < m->m_y)
	{
		x = -1;
		while (++x < m->m_x)
			if (key == 69)
			{
				m->map[y][x].x = (m->map[y][x].x - W / 2) * 1.3 + W / 2;
				m->map[y][x].y = (m->map[y][x].y - H / 2) * 1.3 + H / 2;
				m->map[y][x].z = m->map[y][x].z * 1.3;
			}
			else if (key == 78)
			{
				m->map[y][x].x = (m->map[y][x].x - W / 2) / 1.3 + W / 2;
				m->map[y][x].y = (m->map[y][x].y - H / 2) / 1.3 + H / 2;
				m->map[y][x].z = m->map[y][x].z / 1.3;
			}
	}
}

void	key_color(int key, t_mass *m)
{
	int	x;
	int	y;

	y = -1;
	while (++y < m->m_y)
	{
		x = -1;
		while (++x < m->m_x)
			(key == 51) ? m->map[y][x].color = 0xFFFFFF : 0;
	}
}

int		key_hooks(int key, t_mass *m)
{
	if (key == ESC)
		exit(0);
	if (key == 2)
		rotation_z(0.1, m);
	else if (key == 0)
		rotation_z(-0.1, m);
	else if (key == 12)
		rotation_y(0.1, m);
	else if (key == 14)
		rotation_y(-0.1, m);
	else if (key == 13)
		rotation_x(0.1, m);
	else if (key == 1)
		rotation_x(-0.1, m);
	else if (key >= 123 && key <= 126)
		keys_move(key, m);
	else if (key == 78 || key == 69)
		key_zoom(key, m);
	else if (key == 51)
		key_color(key, m);
	mlx_clear_window(m->mlx, m->win);
	map_draw(m);
	return (0);
}
