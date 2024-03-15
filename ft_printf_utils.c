/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:30:19 by corellan          #+#    #+#             */
/*   Updated: 2024/03/15 09:03:52 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_number(unsigned long number, int fd, t_base base, int *count)
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
		write_status = print_number((number / base_num), fd, base, count);
		if (write_status == -1)
			return (-1);
		write_status = print_number((number % base_num), fd, base, count);
		if (write_status == -1)
			return (-1);
	}
	else if (base == UPPER)
		write_status = char_return(upper_base[number], fd, count);
	else
		write_status = char_return(lower_base[number], fd, count);
	if (write_status == -1)
		return (-1);
	return (0);
}

int	print_pointer(unsigned long number, int fd, t_base base, int *count)
{
	int	write_status;

	write_status = write(fd, "0x", 2);
	if (write_status == -1)
		return (-1);
	(*count) += 2;
	return (print_number(number, fd, base, count));
}

int	nbr_return(long long number, int fd, t_base base, int *count)
{
	int	write_status;

	if (number < 0)
	{
		write_status = char_return('-', fd, count);
		if (write_status == -1)
			return (-1);
		return (print_number((number * -1), fd, base, count));
	}
	return (print_number(number, fd, base, count));
}

int	char_return(char c, int fd, int *count)
{
	int	write_status;

	write_status = write(fd, &c, 1);
	if (write_status == -1)
		return (-1);
	(*count) += 1;
	return (0);
}

int	str_return(char *str, int fd, int *count)
{
	int	write_status;

	if (str == NULL)
	{
		write_status = write(fd, "(null)", 6);
		(*count) += 6;
	}
	else
	{
		write_status = write(fd, str, ft_strlen(str));
		(*count) += (int)ft_strlen(str);
	}
	if (write_status == -1)
		return (-1);
	return (0);
}
