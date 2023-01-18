#include "push_swap.h"

int check_integer(char **argv, int total)
{
    int i;
    int t;

    i = 1;
    t = 0;
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
		t = 0;
		i ++;
    }
    return (1);
}