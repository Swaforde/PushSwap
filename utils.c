/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:03 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:43:06 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smaller_num(t_tab *tabList)
{
	int	i;
	int	tmp;
	int	tmp2;

	i = 0;
	tmp = tabList->tab_b[0];
	tmp2 = 0;
	while (i < tabList->max_index)
	{
		tmp2 = tabList->tab_b[i];
		if (tmp2 > tmp && tmp2 != 149477148)
			tmp = tmp2;
		i ++;
	}
	return (tmp);
}

int	check_empty_tab(long int *tab, t_tab *tabList)
{
	int	i;

	i = 0;
	while (i < tabList->max_index)
	{
		if (tab[i] != empty)
			return (0);
		i ++;
	}
	return (1);
}

void	forced_rotate_b(t_tab *tabList)
{
	long int	tmp;
	int			i;

	tmp = tabList->tab_b[0];
	i = 1;
	while (i < tabList->max_index)
	{
		tabList->tab_b[i - 1] = tabList->tab_b[i];
		i ++;
	}
	tabList->tab_b[i - 1] = tmp;
}

void	forced_rotate_a(t_tab *tabList)
{
	long int	tmp;
	int			i;

	tmp = tabList->tab_a[0];
	i = 1;
	while (i < tabList->max_index)
	{
		tabList->tab_a[i - 1] = tabList->tab_a[i];
		i ++;
	}
	tabList->tab_a[i - 1] = tmp;
}

int	get_position_of_element(int num, t_tab *tabList)
{
	int	i;

	i = 0;
	while (tabList->tab_b[i] != num)
		i ++;
	if (i <= (count_element(tabList->tab_b, tabList) / 2))
		return (1);
	return (0);
}
