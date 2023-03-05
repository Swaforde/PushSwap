/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:03 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:43:06 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_tab *tab_list)
{
	int	i;
	int	tmp;

	i = 1;
	tmp = tab_list->tab_a[0];
	while (i < tab_list->max_index)
	{
		if (tab_list->tab_a[i] < tmp)
			return (0);
		i ++;
		tmp = tab_list->tab_a[i - 1];
	}
	return (1);
}

void	clear_tab(long int *tab, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		tab[i] = empty;
		i ++;
	}
}

void	init_tab(t_tab *tabList)
{
	int	i;

	i = 0;
	while (i < tabList->max_index)
	{
		tabList->tab_b[i] = empty;
		i ++;
	}
}

void	start_sort(t_tab *tab_list, t_chunk *chunk, int allowed_size)
{
	simplification(tab_list, tab_list->max_index);
	chunk_setup(allowed_size, chunk);
	if (is_sorted(tab_list) == 1)
		exit (0);
	if (allowed_size == 3)
		small_sort(tab_list, 0);
	else if (allowed_size == 5)
		sort_5_num(tab_list);
	else
		sort(tab_list, chunk);
}

int	main(int argc, char *argv[])
{
	long int	*tab_a;
	long int	*tab_b;
	t_tab		tab_list;
	int			allowed_size;
	t_chunk		chunk;

	allowed_size = get_max_index(argv, &tab_list, argc);
	tab_a = malloc (allowed_size * sizeof(long int));
	tab_b = malloc (allowed_size * sizeof(long int));
	tab_list.tab_a = tab_a;
	tab_list.tab_b = tab_b;
	tab_list.total = argc;
	tab_list.max_index = get_max_index(argv, &tab_list, argc);
	chunk_setup(allowed_size, &chunk);
	init_tab(&tab_list);
	if (argc < 2)
		exit (0);
	if (check_integer(argv, &tab_list, 1, 0) != 1)
		exit_program();
	if (check_doublon(&tab_list) == 0)
		exit_program();
	start_sort(&tab_list, &chunk, allowed_size);
	exit (0);
}
