#include "push_swap.h"

void swap_a(t_tab *tabList)
{
    int tmp;

    tmp = tabList->tabA[0];
    tabList->tabA[0] = tabList->tabA[1];
    tabList->tabA[1] = tmp;
}