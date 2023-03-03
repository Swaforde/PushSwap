#include "push_swap.h"
#include "stdio.h"

void	clear_tab(long int *tab, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		tab[i] = empty;
		i ++;
	}
}

void	init_tab(t_tab *tabList)
{
	int	i;

	i = 0;
	while (i < tabList->max_index)
	{
		tabList->tabB[i] = empty;
		i ++;
	}
}

void	print_tab(long int *tab, int max)
{
	int	i;

	i = 0;
	ft_printf("|| Début de l'impression de la pile ||\n\n");
	while (i < max)
	{
		printf("Index : %d || ", i);
		printf("Value : %li\n", tab[i]);
		i ++;
	}
	ft_printf("\n|| Fin de l'impression de la pile ||\n");
}

int	main(int argc, char *argv[])
{
	long int	*tab_a;
	long int	*tab_b;
	t_tab		tab_list;
	int			allowed_size;
	t_chunk		chunk;

	allowed_size = get_max_index(argv, &tab_list, argc);
	tab_a = malloc (allowed_size * sizeof(long int));
	tab_b = malloc (allowed_size * sizeof(long int));
	tab_list.tabA = tab_a;
	tab_list.tabB = tab_b;
	tab_list.max_index = get_max_index(argv, &tab_list, argc);
	chunk_setup(allowed_size, &chunk);
	init_tab(&tab_list);
	if (argc < 2)
		exit (0);
	if (check_integer(argv, argc, &tab_list) != 1)
	{
		ft_printf("Error\n");
		exit(0);
	}
	if (check_doublon(&tab_list) == 0)
	{
		ft_printf("Error\n");
		exit (0);
	}
	simplification(&tab_list, tab_list.max_index);
	chunk_setup(allowed_size, &chunk);
	if (allowed_size == 3)
		small_sort(&tab_list, 0);
	else if (allowed_size == 5)
		sort_5_num(&tab_list);
	else
		sort(&tab_list, &chunk);
	exit (0);
}
