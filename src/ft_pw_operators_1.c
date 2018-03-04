/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pw_operators_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 21:46:44 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/04 22:20:40 by rnugroho         ###   ########.fr       */
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

	sp = 3;
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

void
	pw_print_stripe(t_array *a, t_array *b)
{
	int i;
	int	maxa;
	int	maxb;

	maxa = pw_get_max(a);
	maxb = pw_get_max(b);
	if (a->size > b->size)
		i = a->size - 1;
	else
		i = b->size - 1;
	usleep(120000);
	system("clear");
	i = a->size + b->size + 1;
	while (i >= 0)
	{
		if (i < (int)a->size)
			ft_printf("%3d %*Q%*Q\t", ((int*)ARRAY_START(a))[i],((int*)ARRAY_START(a))[i], '-', maxa - ((int*)ARRAY_START(a))[i], ' ');
		else
			ft_printf("%*Q\t", maxa + 4, ' ');
		if (i < (int)b->size)
			ft_printfln("%3d %*Q%*Q", ((int*)ARRAY_START(b))[i], ((int*)ARRAY_START(b))[i], '-', maxb - ((int*)ARRAY_START(b))[i], ' ');
		else
			ft_printf("\n");
		i--;
	}
	ft_printfln("%*Q\t%*Q", maxa + 4, '+', maxb + 4, '+');
	ft_printfln("%*s%*Q\t%*s", (maxa + 4) / 2 + 1, "a",
				(maxa + 4) - ((maxa + 4) / 2 + 1), ' ' , (maxb + 4) / 2 + 1, "b");
}
