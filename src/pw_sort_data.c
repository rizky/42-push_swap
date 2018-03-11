/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pw_sort_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 13:32:45 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/11 18:04:34 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	pw_rank(t_array *v, t_array *dv)
{
	int	i;
	int j;

	i = (int)v->size - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < (int)dv->size - 1)
		{
			if (ARRAY_DATA(v, i) == ARRAY_DATA(dv, (int)dv->size - 1 - j) &&
				ARRAY_DATA(dv, (int)dv->size - 1 - j) != 999999)
			{
				ARRAY_DATA(dv, (int)dv->size - 1 - j) = 999999;
				break ;
			}
			j++;
		}
		ARRAY_DATA(v, i) = j + 1;
		i--;
	}
	fta_clear(dv);
	*dv = NEW_ARRAY(int);
}

static int
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
	return (left);
}

void
	pw_sortdata(t_array *v, int left, int right)
{
	int pivot;
	int index;

	if (left >= right)
		return ;
	pivot = ARRAY_DATA(v, (right + left) / 2);
	index = pw_partition_array(v, left, right, pivot);
	pw_sortdata(v, left, index - 1);
	pw_sortdata(v, index, right);
}

int
	pw_is_sorted(t_array *v)
{
	int	i;

	if (v->size == 0)
		return (1);
	i = v->size - 1;
	while (i > 0)
	{
		if (ARRAY_DATA(v, i - 1) < ARRAY_DATA(v, i))
			return (0);
		i--;
	}
	return (1);
}
