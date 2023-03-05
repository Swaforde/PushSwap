/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:03 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:43:06 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_tab *tabList)
{
	int	tmp;

	if (count_element(tabList->tab_a, tabList) <= 1)
		return ;
	tmp = tabList->tab_a[0];
	tabList->tab_a[0] = tabList->tab_a[1];
	tabList->tab_a[1] = tmp;
}

void	swap_b(t_tab *tabList)
{
	int	tmp;

	if (count_element(tabList->tab_b, tabList) <= 1)
		return ;
	tmp = tabList->tab_b[0];
	tabList->tab_b[0] = tabList->tab_b[1];
	tabList->tab_b[1] = tmp;
}

void	swap_s(t_tab *tabList)
{
	swap_a(tabList);
	swap_b(tabList);
}
