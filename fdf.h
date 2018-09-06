/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 19:57:44 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/08/15 19:57:46 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define W			1000
# define H			1000
# define ESC			53

# include <math.h>
# include "mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "get_next_line.h"

typedef struct		s_lst
{
	char			*cont;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
	unsigned int	color;

}					t_point;

typedef struct		s_mass
{
	void			*mlx;
	void			*win;
	t_point			**map;
	int				m_x;
	int				m_y;
}					t_mass;

void				ft_new_list(t_lst **list, char *content);
int					count(char const *s, char c);
void				line_draw(t_point p1, t_point p2, t_mass *m);
void				read_map(char *name_file, t_mass *m);
void				map_draw(t_mass *m);
void				valid_map(t_mass *m, t_lst **list);
void				parse_line(t_mass *m, char *line, int y);
unsigned int		ft_atoi_color(char *str);
unsigned int		change_color(double z);
void				put_to_centre(t_mass *m);
void				rotation_y(float n, t_mass *m);
void				rotation_x(float n, t_mass *m);
void				rotation_z(float n, t_mass *m);
void				keys_rotate(int key, t_mass *t);
int					key_hooks(int key, t_mass *tg);
void				keys_move(int key, t_mass *m);
void				keys_zoom(int key, t_mass *m);
void				out_error(char *str);
#endif
