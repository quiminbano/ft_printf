/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:42:13 by corellan          #+#    #+#             */
/*   Updated: 2024/03/27 23:42:50 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	calculate_length(int base, size_t result, size_t number)
{
	result += 1;
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
	size_t	result;
	size_t	number;
	long	original;

	va_copy(copy, *ar);
	original = 0;
	result = 0;
	if (c == 'x' || c == 'X' || c == 'u')
		number = va_arg(copy, unsigned int);
	else if (c == 'd')
	{
		original = va_arg(copy, int);
		if (original < 0)
		{
			result = 1;
			number = (size_t)(original * -1);
		}
	}
	else
		number = va_arg(copy, unsigned long);
	va_end(copy);
	return (calculate_length(base, result, number));
}
