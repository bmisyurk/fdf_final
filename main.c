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

int	main(int argc, char **argv)
{
	t_mass	*m;

	argc != 2 ? out_error("invalid number of arguments!") : 0;
	if (!(m = (t_mass*)malloc(sizeof(*m))))
		out_error("error");
	read_map(argv[1], m);
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, W, H, "FDF");
	put_to_centre(m);
	map_draw(m);
	mlx_hook(m->win, 2, 1L << 1, key_hooks, m);
	mlx_loop(m->mlx);
	return (0);
}
