/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:03 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:43:06 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_value(t_tab *tab_list, long int *tmp, int size)
{
	int	i;
	int	e;

	i = 0;
	e = 0;
	while (i < size)
	{
		e = 0;
		while (tab_list->tab_a[i] != tmp[e])
			e ++;
		tab_list->tab_a[i] = e;
		i ++;
	}
}

void	simple_utils(int operation, int size, int tmp2, long int *tmp)
{
	int	i;

	i = 0;
	while (operation == 1)
	{
		operation = 0;
		i = 0;
		while (i < (size - 1))
		{
			if (tmp[i] > tmp[i + 1])
			{
				tmp2 = tmp[i];
				tmp[i] = tmp[i + 1];
				tmp[i + 1] = tmp2;
				operation = 1;
			}
			i ++;
		}
	}
}

void	small_sort_util(t_tab *tab_list)
{
	if (tab_list->tab_a[1] > tab_list->tab_a[2])
	{
		rotate_a(tab_list);
		swap_a(tab_list);
		rotate_reverse_a(tab_list);
	}
	else
	{
		rotate_a(tab_list);
		rotate_a(tab_list);
		rotate_a(tab_list);
	}
}