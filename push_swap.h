/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:50:02 by tbouvera          #+#    #+#             */
/*   Updated: 2023/01/30 12:08:24 by tbouvera         ###   ########.fr       */
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

void	rotate_ab(t_tab *tabList);
void	rotate_reverse_ab(t_tab *tabList);
#endif