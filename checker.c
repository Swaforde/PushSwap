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
