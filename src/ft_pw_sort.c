/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pw_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 13:32:45 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/03 13:32:54 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	pw_bubblesort(t_array *v)
{
	int	i;

	if (v->size == 0)
		return ;
	i = v->size - 1;
	while (i > 0)
	{
		if (ARRAY_DATA(v, 1) == pw_get_max(v) &&
			ARRAY_DATA(v, 0) == pw_get_min(v))
			{
				ft_printfln("ra");
				pw_rotate(v);
			}
		if (ARRAY_DATA(v, i - 1) < ARRAY_DATA(v, i))
		{
			if (i > (int)v->size / 2)
			{
				while (i < (int)v->size - 1)
				{
					ft_printfln("rra");
					pw_rev_rotate(v);
					i++;
				}
			}
			else
			{
				while (i > 0)
				{
					ft_printfln("ra");
					pw_rotate(v);
					i--;
				}
			}
			ft_printfln("sa");
			pw_swap(v);
			while (ARRAY_DATA(v, 0) > ARRAY_DATA(v, v->size - 1))
			{
				if (ARRAY_DATA(v, v->size - 1) == pw_get_min(v) &&
					ARRAY_DATA(v, 0) == pw_get_max(v))
					break ;
				ft_printfln("ra");
				pw_rotate(v);
				ft_printfln("sa");
				pw_swap(v);
			}
			i = v->size - 1;
		}
		else
			i--;
	}
}

void
	pw_bubblesort_desc(t_array *v)
{
	int	i;

	if (v->size == 0)
		return ;
	i = v->size - 1;
	while (i > 0)
	{
		if (ARRAY_DATA(v, 1) == pw_get_min(v) &&
			ARRAY_DATA(v, 0) == pw_get_max(v))
			{
				ft_printfln("rb");
				pw_rotate(v);
			}
		if (ARRAY_DATA(v, i - 1) > ARRAY_DATA(v, i))
		{
			if (i > (int)v->size / 2)
			{
				while (i < (int)v->size - 1)
				{
					ft_printfln("rrb");
					pw_rev_rotate(v);
					i++;
				}
			}
			else
			{
				while (i > 0)
				{
					ft_printfln("rb");
					pw_rotate(v);
					i--;
				}
			}
			ft_printfln("sb");
			pw_swap(v);
			while (ARRAY_DATA(v, 0) < ARRAY_DATA(v, v->size - 1))
			{
				if (ARRAY_DATA(v, v->size - 1) == pw_get_max(v) &&
					ARRAY_DATA(v, 0) == pw_get_min(v))
					break ;
				ft_printfln("rb");
				pw_rotate(v);
				ft_printfln("sb");
				pw_swap(v);
			}
			i = v->size - 1;
		}
		else
			i--;
	}
}
