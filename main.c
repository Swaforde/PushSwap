#include "push_swap.h"
#include "stdio.h"

int	main(int argc, char *argv[])
{
    long int     *tabA;
    long int     *tabB;
    t_tab   tabList;

    tabA = malloc (argc * sizeof(long int));
    tabB = malloc (argc * sizeof(long int));
    tabList.tabA = tabA;
    tabList.tabB = tabB;
    if (argc < 2)
        ft_printf("Merci d'entrer une pile d'entier à trier !");
    if (check_integer(argv, argc, &tabList) == 1)
        ft_printf("Ok\n");
    else
        ft_printf("Ko\n");
    ft_printf("%d\n", tabList.tabA[0]);
    ft_printf("%d\n", tabList.tabA[1]);
    return (1);
}