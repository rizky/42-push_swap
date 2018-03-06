/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pw_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 13:58:58 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/06 01:30:04 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	pw_print_stack(t_array *a, t_array *b)
{
	int i;
	int max;
	static int counter=0;

	if (a->size > b->size)
		i = a->size - 1;
	else
		i = b->size - 1;
	max = (pw_get_max(a) > pw_get_max(b)
		? pw_get_max(a) : pw_get_max(b));
	usleep(30000);
	system("clear");
	ft_printfln("Counter: %d", ++counter);
	i = a->size + b->size + 1;
	while (i >= 0)
	{
		if (i < (int)a->size)
			ft_printf("%3d %*Q%*Q\t", ((int*)ARRAY_START(a))[i],((int*)ARRAY_START(a))[i], '-', max - ((int*)ARRAY_START(a))[i], ' ');
		else
			ft_printf("%*Q\t", max + 4, ' ');
		if (i < (int)b->size)
			ft_printfln("%3d %*Q%*Q", ((int*)ARRAY_START(b))[i], ((int*)ARRAY_START(b))[i], '-', max - ((int*)ARRAY_START(b))[i], ' ');
		else
			ft_printf("\n");
		i--;
	}
	ft_printfln("%*Q\t%*Q", max + 4, '+', max + 4, '+');
	ft_printfln("%*s%*Q\t%*s", (max + 4) / 2 + 1, "a",
				(max + 4) - ((max + 4) / 2 + 1), ' ' , (max + 4) / 2 + 1, "b");
}
