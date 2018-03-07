/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pw_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 13:32:45 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/07 02:38:04 by rnugroho         ###   ########.fr       */
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
	return left;
}

void
	pw_sortdata_quick(t_array *v, int left, int right)
{
	int pivot;
	int index;

	if (left >= right)
		return ;
	pivot = ARRAY_DATA(v, (right + left) / 2);
	index = pw_partition_array(v, left, right, pivot);
	pw_sortdata_quick(v, left, index - 1);
	pw_sortdata_quick(v, index, right);
}
