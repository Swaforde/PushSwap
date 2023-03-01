#include "push_swap.h"

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

void	forced_rotate_b(t_tab *tabList)
{
	long int	tmp;
	int			i;

	tmp = tabList->tabB[0];
	i = 1;
	while (i < tabList->max_index)
	{
		tabList->tabB[i - 1] = tabList->tabB[i];
		i ++;
	}
	tabList->tabB[i - 1] = tmp;
}

void	forced_rotate_a(t_tab *tabList)
{
	long int	tmp;
	int			i;

	tmp = tabList->tabA[0];
	i = 1;
	while (i < tabList->max_index)
	{
		tabList->tabA[i - 1] = tabList->tabA[i];
		i ++;
	}
	tabList->tabA[i - 1] = tmp;
}
