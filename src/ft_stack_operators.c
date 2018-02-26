/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_operators.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 21:46:44 by rnugroho          #+#    #+#             */
/*   Updated: 2018/02/26 21:49:02 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	pf_swap(t_array *d)
{
	int temp;

	if (d->size < 2)
		return ;
	temp = ((int*)ARRAY_START(d))[d->size-2];
	((int*)ARRAY_START(d))[d->size-2] = ((int*)ARRAY_START(d))[d->size-1];
	((int*)ARRAY_START(d))[d->size-1] = temp;
}

void
	pf_push(t_array *source, t_array *dest)
{
	int temp;

	if (source->size == 0)
		return ;
	temp = ((int*)ARRAY_START(source))[source->size-1];
	fta_popback(source, 1);
	fta_append(dest, &temp, 1);
}

void
	pf_rotate(t_array *d)
{
	int temp;

	if (d->size == 0)
		return ;
	temp = ((int*)ARRAY_START(d))[0];
	fta_popindex(d, 0, 1);
	fta_append(d, &temp, 1);
}

void
	pf_rev_rotate(t_array *d)
{
	int temp;

	if (d->size == 0)
		return ;
	temp = ((int*)ARRAY_START(d))[d->size-1];
	fta_popback(d, 1);
	fta_insert(d, &temp, 1, 0);
}

int
	pf_is_sorted(t_array *d)
{
	int	i;

	if (d->size == 0)
		return (1);
	i = d->size - 1;
	while (i > 0)
	{
		if (((int*)ARRAY_START(d))[i - 1] < ((int*)ARRAY_START(d))[i])
			return (0);
		i--;
	}
	return (1);
}