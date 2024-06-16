/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_append.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:30:19 by corellan          #+#    #+#             */
/*   Updated: 2024/06/16 10:16:48 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	append_number(unsigned long number, t_base base, t_printf *data)
{
	int				write_status;
	unsigned long	base_num;
	size_t			length;

	if (base == NORMAL)
		base_num = 10;
	else
		base_num = 16;
	ft_bzero(data->ul_buf, sizeof(data->ul_buf));
	ft_sultoa_base(data->ul_buf, number, base_num, (size_t)base);
	length = ft_strlen(data->ul_buf);
	write_status = append_str(data, data->ul_buf, length);
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
	if (append_char(data, c, 0) == -1)
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
