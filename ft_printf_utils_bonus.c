/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:42:13 by corellan          #+#    #+#             */
/*   Updated: 2024/04/02 11:46:30 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	calculate_length(int base, size_t number)
{
	size_t	result;

	result = 1;
	if (number == 0)
		return (result);
	while ((number / base) > 0)
	{
		number /= base;
		result++;
	}
	return (result);
}

size_t	length_number(const char c, va_list *ar, int base)
{
	va_list	copy;
	size_t	number;
	long	original;

	va_copy(copy, *ar);
	original = 0;
	number = 0;
	if (c == 'x' || c == 'X' || c == 'u')
		number = va_arg(copy, unsigned int);
	else if (c == 'd' || c == 'i')
	{
		original = va_arg(copy, int);
		if (original < 0)
			number = (size_t)(original * -1);
		else
			number = (size_t)original;
	}
	else
		number = va_arg(copy, unsigned long);
	va_end(copy);
	return (calculate_length(base, number));
}
