#include "push_swap.h"

void	forced_reverse_b(t_tab *tabList)
{
	long int	tmp;
	int			i;

	i = tabList->max_index - 1;
	tmp = tabList->tabB[i];
	while (i != 0)
	{
		tabList->tabB[i] = tabList->tabB[i - 1];
		i --;
	}
	tabList->tabB[i] = tmp;
}

void	forced_reverse_a(t_tab *tabList)
{
	long int	tmp;
	int			i;

	i = tabList->max_index - 1;
	tmp = tabList->tabA[i];
	while (i != 0)
	{
		tabList->tabA[i] = tabList->tabA[i - 1];
		i --;
	}
	tabList->tabA[i] = tmp;
}

void	rotate_reverse_ab(t_tab *tabList)
{
	rotate_reverse_a(tabList);
	rotate_reverse_b(tabList);
}
