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
	print_tab(tabList->tabA, tabList->max_index);
	print_tab(tmp, tabList->max_index);
}