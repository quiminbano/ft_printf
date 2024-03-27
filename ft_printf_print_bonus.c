/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:30:19 by corellan          #+#    #+#             */
/*   Updated: 2024/03/28 00:14:26 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_number(unsigned long number, t_base base, t_printf *data)
{
	int				write_status;
	unsigned long	base_num;
	const char		*lower_base = "0123456789abcdef";
	const char		*upper_base = "0123456789ABCDEF";

	if (base == NORMAL)
		base_num = 10;
	else
		base_num = 16;
	if (number >= base_num)
	{
		if (print_number((number / base_num), base, data) == -1)
			return (-1);
		if (print_number((number % base_num), base, data) == -1)
			return (-1);
	}
	else if (base == UPPER)
		write_status = char_return(upper_base[number], data);
	else
		write_status = char_return(lower_base[number], data);
	if (write_status == -1)
		return (-1);
	return (0);
}

int	print_unsigned(unsigned long number, t_base base, t_printf *data)
{
	int	write_status;

	if (data->conversion == 'p')
	{
		data->flags.has_sharp = 1;
		data->flags.type_sharp = LOWER;
	}
	if (print_identation(data, data->size_number, BEFORE) == -1)
		return (-1);
	write_status = print_number(number, base, data);
	if (write_status == -1)
		return (-1);
	if (print_identation(data, data->size_number, AFTER) == -1)
		return (-1);
	return (0);
}

int	nbr_return(long long number, t_base base, t_printf *data)
{
	int	write_status;

	if (data->flags.has_plus)
		data->size_number += 1;
	if (print_identation(data, data->size_number, BEFORE) == -1)
		return (-1);
	if (number < 0)
	{
		write_status = char_return('-', data);
		if (write_status == -1)
			return (-1);
		number *= -1;
	}
	if (print_number(number, base, data) == -1)
		return (-1);
	if (print_identation(data, data->size_number, AFTER) == -1)
		return (-1);
	return (0);
}

int	char_return(char c, t_printf *data)
{
	int	write_status;

	if (print_identation(data, 1, BEFORE) == -1)
		return (-1);
	write_status = write(data->fd, &c, 1);
	if (write_status == -1)
		return (-1);
	data->count += 1;
	if (print_identation(data, 1, AFTER) == -1)
		return (-1);
	return (0);
}

int	str_return(char *str, t_printf *data)
{
	int		write_status;
	size_t	size_string;

	if (str == NULL)
		size_string = 6;
	else
		size_string = ft_strlen(str);
	if (data->flags.has_dot && data->flags.size_string < size_string)
		size_string = data->flags.size_string;
	if (print_identation(data, size_string, BEFORE) == -1)
		return (-1);
	if (str == NULL)
		write_status = write(data->fd, "(null)", size_string);
	else
		write_status = write(data->fd, str, size_string);
	data->count += (int)size_string;
	if (write_status == -1)
		return (-1);
	if (print_identation(data, size_string, AFTER) == -1)
		return (-1);
	return (0);
}
