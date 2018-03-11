/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_operators.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 21:46:44 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/11 18:27:54 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ch_swap(t_array *d, t_array *dv)
{
	int temp;

	(void)dv;
	if (d->size < 2)
		return ;
	temp = ARRAY_DATA(d, d->size - 2);
	ARRAY_DATA(d, d->size - 2) = ARRAY_DATA(d, d->size - 1);
	ARRAY_DATA(d, d->size - 1) = temp;
}

void
	ch_push(t_array *dest, t_array *source)
{
	int temp;

	if (source->size == 0)
		return ;
	temp = ARRAY_DATA(source, source->size - 1);
	fta_popback(source, 1);
	fta_append(dest, &temp, 1);
}

void
	ch_rev_rotate(t_array *d, t_array *dv)
{
	int temp;

	(void)dv;
	if (d->size == 0)
		return ;
	temp = ARRAY_DATA(d, 0);
	fta_append(d, &temp, 1);
	fta_popindex(d, 0, 1);
}

void
	ch_rotate(t_array *d, t_array *dv)
{
	int temp;

	(void)dv;
	if (d->size == 0)
		return ;
	temp = ARRAY_DATA(d, d->size - 1);
	fta_popback(d, 1);
	fta_insert(d, &temp, 1, 0);
}
