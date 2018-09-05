/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 10:12:27 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/08/25 10:12:28 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation_z(float n, t_mass *m)
{
	int		y;
	int		x;
	t_point	time;

	y = -1;
	while (++y < m->m_y)
	{
		x = -1;
		while (++x < m->m_x)
		{
			time = m->map[y][x];
			time.x = (m->map[y][x].x - W / 2) * cos(n) -
			(m->map[y][x].y - H / 2) * sin(n) + W / 2;
			time.y = (m->map[y][x].x - W / 2) * sin(n) +
			(m->map[y][x].y - H / 2) * cos(n) + H / 2;
			m->map[y][x] = time;
		}
	}
}

void	rotation_y(float n, t_mass *m)
{
	int		y;
	int		x;
	t_point	time;

	y = -1;
	while (++y < m->m_y)
	{
		x = -1;
		while (++x < m->m_x)
		{
			time = m->map[y][x];
			time.x = (m->map[y][x].x - W / 2) * cos(n) -
			m->map[y][x].z * sin(n) + W / 2;
			time.z = m->map[y][x].z * cos(n) +
			(m->map[y][x].x - W / 2) * sin(n);
			m->map[y][x] = time;
		}
	}
}

void	rotation_x(float n, t_mass *m)
{
	int		y;
	int		x;
	t_point	time;

	y = -1;
	while (++y < m->m_y)
	{
		x = -1;
		while (++x < m->m_x)
		{
			time = m->map[y][x];
			time.y = (m->map[y][x].y - H / 2) * cos(n) -
			m->map[y][x].z * sin(n) + H / 2;
			time.z = m->map[y][x].z * cos(n) +
			(m->map[y][x].y - H / 2) * sin(n);
			m->map[y][x] = time;
		}
	}
}
