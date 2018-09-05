/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 13:33:37 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/09/05 13:33:39 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_new_list(t_lst **list, char *content)
{
	t_lst	*p_lst;
	t_lst	*p_cnt;

	p_lst = *list;
	p_cnt = (t_lst *)ft_memalloc(sizeof(t_lst));
	p_cnt->cont = content;
	p_cnt->next = NULL;
	if (*list == NULL)
		*list = p_cnt;
	else
	{
		while (p_lst->next)
			p_lst = p_lst->next;
		p_lst->next = p_cnt;
	}
}
