/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 13:33:48 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/09/05 13:33:51 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
void			put_pixel_to_image(t_mass *m, int x, int y, int color)
{
	if (x > -1 && y > -1 && x < W && y < H)
		m->img[x + y * W] = color;
}

void	line_draw(t_point p1, t_point p2, t_mass *m)
{
	float			x;
	float			y;

	x = p1.x;
	y = p1.y;
	if (fabs(p1.x - p2.x) > fabs(p1.y - p2.y))
		while (p1.x > p2.x ? x > p2.x : x < p2.x)
		{
			x > p2.x ? x-- : x++;
			y = ((x - p1.x) / (p2.x - p1.x)) * (p2.y - p1.y) + p1.y;
			put_pixel_to_image(m, x, y, p1.color);
		}
	else
		while (p1.y > p2.y ? y > p2.y : y < p2.y)
		{
			y > p2.y ? y-- : y++;
			x = ((y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y)) + p1.x;
			put_pixel_to_image(m, x, y, p2.color);
		}
}

void	map_draw(t_mass *m)
{
	int	y;
	int	x;
	ft_bzero(m->img, H * W * 4);
	y = -1;
	while (++y < m->m_y)
	{
		x = -1;
		while (++x < m->m_x)
		{
			if (x + 1 < m->m_x)
				line_draw(m->map[y][x], m->map[y][x + 1], m);
			if (y + 1 < m->m_y)
				line_draw(m->map[y][x], m->map[y + 1][x], m);
		}
	}
	mlx_put_image_to_window(m->mlx, m->win, m->img_ptr, 0, 0);
}
