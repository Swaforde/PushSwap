/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:03 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:43:06 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_reverse_a(t_tab *tabList)
{
	long int	tmp;
	int			i;

	i = count_element(tabList->tab_a, tabList) - 1;
	tmp = tabList->tab_a[i];
	while (i > 0)
	{
		tabList->tab_a[i] = tabList->tab_a[i - 1];
		i --;
	}
	tabList->tab_a[i] = tmp;
}

void	rotate_reverse_b(t_tab *tabList)
{
	long int	tmp;
	int			i;

	i = count_element(tabList->tab_b, tabList) - 1;
	tmp = tabList->tab_b[i];
	while (i > 0)
	{
		tabList->tab_b[i] = tabList->tab_b[i - 1];
		i --;
	}
	tabList->tab_b[i] = tmp;
}

void	rotate_b(t_tab *tabList)
{
	long int	tmp;
	int			i;

	tmp = tabList->tab_b[0];
	i = 1;
	while (i < count_element(tabList->tab_b, tabList))
	{
		tabList->tab_b[i - 1] = tabList->tab_b[i];
		i ++;
	}
	tabList->tab_b[i - 1] = tmp;
}

void	rotate_a(t_tab *tabList)
{
	long int	tmp;
	int			i;

	tmp = tabList->tab_a[0];
	i = 1;
	while (i < count_element(tabList->tab_a, tabList))
	{
		tabList->tab_a[i - 1] = tabList->tab_a[i];
		i ++;
	}
	tabList->tab_a[i - 1] = tmp;
}

void	rotate_ab(t_tab *tabList)
{
	rotate_a(tabList);
	rotate_b(tabList);
}
