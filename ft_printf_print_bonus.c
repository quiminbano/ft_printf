/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:30:19 by corellan          #+#    #+#             */
/*   Updated: 2024/03/31 19:55:42 by corellan         ###   ########.fr       */
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
		write_status = print_number((number / base_num), base, data);
		if (write_status == -1)
			return (-1);
		write_status = print_number((number % base_num), base, data);
		if (write_status == -1)
			return (-1);
	}
	else if (base == UPPER)
		write_status = char_return(upper_base[number], data, NUMBER);
	else
		write_status = char_return(lower_base[number], data, NUMBER);
	if (write_status == -1)
		return (-1);
	return (0);
}

int	print_unsigned(unsigned long number, t_base base, t_printf *data)
{
	size_t	backup;

	backup = data->size_number;
	if (data->flags.conv == 'p')
	{
		data->flags.has_sharp = 1;
		data->flags.type_sharp = LOWER;
	}
	if (data->flags.has_sharp && data->flags.conv != 'p' && number == 0)
		data->flags.has_sharp = 0;
	if (data->flags.size_dot >= data->size_number)
		data->size_number = data->flags.size_dot;
	if (special_case(data) && !number)
		data->size_number = 0;
	if (print_identation(data, data->size_number, BEFORE) == -1)
		return (-1);
	if ((data->size_number >= backup) && \
		print_zeros((data->size_number - backup), data) == -1)
		return (-1);
	if (data->size_number && print_number(number, base, data) == -1)
		return (-1);
	if (print_identation(data, data->size_number, AFTER) == -1)
		return (-1);
	return (0);
}

int	nbr_return(long long number, t_base base, t_printf *data)
{
	size_t	backup;

	backup = data->size_number;
	if (number < 0)
	{
		number *= -1;
		data->flags.has_plus = 0;
		data->flags.has_space = 0;
		data->flags.neg = 1;
	}
	if (data->flags.size_dot >= data->size_number)
		data->size_number = data->flags.size_dot;
	if (special_case(data) && !number)
		data->size_number = 0;
	if (print_identation(data, data->size_number, BEFORE) == -1)
		return (-1);
	if ((data->size_number >= backup) && \
		print_zeros((data->size_number - backup), data) == -1)
		return (-1);
	if (data->size_number && print_number(number, base, data) == -1)
		return (-1);
	if (print_identation(data, data->size_number, AFTER) == -1)
		return (-1);
	return (0);
}

int	char_return(char c, t_printf *data, t_char flag)
{
	int	write_status;

	if (flag == CHAR && print_identation(data, 1, BEFORE) == -1)
		return (-1);
	write_status = write(data->fd, &c, 1);
	if (write_status == -1)
		return (-1);
	data->count += 1;
	if (flag == CHAR && print_identation(data, 1, AFTER) == -1)
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
	if (data->flags.has_dot && data->flags.size_dot < size_string)
		size_string = data->flags.size_dot;
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
