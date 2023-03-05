/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:03 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:43:06 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing(int value, t_tab *tabList)
{
	static int	index;

	tabList->tab_a[index] = value;
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

int	big_parsing(t_tab *tabList, char *string, int i, int t)
{
	char	**tab_tmp;

	tab_tmp = ft_split(string, 32);
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
		if (check_int(tab_tmp[i]) == 0)
			return (0);
		i ++;
	}
	parsing_util(string, tabList, tab_tmp);
	return (1);
}
