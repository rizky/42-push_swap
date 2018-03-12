/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 18:49:14 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/12 01:52:56 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_push_swap_backtrack(t_array *a, t_array *b)
{
	if (pw_is_sorted(a))
		return ;
	pw_split_to_b(a, b, pw_get_avg(a), a->size);
	ft_push_swap(a, b);
	if (pw_get_size(a, pw_get_max(a)) >= 20)
	{
		pw_backtrack_split(a, b, pw_get_max(a));
		pw_backtrack_split(a, b, pw_get_max(a));
	}
	pw_backtrack(a, b, pw_get_max(a));
}

int
	main(int ac, char **av)
{
	int			i;
	t_array		a;
	t_array		b;

	a = NEW_ARRAY(int);
	b = NEW_ARRAY(int);
	if (ac > 1)
	{
		i = 1;
		if (pw_get_arg(&a, i, ac, av) == -1)
		{
			fta_clear(&a);
			return (0);
		}
		pw_get_arg(&b, i, ac, av);
		pw_sortdata(&b, 0, b.size - 1);
		pw_rank(&a, &b);
		if (a.size <= 5)
			ft_push_swap_simple(&a, &b);
		else
			ft_push_swap_backtrack(&a, &b);
		fta_clear(&a);
		fta_clear(&b);
	}
	return (0);
}
