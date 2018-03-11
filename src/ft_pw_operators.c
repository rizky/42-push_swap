/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pw_operators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 21:46:44 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/11 05:28:12 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	pw_swap(t_array *d, t_array *dv, char *instr)
{
	int temp;

	(void)dv;
	if (d->size < 2)
		return ;
	temp = ARRAY_DATA(d, d->size - 2);
	ARRAY_DATA(d, d->size - 2) = ARRAY_DATA(d, d->size - 1);
	ARRAY_DATA(d, d->size - 1) = temp;
	ft_printfln("%s", instr);
}

void
	pw_push(t_array *dest, t_array *source, char *instr)
{
	int temp;

	if (source->size == 0)
		return ;
	temp = ARRAY_DATA(source, source->size - 1);
	fta_popback(source, 1);
	fta_append(dest, &temp, 1);
	ft_printfln("%s", instr);
}

void
	pw_rev_rotate(t_array *d, t_array *dv, char *instr)
{
	int temp;

	(void)dv;
	if (d->size == 0)
		return ;
	temp = ARRAY_DATA(d, 0);
	fta_append(d, &temp, 1);
	fta_popindex(d, 0, 1);
	ft_printfln("%s", instr);
}

void
	pw_rotate(t_array *d, t_array *dv, char *instr)
{
	int temp;

	(void)dv;
	if (d->size == 0)
		return ;
	temp = ARRAY_DATA(d, d->size - 1);
	fta_popback(d, 1);
	fta_insert(d, &temp, 1, 0);
	ft_printfln("%s", instr);
}

void
	pw_rev_rotate_r(t_array *d, t_array *dv, char *instr)
{
	int temp;

	if (d->size == 0)
		return ;
	temp = ARRAY_DATA(d, 0);
	fta_append(d, &temp, 1);
	fta_popindex(d, 0, 1);
	if (dv->size == 0)
		return ;
	temp = ARRAY_DATA(dv, 0);
	fta_append(dv, &temp, 1);
	fta_popindex(dv, 0, 1);
	ft_printfln("%s", instr);
}
