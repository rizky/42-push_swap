/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pw_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 13:32:45 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/03 22:28:13 by rnugroho         ###   ########.fr       */
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

void
	pw_rank(t_array *v, t_array *dv)
{
	int	i;
	int j;

	i = 0;
	while (i < (int)v->size)
	{
		j = 0;
		while (j < (int)dv->size)
		{
			if (ARRAY_DATA(v, i) == ARRAY_DATA(dv, j) &&
				ARRAY_DATA(dv, j) != 999999)
			{
				ARRAY_DATA(dv, j) = 999999;
				break ;
			}
			j++;
		}
		ARRAY_DATA(v, i) = j;
		i++;
	}
}

void
	pw_sortdata_bubble(t_array *dv)
{
	int	temp;
	int	i;
	int j;

	i = 0;
	while (i < (int)dv->size - 1)
	{
		j = i + 1;
		while (j < (int)dv->size)
		{
			if (ARRAY_DATA(dv, i) > ARRAY_DATA(dv, j))
				{
					temp  = ARRAY_DATA(dv, j);
					ARRAY_DATA(dv, j) = ARRAY_DATA(dv, i);
					ARRAY_DATA(dv, i) = temp;
				}
			j++;
		}
		i++;
	}
}


int
	pw_partition_array(t_array *v, int left, int right, int pivot)
{
	int temp;

	while (left <= right)
	{
		while (ARRAY_DATA(v, left) > pivot)
			left++;
		while (ARRAY_DATA(v, right) < pivot)
			right--;
		if (left <= right)
		{
			temp = ARRAY_DATA(v, right);
			ARRAY_DATA(v, right) = ARRAY_DATA(v, left);
			ARRAY_DATA(v, left) = temp;
			left++;
			right--;
		}
	}
	return left;
}

void
	pw_quicksort_array(t_array *v, int left, int right)
{
	int pivot;
	int index;

	if (left >= right)
		return ;
	pivot = ARRAY_DATA(v, (right + left) / 2);
	index = pw_partition_array(v, left, right, pivot);
	pw_quicksort_array(v, left, index - 1);
	pw_quicksort_array(v, index, right);
}

void
	pw_sortdata_quick(t_array *v)
{
	pw_quicksort_array(v, 0, (int)v->size - 1);
}
