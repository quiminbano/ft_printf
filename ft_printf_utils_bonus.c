/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:42:13 by corellan          #+#    #+#             */
/*   Updated: 2024/03/27 19:22:54 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	print_sharp(t_printf *data, t_when when)
{
	int	write_status;

	write_status = 0;
	if (when == BEFORE && data->flags.has_sharp && \
		data->flags.type_sharp == UPPER)
	{
		write_status = write(data->fd, "0X", 2);
		data->count += 2;
	}
	else if (when == BEFORE && data->flags.has_sharp && \
		data->flags.type_sharp == LOWER)
	{
		write_status = write(data->fd, "0x", 2);
		data->count += 2;
	}
	if (write_status == -1)
		return (-1);
	return (0);
}

static int	sp_zero(t_printf *data, size_t size_parameter, t_when when, char c)
{
	int		write_status;
	size_t	iter;

	write_status = 0;
	iter = 0;
	while (data->flags.has_pure_number && when == BEFORE && \
		iter < size_parameter)
	{
		write_status = write(data->fd, &c, 1);
		if (write_status == -1)
			return (-1);
		iter++;
		(data->count)++;
	}
	while (data->flags.has_minus && when == AFTER && \
		iter < size_parameter)
	{
		write_status = write(data->fd, &c, 1);
		if (write_status == -1)
			return (-1);
		iter++;
		(data->count)++;
	}
	return (0);
}

int	print_identation(t_printf *data, size_t size_parameter, t_when when)
{
	size_t	total_size;
	char	c;

	total_size = data->flags.size_print;
	if (print_sharp(data, when) == -1)
		return (-1);
	if (size_parameter > total_size || total_size == 0)
		return (0);
	total_size -= size_parameter;
	if (data->flags.has_zero && data->flags.has_pure_number)
		c = '0';
	else
		c = ' ';
	if (sp_zero(data, size_parameter, when, c) == -1)
		return (-1);
	return (0);
}

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
