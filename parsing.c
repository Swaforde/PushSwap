#include "push_swap.h"

void parsing(int value, t_tab *tabList)
{
    static int index;
    tabList->tabA[index] = value;
    index ++;
}