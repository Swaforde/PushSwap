#include "push_swap.h"

void parsing(int value, t_tab *tabList)
{
    static int index;
    tabList->tabA[index] = value;
    index ++;
}

int	word_count(char const *str, char c)
{
	int	word_count;
	int	i;

	word_count = 0;
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == 0))
			word_count++;
		i++;
	}
	return (word_count);
}

int big_parsing(t_tab *tabList, char *string)
{
	char **tab_tmp;
	int i;
	int t;

	tab_tmp = ft_split(string, 32);
	i = 0;
	t = 0;

	while (tab_tmp[i] != NULL)
	{
        if (tab_tmp[i][0] == '-' || ft_isdigit((int)tab_tmp[i][0]) == 1)
			t = 1;
		else
			return (0);
		while (tab_tmp[i][t] != '\0')
		{
			if (ft_isdigit((int)tab_tmp[i][t]) == 0)
				return (0);
			t ++;
		}
		i ++;
	}

	i = 0;
	while (i < word_count(string, 32))
	{
		tabList->tabA[i] = ft_atoi(tab_tmp[i]);
		i ++;
	}
	return (1);
}