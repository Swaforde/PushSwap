#include "push_swap.h"
#include "stdio.h"

void    print_tab(long int *tab, int max)
{
    int i;

    i = 0;
    ft_printf("|| Début de l'impression de la pile ||\n\n");
    while (i < max)
    {
        printf ("Index : %d || ",  i);
        printf ("Value : %lu\n", tab[i]);
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
    if (argc < 2)
        ft_printf("Merci d'entrer une pile d'entier à trier !");
    if (check_integer(argv, argc, &tabList) == 1)
        ft_printf("Ok\n");
    else
        ft_printf("Ko\n");
    tabList.tabB[0] = 10;
    tabList.tabA[2] = empty;
    print_tab(tabList.tabA, tabList.max_index);
    ft_printf ("(%d)", count_element(tabList.tabA, &tabList));
    push_a(&tabList);
    print_tab(tabList.tabA, tabList.max_index);
    ft_printf ("(%d)", count_element(tabList.tabA, &tabList));
    return (1);
}