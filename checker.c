#include "push_swap.h"

int	count_element(long int *tab, t_tab *tabList)
{
	int element;
	int i;

	element = 0;
	i = 0;
	while (i < tabList->max_index)
	{
		if (tab[i] != empty)
		element ++;
		i ++;
	}
	return (element);
}
