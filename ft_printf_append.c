/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_append.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:30:19 by corellan          #+#    #+#             */
/*   Updated: 2024/04/02 19:41:04 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	append_number(unsigned long number, t_base base, t_printf *data)
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
		write_status = append_number((number / base_num), base, data);
		if (write_status == -1)
			return (-1);
		write_status = append_number((number % base_num), base, data);
		if (write_status == -1)
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

int	append_pointer(unsigned long number, t_base base, t_printf *data)
{
	data->str = append_str(data->str, "0x", data->count, 2);
	if (!data->str)
		return (-1);
	data->count += 2;
	return (append_number(number, base, data));
}

int	nbr_return(long long number, t_base base, t_printf *data)
{
	int	write_status;

	if (number < 0)
	{
		write_status = char_return('-', data);
		if (write_status == -1)
			return (-1);
		return (append_number((number * -1), base, data));
	}
	return (append_number(number, base, data));
}

int	char_return(char c, t_printf *data)
{
	data->str = append_char(data->str, c, data->count);
	if (!data->str)
		return (-1);
	data->count += 1;
	return (0);
}

int	str_return(char *str, t_printf *data)
{
	if (str == NULL)
	{
		data->str = append_str(data->str, "(null)", data->count, 6);
		data->count += 6;
	}
	else
	{
		data->str = append_str(data->str, str, data->count, ft_strlen(str));
		data->count += (int)ft_strlen(str);
	}
	if (!data->str)
		return (-1);
	return (0);
}
