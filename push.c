#include "push_swap.h"

void	utils_pa(t_tab *tab_list, int i)
{
	tab_list->tabA[i] = tab_list->tabB[0];
	tab_list->tabB[0] = empty;
	forced_rotate_b(tab_list);
}

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
				utils_pa(tabList, i);
				return (1);
			}
			else
			{
				forced_reverse_a(tabList);
				utils_pa(tabList, i);
				return (1);
			}
			i ++;
		}
	}
	return (0);
}

void	utils_pb(t_tab *tab_list, int i)
{
	tab_list->tabB[i] = tab_list->tabA[0];
	tab_list->tabA[0] = empty;
	forced_rotate_a(tab_list);
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
				utils_pb(tabList, i);
				return (1);
			}
			else
			{
				forced_reverse_b(tabList);
				utils_pb(tabList, i);
				return (1);
			}
			i ++;
		}
	}
	return (0);
}
