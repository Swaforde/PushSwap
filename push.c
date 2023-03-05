/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:03 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:43:06 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	utils_pa(t_tab *tab_list, int i)
{
	tab_list->tab_a[i] = tab_list->tab_b[0];
	tab_list->tab_b[0] = empty;
	forced_rotate_b(tab_list);
}

int	push_a(t_tab *tabList)
{
	int	i;

	i = 0;
	if (count_element(tabList->tab_b, tabList) != 0)
	{
		while (i < tabList->max_index)
		{
			if (tabList->tab_a[i] == empty)
			{
				utils_pa(tabList, i);
				return (1);
			}
			else
			{
				forced_reverse_a(tabList);
				utils_pa(tabList, i);
				return (1);
			}
			i ++;
		}
	}
	return (0);
}

void	utils_pb(t_tab *tab_list, int i)
{
	tab_list->tab_b[i] = tab_list->tab_a[0];
	tab_list->tab_a[0] = empty;
	forced_rotate_a(tab_list);
}

int	push_b(t_tab *tabList)
{
	int	i;

	i = 0;
	if (count_element(tabList->tab_a, tabList) != 0)
	{
		while (i < tabList->max_index)
		{
			if (tabList->tab_b[i] == empty)
			{
				utils_pb(tabList, i);
				return (1);
			}
			else
			{
				forced_reverse_b(tabList);
				utils_pb(tabList, i);
				return (1);
			}
			i ++;
		}
	}
	return (0);
}
