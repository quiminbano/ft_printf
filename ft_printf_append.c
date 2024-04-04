/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_append.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:30:19 by corellan          #+#    #+#             */
/*   Updated: 2024/04/05 00:27:33 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	append_number(unsigned long number, t_base base, t_printf *data)
{
	int				write_status;
	unsigned long	base_num;
	size_t			length;
	char			*str;

	if (base == NORMAL)
		base_num = 10;
	else
		base_num = 16;
	str = ft_ultoa_base(number, base_num, (size_t)base);
	if (!str)
		return (-1);
	length = ft_strlen(str);
	write_status = append_str(data, str, length);
	free(str);
	str = NULL;
	if (write_status == -1)
		return (-1);
	data->count += length;
	return (0);
}

int	append_pointer(unsigned long number, t_base base, t_printf *data)
{
	if (append_str(data, "0x", 2) == -1)
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
	if (append_char(data, c) == -1)
		return (-1);
	data->count += 1;
	return (0);
}

int	str_return(char *str, t_printf *data)
{
	int		write_status;
	size_t	length;

	if (str == NULL)
	{
		length = 6;
		write_status = append_str(data, "(null)", length);
	}
	else
	{
		length = ft_strlen(str);
		write_status = append_str(data, str, length);
	}
	data->count += (int)length;
	if (write_status == -1)
		return (-1);
	return (0);
}
