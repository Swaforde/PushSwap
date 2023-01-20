#include "push_swap.h"

int    push_a(t_tab *tabList)
{
    int i;

    i = 0;
    if (count_element(tabList->tabB, tabList) == 0)
    {
        while (i < tabList->max_index)
        {
            if (tabList->tabA[i] == empty)
            {
                tabList->tabA[i] = tabList->tabB[0];
                return (1);
            }
        }
    }

    return (0);
}