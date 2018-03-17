/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:35:43 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/17 16:10:40 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# define ARRAY_DATA(D, I) ((int*)(D)->data)[I]
# define OPT_V 0
# define OPT_C 1
# define OPT_A 2
# define OPT_T 3

void		pw_swap(t_array *d, t_array *dv, char *instr);
void		pw_push(t_array *source, t_array *dest, char *instr);
void		pw_rotate(t_array *d, t_array *dv, char *instr);
void		pw_rev_rotate(t_array *d, t_array *dv, char *instr);
void		pw_rev_rotate_r(t_array *d, t_array *dv, char *instr);
void		pw_smart_rotate(t_array *a, t_array *b);

void		ch_swap(t_array *d, t_array *dv);
void		ch_push(t_array *source, t_array *dest);
void		ch_rotate(t_array *d, t_array *dv);
void		ch_rev_rotate(t_array *d, t_array *dv);

void		ft_push_swap_simple(t_array *a, t_array *b);
void		ft_push_swap_backtrack(t_array *a, t_array *b);
void		ft_push_swap_segment(t_array *a, t_array *b);

void		ft_push_swap(t_array *a, t_array *b);
void		pw_backtrack_split(t_array *a, t_array *b, int limit);
void		pw_backtrack(t_array *a, t_array *b, int limit);
void		pw_split_to_b(t_array *a, t_array *b, int avg, int size);
void		pw_split_to_a(t_array *a, t_array *b, int avg, int size);
void		pw_print_stack(t_array *a, t_array *b, t_array *opt);

int			pw_get_arg(t_array *a, int i, int ac, char **av);
void		ft_push_swap(t_array *a, t_array *b);

int			pw_get_min(t_array *d);
int			pw_get_max(t_array *d);
int			pw_get_avg(t_array *d);
int			pw_is_sorted(t_array *d);
int			pw_getoptions(char **av, t_array *opt);
void		pw_merge(t_array *a, t_array *b);

int			pw_get_size(t_array *d, int limit);
int			pw_get_avg_limit(t_array *d, int limit);

void		pw_rank(t_array *v, t_array *dv);
void		pw_sortdata(t_array *v, int left, int right);
#endif
