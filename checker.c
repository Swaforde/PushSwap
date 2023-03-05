/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:03 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:43:06 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_element(long int *tab, t_tab *tabList)
{
	int	element;
	int	i;

	element = 0;
	i = 0;
	while (i < tabList->max_index)
	{
		if (tab[i] != empty)
		element ++;
		i ++;
	}
	return (element);
}

char	**free_tab(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	ptr = NULL;
	return (ptr);
}

void	setup(t_tab *tab_list, int argc, long int *tab_a, long int *tab_b)
{
	tab_list->tab_a = tab_a;
	tab_list->tab_b = tab_b;
	tab_list->total = argc;
}
