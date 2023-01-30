#include "push_swap.h"

void	rotate_a(t_tab *tabList)
{
	long int	tmp;
	int			i;

	tmp = tabList->tabA[0];
	i = 1;
	while (i < count_element(tabList->tabA, tabList))
	{
		tabList->tabA[i - 1] = tabList->tabA[i];
		i ++;
	}
	tabList->tabA[i - 1] = tmp;
}

void	rotate_reverse_a(t_tab *tabList)
{
	long int	tmp;
	int			i;

	i = count_element(tabList->tabA, tabList) - 1;
	tmp = tabList->tabA[i];
	while (i > 0)
	{
		tabList->tabA[i] = tabList->tabA[i - 1];
		i --;
	}
	tabList->tabA[i] = tmp;
}

void	rotate_reverse_b(t_tab *tabList)
{
	long int	tmp;
	int			i;

	i = count_element(tabList->tabB, tabList) - 1;
	tmp = tabList->tabB[i];
	while (i > 0)
	{
		tabList->tabB[i] = tabList->tabB[i - 1];
		i --;
	}
	tabList->tabB[i] = tmp;
}

void	rotate_b(t_tab *tabList)
{
	long int	tmp;
	int			i;

	tmp = tabList->tabB[0];
	i = 1;
	while (i < count_element(tabList->tabB, tabList))
	{
		tabList->tabB[i - 1] = tabList->tabB[i];
		i ++;
	}
	tabList->tabB[i - 1] = tmp;
}

void	rotate_ab(t_tab *tabList)
{
	rotate_a(tabList);
	rotate_b(tabList);
}

void	rotate_reverse_ab(t_tab *tabList)
{
	rotate_reverse_a(tabList);
	rotate_reverse_b(tabList);
}