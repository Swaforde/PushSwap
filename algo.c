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
	int			e;

	tmp = malloc (size * sizeof(long int));
	i = 0;
	tmp2 = 0;
	operation = 1;
	while (i < count_element(tabList->tab_a, tabList))
	{
		tmp[i] = tabList->tab_a[i];
		i ++;
	}
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
	i = 0;
	e = 0;
	while (i < size)
	{
		e = 0;
		while (tabList->tab_a[i] != tmp[e])
			e ++;
		tabList->tab_a[i] = e;
		i ++;
	}
	free (tmp);
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
			{
				rotate_b(tabList);
				ft_printf("rb\n");
			}
			else
			{
				rotate_reverse_b(tabList);
				ft_printf("rrb\n");
			}
		}
		push_a(tabList);
		ft_printf("pa\n");
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
			{
				chunk->index_1 += chunk->step;
				chunk->index_2 += chunk->step;
			}
			push_b(tabList);
			ft_printf("pb\n");
			i++;
		}
		else
		{
			rotate_a(tabList);
			ft_printf("ra\n");
		}
	}
	finish_sort(tabList);
}

void	sort_5_num(t_tab *tab_list)
{
	while (count_element(tab_list->tab_a, tab_list) != 3)
	{
		if (tab_list->tab_a[0] == 1 || tab_list->tab_a[0] == 0)
		{
			push_b(tab_list);
			ft_printf("pb\n");
		}
		else
		{
			if (get_index_of_element(0, tab_list) <= 2 || get_index_of_element(1, tab_list) <= 2)
			{
				rotate_a(tab_list);
				ft_printf("ra\n");
			}
			else
			{
				rotate_reverse_a(tab_list);
				ft_printf("rra\n");
			}
		}
	}
	if (tab_list->tab_b[0] < tab_list->tab_b[1])
	{
		swap_b(tab_list);
		ft_printf("sb\n");
	}
	small_sort(tab_list, 2);
	push_a(tab_list);
	ft_printf("pa\n");
	push_a(tab_list);
	ft_printf("pa\n");
}

void	small_sort(t_tab *tab_list, int low)
{
	if (get_index_of_element(low, tab_list) == 0)
	{
		if (tab_list->tab_a[1] > tab_list->tab_a[2])
		{
			rotate_a(tab_list);
			ft_printf("ra\n");
			swap_a(tab_list);
			ft_printf("sa\n");
			rotate_reverse_a(tab_list);
			ft_printf("rra\n");
		}
		else
		{
			rotate_a(tab_list);
			ft_printf("ra\n");
			rotate_a(tab_list);
			ft_printf("ra\n");
			rotate_a(tab_list);
			ft_printf("ra\n");
		}
	}
	if (get_index_of_element(low, tab_list) == 1)
	{
		if (tab_list->tab_a[0] < tab_list->tab_a[2])
		{
			swap_a(tab_list);
			ft_printf("sa\n");
		}
		else
		{
			rotate_a(tab_list);
			ft_printf("ra\n");
		}
	}
	if (get_index_of_element(low, tab_list) == 2)
	{
		if (tab_list->tab_a[0] > tab_list->tab_a[1])
		{
			swap_a(tab_list);
			ft_printf("sa\n");
			rotate_reverse_a(tab_list);
			ft_printf("rra\n");
		}
		else
		{
			rotate_reverse_a(tab_list);
			ft_printf("rra\n");
		}
	}
}
