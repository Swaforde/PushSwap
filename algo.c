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
	while (i < count_element(tabList->tabA, tabList))
	{
		tmp[i] = tabList->tabA[i];
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
		while (tabList->tabA[i] != tmp[e])
			e ++;
		tabList->tabA[i] = e;
		i ++;
	}
	free (tmp);
}

int	find_same_number(long int *tab, int num, t_tab *tabList)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	while (i < count_element(tab, tabList))
	{
		if (tab[i] == num)
			s++;
		i ++;
	}
	return (s);
}

int	find_smaller_num(t_tab *tabList)
{
	int	i;
	int	tmp;
	int	tmp2;

	i = 0;
	tmp = tabList->tabB[0];
	tmp2 = 0;
	while (i < tabList->max_index)
	{
		tmp2 = tabList->tabB[i];
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

int	get_position_of_element(int num, t_tab *tabList)
{
	int	i;

	i = 0;
	while (tabList->tabB[i] != num)
		i ++;
	if (i <= (count_element(tabList->tabB, tabList) / 2))
		return (1);
	return (0);
}

void	finish_sort(t_tab *tabList)
{
	int	tmp;

	tmp = 0;
	while (check_empty_tab(tabList->tabB, tabList) != 1)
	{
		tmp = find_smaller_num(tabList);
		while (tabList->tabB[0] != tmp)
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

void	sort(t_tab *tabList, t_chunk *chunk)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (check_empty_tab(tabList->tabA, tabList) != 1)
	{
		if (tabList->tabA[0] <= chunk->index_2)
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
