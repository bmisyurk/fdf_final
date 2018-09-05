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
	if (z >= 1 && z <= 99)
		return (0xDE5D83);
	else if (z >= -99 && z <= -1)
		return (0x87A96B);
	else
		return (0x78DBE2);
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
