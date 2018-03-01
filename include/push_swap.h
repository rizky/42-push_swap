/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:35:43 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/01 15:49:08 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

void		pf_swap(t_array *d);
void		pf_push(t_array *source, t_array *dest);
void		pf_rotate(t_array *d);
void		pf_rev_rotate(t_array *d);
int			pf_is_sorted(t_array *d);
void		pf_print_stack(t_array *a, t_array *b);
#endif
