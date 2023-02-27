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

void big_parsing(t_tab *tabList, char *string)
{
	char **tab_tmp;
	int i;

	tab_tmp = ft_split(string, 32);
	i = 0;

	ft_printf("\n%d\n", word_count(string, 32));

	while (i < word_count(string, 32))
	{
		tabList->tabA[i] = ft_atoi(tab_tmp[i]);
		i ++;
	}
}