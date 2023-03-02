/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:50:02 by tbouvera          #+#    #+#             */
/*   Updated: 2023/02/27 13:33:55 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./Libft/libft.h"

enum e_spec
{
    empty = 4444444444
};

typedef struct s_tabl
{
    long int *tabA;
    long int *tabB;
    int max_index;
}   t_tab;

typedef struct s_chunk
{
	int index_1;
	int index_2;
	int total;
	int step;
} t_chunk;

int     check_integer(char **argv, int total, t_tab *tabList);
void    print_tab(long int *tab, int max);
void    clear_tab(long int *tab, int max);
int     count_element(long int *tab, t_tab *tabList);
void    parsing(int value, t_tab *tabList);
void	rotate_b(t_tab *tabList);
void	rotate_a(t_tab *tabList);
void    swap_a(t_tab *tabList);
void    swap_b(t_tab *tabList);
void    swap_s(t_tab *tabList);
int     push_a(t_tab *tabList);
int     push_b(t_tab *tabList);
void	rotate_reverse_b(t_tab *tabList);
void	rotate_reverse_a(t_tab *tabList);
void	simplification(t_tab *tabList, int size);
void	forced_reverse_b(t_tab *tabList);
void	forced_reverse_a(t_tab *tabList);
void	forced_rotate_b(t_tab *tabList);
void	forced_rotate_a(t_tab *tabList);
void	rotate_ab(t_tab *tabList);
void	rotate_reverse_ab(t_tab *tabList);
int		find_same_number(long int *tab, int num, t_tab *tabList);
void sort(t_tab *tabList, t_chunk *chunk);
int		check_empty_tab(long int *tab, t_tab *tabList);
int big_parsing(t_tab *tabList, char *string);
int	word_count(char const *str, char c);
int get_max_index (char **argv, t_tab *tabList, int argc);
void chunk_setup(int total_element, t_chunk *chunk);
int find_smaller_num(t_tab *tabList);
void	small_sort(t_tab *tab_list, int low);
int	get_index_of_element(int num, t_tab *tab_list);
int	check_doublon(t_tab *tab_list);
int	check_int(t_tab *tab_list);
void	sort_5_num(t_tab *tab_list);

#endif