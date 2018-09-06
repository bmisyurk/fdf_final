/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 13:33:25 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/09/05 13:33:28 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	change_color(double z)
{
	unsigned int color;

	color = 0;
	(z >= -10 && z <= -5) ? color = (0x172f0d) : 0;
	(z > -5 && z <= 4) ? color = (0x5d9ff9) : 0;
	(z > -1 && z <= 0) ? color = (0x0700F5) : 0;
	(z > 0 && z <= 3) ? color = (0x1DAFFC) : 0;
	(z > 3 && z <= 5) ? color = (0x35464B) : 0;
	(z > 5 && z <= 7) ? color = (0x4D3D2D) : 0;
	(z > 7 && z <= 9) ? color = (0x633C18) : 0;
	(z > 9 && z <= 14) ? color = (0x894C10) : 0;
	(z > 14 && z <= 18) ? color = (0xE5BE8B) : 0;
	(z > 18 && z <= 20) ? color = (0x31ff06) : 0;
	(z > 20 && z <= 23) ? color = (0x118401) : 0;
	(z > 23 && z <= 29) ? color = (0x009407) : 0;
	(z > 29 && z <= 32) ? color = (0x00E007) : 0;
	(z > 32 && z <= 35) ? color = (0x996315) : 0;
	(z > 35 && z <= 40) ? color = (0xFFFFFF) : 0;
	color == 0 ? color = (0xFFFFFF) : 0;
	return (color);
}

unsigned int	ft_atoi_color(char *str)
{
	int				i;
	int				k;
	unsigned int	num;
	char			*arr;

	i = -1;
	num = 0;
	k = -1;
	arr = (char *)ft_memalloc(sizeof(char) * 17);
	while (++i < 16)
		if (i < 10)
			arr[i] = i + 48;
		else
			arr[i] = i + 55;
	i = -1;
	while (str[++i] != ' ' && str[i] != '\0')
		while (arr[++k] != '\0')
			if (ft_toupper(str[i]) == arr[k])
			{
				num = num * 16 + k;
				k = -1;
				break ;
			}
	ft_strdel(&arr);
	return (num);
}
