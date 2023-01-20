/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:50:02 by tbouvera          #+#    #+#             */
/*   Updated: 2023/01/05 11:55:04 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./Libft/libft.h"

enum e_spec
{
    empty = 4444444444
};

typedef struct s_tab
{
    long int *tabA;
    long int *tabB;
    int max_index;
}   t_tab;

int     check_integer(char **argv, int total, t_tab *tabList);
int     count_element(long int *tab, t_tab *tabList);
void    parsing(int value, t_tab *tabList);
void    swap_a(t_tab *tabList);
void    swap_b(t_tab *tabList);
void    swap_s(t_tab *tabList);

#endif