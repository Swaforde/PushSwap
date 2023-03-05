/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:03 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:43:06 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int(char *str)
{
	long int i;
	i = ft_long_atoi(str);
	if (i > 2147483647 || i < -2147483648)
		return (0);
	return (1);
}

int	check_doublon(t_tab *tab_list)
{
	int	i;
	int	t;
	int tmp;
	int	tmp2;

	i = 0;
	t = 0;
	tmp = 0;
	tmp2 = 0;
	while (i < tab_list->max_index)
	{
		tmp = tab_list->tab_a[i];
		while (t < tab_list->max_index)
		{
			if (tab_list->tab_a[t] == tmp && i != t)
				return 0;
			t ++;
		}
		t = 0;
		i ++;
	}
	return (1);
}

int	check_integer(char **argv, int total, t_tab *tabList)
{
	int	i;
	int	t;

	i = 1;
	t = 0;
	if (total == 2)
	{
		if (big_parsing(tabList, argv[1]) == 1)
			return (1);
		return (0);
	}
	while (i < total)
	{
		if (argv[i][0] == '-' || ft_isdigit((int)argv[i][0]) == 1)
			t = 1;
		else
			return (0);
		while (argv[i][t] != '\0')
		{
			if (ft_isdigit((int)argv[i][t]) == 0)
				return (0);
			t ++;
		}
		if (check_int(argv[i]) == 0)
			return (0);
		parsing(ft_atoi(argv[i]), tabList);
		t = 0;
		i ++;
	}
	return (1);
}

int	get_max_index(char **argv, t_tab *tabList, int argc)
{
	int	i;

	i = 0;
	if (argc == 2)
		i = word_count(argv[1], 32);
	else
		i = argc - 1;
	return (i);
}

void	chunk_setup(int total_element, t_chunk *chunk)
{
	chunk->index_1 = 0;
	if (total_element <= 10)
	{
		chunk->total = 1;
		chunk->index_2 = total_element / 1;
		chunk->step = total_element / 1;
		return ;
	}
	if (total_element <= 100)
	{
		chunk->total = 8;
		chunk->index_2 = total_element / 8;
		chunk->step = total_element / 8;
		return ;
	}
	if (total_element <= 500 && total_element > 100)
	{
		chunk->total = 10;
		chunk->index_2 = total_element / 10;
		chunk->step = total_element / 10;
		return ;
	}
}
