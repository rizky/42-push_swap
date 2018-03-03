/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pw_operators_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 13:58:58 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/03 13:59:10 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	pw_split(t_array *a, t_array *b)
{
	int avg;
	int	i;

	avg = pw_get_avg(a);
	i = a->size - 1;
	while (i >= 0)
	{
		if (avg >= ARRAY_DATA(a, a->size - 1))
		{
			pw_push(a, b);
			ft_printfln("pb");
		}
		else
		{
			pw_rev_rotate(a);
			ft_printfln("rra");
		}
		i--;
	}
}
