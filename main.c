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
	int 	bit_per_pixel;
	int 	size_line;
	int 	endian;

	bit_per_pixel = 32;
	size_line = W;
	endian = 1;
	argc != 2 ? out_error("invalid number of arguments!") : 0;
	if (!(m = (t_mass*)malloc(sizeof(*m))))
		out_error("error");
	read_map(argv[1], m);
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, W, H, "Fractol");
	m->img_ptr = mlx_new_image(m->mlx, W, H);
	m->img = (unsigned int *)mlx_get_data_addr(m->img_ptr, &bit_per_pixel, &size_line, &endian);
	put_to_centre(m);
	map_draw(m);
	mlx_hook(m->win, 2, 1L << 1, key_hooks, m);
	mlx_hook(m->win, 17, 1L << 17, exit_cl, m);
	mlx_loop(m->mlx);
	return (0);
}
