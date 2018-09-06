/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 13:34:08 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/09/05 13:34:11 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_map(char *file, t_mass *m)
{
	int		fd;
	char	*line;
	t_lst	*list;
	int		ret;

	m->m_y = 0;
	fd = open(file, O_RDONLY);
	list = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_new_list(&list, line);
		m->m_y++;
	}
	ret == -1 ? out_error("file isn't read") : 0;
	close(fd);
	if (!(m->map = (t_point **)ft_memalloc(sizeof(t_point *) * m->m_y)))
		out_error("Error");
	ft_strdel(&line);
	valid_map(m, &list);
}
