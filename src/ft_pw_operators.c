/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pw_operators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 21:46:44 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/03 13:49:35 by rnugroho         ###   ########.fr       */
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
	int	sp;

	sp = 5;
	if (a->size > b->size)
		i = a->size - 1;
	else
		i = b->size - 1;
	while (i >= 0)
	{
		if (i < (int)a->size)
			ft_printf("%*d ", sp, ((int*)ARRAY_START(a))[i]);
		else
			ft_printf("%*Q ", sp, ' ');
		if (i < (int)b->size)
			ft_printfln("%*d ", sp, ((int*)ARRAY_START(b))[i]);
		else
			ft_printf("\n");
		i--;
	}
	ft_printfln("%*Q %*Q", sp, '-', sp, '-');
	ft_printfln("%*s%*Q %*s", sp / 2 + 1, "a",
				sp - (sp / 2 + 1), ' ' , sp / 2 + 1, "b");
	ft_printfln("%50Q",'-');
}
