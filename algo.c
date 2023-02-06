#include "push_swap.h"

void	simplification(t_tab *tabList, int size)
{
	long int *tmp;
	int	i;
	int tmp2;
	int operation;

	tmp = malloc (size * sizeof(long int));
	i = 0;
	tmp2 = 0;
	operation = 0;
	while (i < count_element(tabList->tabA, tabList))
	{
		tmp[i] = tabList->tabA[i];
		i ++;
	}

	i = 0;
	while (operation > 0)
	{
		while (i < (size - 1))
		{
			if (tmp[i] > tmp[i + 1])
			{
				tmp2 = tmp[i];
				tmp[i] = tmp[i + 1];
				tmp[i + 1] = tmp2;
				operation ++;
			}
			i ++;
			operation = 0;
		}
	}
	print_tab(tmp, tabList->max_index);
}