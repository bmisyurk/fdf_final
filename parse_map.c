/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 13:34:17 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/09/05 13:34:20 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	valid_map(t_mass *m, t_lst **list)
{
	int		y;
	t_lst	*p;

	m->m_x = count((*list)->cont, ' ');
	y = 0;
	while ((*list))
	{
		if (count((*list)->cont, ' ') != m->m_x)
			out_error("map error");
		m->map[y] = (t_point *)ft_memalloc(sizeof(t_point) * (m->m_x + 1));
		parse_line(m, (*list)->cont, y);
		p = *list;
		(*list) = (*list)->next;
		free(p->cont);
		free(p);
		y++;
	}
}

void	parse_line(t_mass *m, char *line, int y)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (line[i])
	{
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] && line[i] != ' ')
		{
			m->map[y][x].y = y;
			m->map[y][x].x = x;
			m->map[y][x].z = ft_atoi(line + i);
			while (line[i] && line[i] != ' ' && line[i] != ',')
				i++;
			if (line[i] == ' ' || line[i] == '\0')
				m->map[y][x].color = change_color(m->map[y][x].z);
			else
				m->map[y][x].color = ft_atoi_color(line + i + 3);
			while (line[i] && line[i] != ' ')
				i++;
		}
		x++;
	}
}

int		count(char const *str, char c)
{
	size_t	i;
	size_t	j;
	char	*src;

	if (!str)
		return (0);
	i = 0;
	j = 0;
	src = (char*)str;
	if (src[i] != c)
	{
		j++;
		i++;
	}
	while (src[i] != '\0')
	{
		if (src[i] != c && src[i - 1] == c)
			j++;
		i++;
	}
	return (j);
}
