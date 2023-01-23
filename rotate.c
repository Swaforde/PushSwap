#include "push_swap.h"

void	rotate_a(t_tab *tabList)
{
    long int	*tmp;
	int			index;
	int			i;
	int			y;

	index = 0;
	i = 1;
	y = 0;
    tmp = malloc (count_element(tabList->tabA, tabList) * sizeof(int));
	if (!tmp)
		return ;
	if (count_element(tabList->tabA, tabList) < 2)
		return ;
	while (index < count_element(tabList->tabA, tabList))
	{
		tmp[index] = tabList->tabA[index];
		index ++;
	}
	clear_tab(tabList->tabA, tabList->max_index);
	while (i < index)
	{
		tabList->tabA[y] = tmp[i];
		y ++;
		i ++;
	}
	tabList->tabA[y] = tmp[0];
	free (tmp);
}

void	rotate_b(t_tab *tabList)
{
    long int	*tmp;
	int			index;
	int			i;
	int			y;

	index = 0;
	i = 1;
	y = 0;
    tmp = malloc (count_element(tabList->tabB, tabList) * sizeof(int));
	if (!tmp)
		return ;
	if (count_element(tabList->tabB, tabList) < 2)
		return ;
	while (index < count_element(tabList->tabB, tabList))
	{
		tmp[index] = tabList->tabB[index];
		index ++;
	}
	clear_tab(tabList->tabB, tabList->max_index);
	while (i < index)
	{
		tabList->tabB[y] = tmp[i];
		y ++;
		i ++;
	}
	tabList->tabB[y] = tmp[0];
	free (tmp);
}

void	rotate_ab(t_tab *tabList)
{
	rotate_a(tabList);
	rotate_b(tabList);
}