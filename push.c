#include "push_swap.h"

int	push_a(t_tab *tabList)
{
	int	i;

	i = 0;
	if (count_element(tabList->tabB, tabList) != 0)
	{
		while (i < tabList->max_index)
		{
			if (tabList->tabA[i] == empty)
			{
				tabList->tabA[i] = tabList->tabB[0];
				tabList->tabB[0] = empty;
				forced_rotate_b(tabList);
				return (1);
			}
			else
			{
				forced_reverse_a(tabList);
				tabList->tabA[i] = tabList->tabB[0];
				tabList->tabB[0] = empty;
				forced_rotate_b(tabList);
				return (1);
			}
			i ++;
		}
	}
	return (0);
}

int	push_b(t_tab *tabList)
{
	int	i;

	i = 0;
	if (count_element(tabList->tabA, tabList) != 0)
	{
		while (i < tabList->max_index)
		{
			if (tabList->tabB[i] == empty)
			{
				tabList->tabB[i] = tabList->tabA[0];
				tabList->tabA[0] = empty;
				forced_rotate_a(tabList);
				return (1);
			}
			else
			{
				forced_reverse_b(tabList);
				tabList->tabB[i] = tabList->tabA[0];
				tabList->tabA[0] = empty;
				forced_rotate_a(tabList);
				return (1);
			}
			i ++;
		}
	}
	return (0);
}
