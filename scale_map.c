/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 13:34:33 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/09/05 13:34:35 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_to_centre(t_mass *m)
{
	int cof;
	int	y;
	int	x;

	cof = m->m_x > m->m_y ? m->m_x : m->m_y;
	cof = W / cof;
	y = -1;
	while (++y < m->m_y)
	{
		x = -1;
		while (++x < m->m_x)
		{
			m->map[y][x].x = (m->map[y][x].x - m->m_x / 2) * cof + W / 2;
			m->map[y][x].y = (m->map[y][x].y - m->m_y / 2) * cof + H / 2;
			m->map[y][x].z = m->map[y][x].z * cof;
		}
	}
}
