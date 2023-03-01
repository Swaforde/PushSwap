#include "push_swap.h"

int	check_integer(char **argv, int total, t_tab *tabList)
{
	int	i;
	int	t;

	i = 1;
	t = 0;
	if (total == 2)
	{
		if (big_parsing(tabList, argv[1]) == 1)
			return (1);
		return (0);
	}
	while (i < total)
	{
		if (argv[i][0] == '-' || ft_isdigit((int)argv[i][0]) == 1)
			t = 1;
		else
			return (0);
		while (argv[i][t] != '\0')
		{
			if (ft_isdigit((int)argv[i][t]) == 0)
				return (0);
			t ++;
		}
		parsing(ft_atoi(argv[i]), tabList);
		t = 0;
		i ++;
	}
	return (1);
}

int	get_max_index(char **argv, t_tab *tabList, int argc)
{
	int	i;

	i = 0;
	if (argc == 2)
		i = word_count(argv[1], 32);
	else
		i = argc - 1;
	return (i);
}
