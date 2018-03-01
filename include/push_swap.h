/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:35:43 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/01 16:04:32 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

void		pw_swap(t_array *d);
void		pw_push(t_array *source, t_array *dest);
void		pw_rotate(t_array *d);
void		pw_rev_rotate(t_array *d);
int			pw_is_sorted(t_array *d);
void		pw_print_stack(t_array *a, t_array *b);
#endif
