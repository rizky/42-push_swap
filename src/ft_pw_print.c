/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pw_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 13:58:58 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/07 01:47:04 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	pw_print_color(t_array *v, int i)
{
	if (ARRAY_DATA(v, i) == ARRAY_DATA(v, i + 1) + 1 ||
		ARRAY_DATA(v, i) == ARRAY_DATA(v, i - 1) - 1||
		ARRAY_DATA(v, i) == ARRAY_DATA(v, i + 1) ||
		ARRAY_DATA(v, i) == ARRAY_DATA(v, i - 1))
		return (GREEN);
	else
		return (EOC);
}

void
	pw_print_stack(t_array *a, t_array *b)
{
	int			i;
	int			max;
	static int	counter = 0;

	max = (pw_get_max(a) > pw_get_max(b) ? pw_get_max(a) : pw_get_max(b));
	usleep(20000);
	system("clear");
	ft_printfln("Counter: %d", ++counter);
	i = a->size + b->size + 1;
	while (i >= 0)
	{
		if (i < (int)a->size)
			ft_printf("%*w%3d %*Q%*Q%w\t", pw_print_color(a, i), ARRAY_DATA(a, i),
			ARRAY_DATA(a, i), '-', max - ARRAY_DATA(a, i), ' ');
		else
			ft_printf("%*Q\t", max + 4, ' ');
		if (i < (int)b->size)
			ft_printfln("%*w%3d %*Q%*Q%w", pw_print_color(b, i), ARRAY_DATA(b, i),
			ARRAY_DATA(b, i), '-', max - ARRAY_DATA(b, i), ' ');
		else
			ft_printf("\n");
		i--;
	}
}
