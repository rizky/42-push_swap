/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pw_operators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 21:46:44 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/02 16:37:22 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	pw_swap(t_array *d)
{
	int temp;

	if (d->size < 2)
		return ;
	temp = ((int*)ARRAY_START(d))[d->size-2];
	((int*)ARRAY_START(d))[d->size-2] = ((int*)ARRAY_START(d))[d->size-1];
	((int*)ARRAY_START(d))[d->size-1] = temp;
}

void
	pw_push(t_array *source, t_array *dest)
{
	int temp;

	if (source->size == 0)
		return ;
	temp = ((int*)ARRAY_START(source))[source->size-1];
	fta_popback(source, 1);
	fta_append(dest, &temp, 1);
}

void
	pw_rotate(t_array *d)
{
	int temp;

	if (d->size == 0)
		return ;
	temp = ((int*)ARRAY_START(d))[0];
	fta_popindex(d, 0, 1);
	fta_append(d, &temp, 1);
}

void
	pw_rev_rotate(t_array *d)
{
	int temp;

	if (d->size == 0)
		return ;
	temp = ((int*)ARRAY_START(d))[d->size-1];
	fta_popback(d, 1);
	fta_insert(d, &temp, 1, 0);
}

void
	pw_print_stack(t_array *a, t_array *b)
{
	int i;

	if (a->size > b->size)
		i = a->size - 1;
	else
		i = b->size - 1;
	while (i >= 0)
	{
		if (i < (int)a->size)
			ft_printf("%2d  ", ((int*)ARRAY_START(a))[i]);
		else
			ft_printf("    ");
		if (i < (int)b->size)
			ft_printfln("%2d ", ((int*)ARRAY_START(b))[i]);
		else
			ft_printf("\n");
		i--;
	}
	ft_printfln("--- ---");
	ft_printfln("%2s  %2s", "a", "b");
	ft_printfln("--------------------------------------------------");
}
