#include "push_swap.h"

void swap_a(t_tab *tabList)
{
    int tmp;

    if (count_element(tabList->tabA, tabList) <= 1)
        return ;
    tmp = tabList->tabA[0];
    tabList->tabA[0] = tabList->tabA[1];
    tabList->tabA[1] = tmp;
}

void swap_b(t_tab *tabList)
{
    int tmp;

    if (count_element(tabList->tabB, tabList) <= 1)
        return ;
    tmp = tabList->tabB[0];
    tabList->tabB[0] = tabList->tabB[1];
    tabList->tabB[1] = tmp;
}

void swap_s(t_tab *tabList)
{
    swap_a(tabList);
    swap_b(tabList);
}