/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:35:43 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/07 01:35:51 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# define ARRAY_DATA(D, I) ((int*)ARRAY_START(D))[I]
# define ARRAY_DATA_DOT(D, I) ((int*)((D).data))[I]

void		pw_swap(t_array *d, t_array *dv);
void		pw_push(t_array *source, t_array *dest);
void		pw_rotate(t_array *d, t_array *dv);
void		pw_rev_rotate(t_array *d, t_array *dv);
int			pw_is_sorted(t_array *d);

void		pw_print_stack(t_array *a, t_array *b);

void		ft_push_swap(t_array *a, t_array *b);

int			pw_get_min(t_array *d);
int			pw_get_max(t_array *d);
int			pw_get_avg(t_array *d, int size);
int			pw_getoptions(char **av, int *g_isverbose);
void		pw_rank(t_array *v, t_array *dv);
void		pw_sortdata_quick(t_array *v);
#endif
