/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:35:43 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/10 20:45:43 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# define ARRAY_DATA(D, I) ((int*)ARRAY_START(D))[I]

void		pw_swap(t_array *d, t_array *dv);
void		pw_push(t_array *source, t_array *dest);
void		pw_rotate(t_array *d, t_array *dv);
void		pw_rev_rotate(t_array *d, t_array *dv);

void		ft_push_swap_simple(t_array *a, t_array *b, int isverbose, int iscolor);
void		ft_push_swap_backtrack(t_array *a, t_array *b, int isverbose, int iscolor);

void		pw_print_stack(t_array *a, t_array *b, int iscolor);

int			pw_get_arg(t_array *a, int i, int ac, char **av);
void		ft_push_swap(t_array *a, t_array *b);

int			pw_get_min(t_array *d);
int			pw_get_max(t_array *d);
int			pw_get_avg(t_array *d);
int			pw_is_sorted(t_array *d);
int			pw_getoptions(char **av, int *isverbose, int *iscolor);

int			pw_get_size(t_array *d, int limit);
int			pw_get_avg_limit(t_array *d, int limit);

void		pw_rank(t_array *v, t_array *dv);
void		pw_sortdata(t_array *v, int left, int right);
#endif
