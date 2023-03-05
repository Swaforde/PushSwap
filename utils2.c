/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:03 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:43:06 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	forced_reverse_b(t_tab *tabList)
{
	long int	tmp;
	int			i;

	i = tabList->max_index - 1;
	tmp = tabList->tab_b[i];
	while (i != 0)
	{
		tabList->tab_b[i] = tabList->tab_b[i - 1];
		i --;
	}
	tabList->tab_b[i] = tmp;
}

void	forced_reverse_a(t_tab *tabList)
{
	long int	tmp;
	int			i;

	i = tabList->max_index - 1;
	tmp = tabList->tab_a[i];
	while (i != 0)
	{
		tabList->tab_a[i] = tabList->tab_a[i - 1];
		i --;
	}
	tabList->tab_a[i] = tmp;
}

void	rotate_reverse_ab(t_tab *tabList)
{
	rotate_reverse_a(tabList);
	rotate_reverse_b(tabList);
}

int	index_el(int num, t_tab *tab_list)
{
	int	i;

	i = 0;
	while (tab_list->tab_a[i] != num)
		i ++;
	return (i);
}

long int	ft_long_atoi(const char *str)
{
	int			i;
	long int	return_value;
	int			is_negative;

	i = 0;
	return_value = 0;
	is_negative = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i ++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_negative = 1;
		i ++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		return_value = return_value * 10 + (str[i++] - 48);
	if (is_negative == 1)
		return (return_value * -1);
	return (return_value);
}
