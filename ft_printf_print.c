/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:30:19 by corellan          #+#    #+#             */
/*   Updated: 2024/04/02 15:26:13 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		data->str = append_char(data->str, upper_base[number]);
	else
		data->str = append_char(data->str, lower_base[number]);
	if (!data->str)
		return (-1);
	return (0);
}

int	print_pointer(unsigned long number, t_base base, t_printf *data)
{
	data->str = append_str(data->str, "0x", 2);
	if (!data->str)
		return (-1);
	data->count += 2;
	return (print_number(number, base, data));
}

int	nbr_return(long long number, t_base base, t_printf *data)
{
	if (number < 0)
	{
		data->str = append_char(data->str, '-');
		if (!data->str)
			return (-1);
		return (print_number((number * -1), base, data));
	}
	return (print_number(number, base, data));
}

int	char_return(char c, t_printf *data)
{
	data->str = append_char(data->str, c);
	if (!data->str)
		return (-1);
	data->count += 1;
	return (0);
}

int	str_return(char *str, t_printf *data)
{
	if (str == NULL)
	{
		data->str = append_str(data->str, "(null)", 6);
		data->count += 6;
	}
	else
	{
		data->str = append_str(data->str, str, ft_strlen(str));
		data->count += (int)ft_strlen(str);
	}
	if (!data->str)
		return (-1);
	return (0);
}
