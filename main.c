#include "push_swap.h"
#include "stdio.h"

void    clear_tab(long int *tab, int max)
{
    int i;

    i = 0;
    while (i < max)
    {
        tab[i] = empty;
        i ++;
    }
}

void       init_tab(t_tab *tabList)
{
    int i;

    i = 0;
    while (i < tabList->max_index)
    {
        tabList->tabB[i] = empty;
        i ++;
    }
}

void    print_tab(long int *tab, int max)
{
    int i;

    i = 0;
    ft_printf("|| Début de l'impression de la pile ||\n\n");
    while (i < max)
    {
        printf ("Index : %d || ",  i);
        printf ("Value : %li\n", tab[i]);
        i ++;
    }
    ft_printf("\n|| Fin de l'impression de la pile ||\n");
}

int	main(int argc, char *argv[])
{
    long int     *tabA;
    long int     *tabB;
    t_tab   tabList;

    tabA = malloc (argc * sizeof(long int));
    tabB = malloc (argc * sizeof(long int));
    tabList.tabA = tabA;
    tabList.tabB = tabB;
    tabList.max_index = argc - 1;
    init_tab(&tabList);
    if (argc < 2)
        ft_printf("Merci d'entrer une pile d'entier à trier !");
    if (check_integer(argv, argc, &tabList) == 1)
        ft_printf("Ok\n");
    else
        ft_printf("Ko\n");
	//simplification(&tabList, argc);
	push_b(&tabList);
	print_tab(tabList.tabA, tabList.max_index);
	print_tab(tabList.tabB, tabList.max_index);
	push_b(&tabList);
	print_tab(tabList.tabA, tabList.max_index);
	print_tab(tabList.tabB, tabList.max_index);

	ft_printf("////////////////\n");

	push_a(&tabList);
	print_tab(tabList.tabA, tabList.max_index);
	print_tab(tabList.tabB, tabList.max_index);
	push_a(&tabList);
	print_tab(tabList.tabA, tabList.max_index);
	print_tab(tabList.tabB, tabList.max_index);
    return (1);
}