/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:03 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:43:06 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simplification(t_tab *tabList, int size)
{
	long int	*tmp;
	int			i;
	int			tmp2;
	int			operation;

	tmp = malloc (size * sizeof(long int));
	if (!tmp)
		return ;
	i = 0;
	tmp2 = 0;
	operation = 1;
	while (i < count_element(tabList->tab_a, tabList))
	{
		tmp[i] = tabList->tab_a[i];
		i ++;
	}
	i = 0;
	simple_utils(operation, size, tmp2, tmp);
	set_value(tabList, tmp, size);
	free (tmp);
	tmp = NULL;
}

void	finish_sort(t_tab *tabList)
{
	int	tmp;

	tmp = 0;
	while (check_empty_tab(tabList->tab_b, tabList) != 1)
	{
		tmp = find_smaller_num(tabList);
		while (tabList->tab_b[0] != tmp)
		{
			if (get_position_of_element(tmp, tabList) == 1)
				rotate_b(tabList);
			else
				rotate_reverse_b(tabList);
		}
		push_a(tabList);
	}
}

void	sort(t_tab *tabList, t_chunk *chunk)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (check_empty_tab(tabList->tab_a, tabList) != 1)
	{
		if (tabList->tab_a[0] <= chunk->index_2)
		{
			if (i == chunk->index_2)
				chunk->index_2 += chunk->step;
			push_b(tabList);
			i++;
		}
		else
			rotate_a(tabList);
	}
	finish_sort(tabList);
}

void	sort_5_num(t_tab *tab_list)
{
	while (count_element(tab_list->tab_a, tab_list) != 3)
	{
		if (tab_list->tab_a[0] == 1 || tab_list->tab_a[0] == 0)
			push_b(tab_list);
		else
		{
			if (index_el(0, tab_list) <= 2 || index_el(1, tab_list) <= 2)
				rotate_a(tab_list);
			else
				rotate_reverse_a(tab_list);
		}
	}
	if (tab_list->tab_b[0] < tab_list->tab_b[1])
		swap_b(tab_list);
	small_sort(tab_list, 2);
	push_a(tab_list);
	push_a(tab_list);
}

void	small_sort(t_tab *tab_list, int low)
{
	if (index_el(low, tab_list) == 0)
		small_sort_util(tab_list);
	if (index_el(low, tab_list) == 1)
	{
		if (tab_list->tab_a[0] < tab_list->tab_a[2])
			swap_a(tab_list);
		else
			rotate_a(tab_list);
	}
	if (index_el(low, tab_list) == 2)
	{
		if (tab_list->tab_a[0] > tab_list->tab_a[1])
		{
			swap_a(tab_list);
			rotate_reverse_a(tab_list);
		}
		else
			rotate_reverse_a(tab_list);
	}
}
