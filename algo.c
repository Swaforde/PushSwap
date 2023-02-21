#include "push_swap.h"

void	simplification(t_tab *tabList, int size)
{
	long int *tmp;
	int	i;
	int tmp2;
	int operation;
	int e;

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
		while (i < (size - 2))
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
	int i;
	int s;

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

int find_smaller_num(t_tab *tabList)
{
	int i;
	int tmp;
	int tmp2;

	i = 0;
	tmp = tabList->tabA[0];
	tmp2 = 0;
	while (i < tabList->max_index)
	{
		tmp2 = tabList->tabA[i];
		if (tmp2 < tmp)
			tmp = tmp2;
		i ++;
	}

	return (tmp);
}

int check_empty_tab(long int *tab, t_tab *tabList)
{
	int i;

	i = 0;
	while (i < tabList->max_index)
	{
		if (tab[i] != empty)
			return (0);
		i ++;
	}
	return (1);
}

void sort(t_tab *tabList)
{
	int i;
	int tmp;

	i = 0;
	tmp = 0;
	while (check_empty_tab(tabList->tabA, tabList) != 1)
	{
		tmp = find_smaller_num(tabList);
		if (tabList->tabA[0] == tmp)
		{
			push_b(tabList);
			ft_printf("pb\n");
		}
		rotate_a(tabList);
		ft_printf("ra\n");
		i ++;
	}

	i = 0;

	while (tabList->tabB[0] != empty)
	{
		push_a(tabList);
		ft_printf("pa\n");
	}
}