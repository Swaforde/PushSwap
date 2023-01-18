#include "push_swap.h"

int	main(int argc, char *argv[])
{
    int     *tabA;
    int     *tabB;
    t_tab   tabList;

    tabA = malloc (argc * sizeof(int));
    tabB = malloc (argc * sizeof(int));
    tabList.tabA = tabA;
    tabList.tabB = tabB;
    if (argc < 2)
        ft_printf("Merci d'entrer une pile d'entier à trier !");
    if (check_integer(argv, argc) == 1)
        ft_printf("Ok\n");
    else
        ft_printf("Ko\n");
    return (1);
}