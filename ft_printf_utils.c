/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:30:19 by corellan          #+#    #+#             */
/*   Updated: 2024/03/14 18:03:44 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_number(long long number, int fd, t_base base, int *count)
{
	int		write_status;
	char	lower_base[MAXBASE];
	char	upper_base[MAXBASE];

	ft_strlcpy(lower_base, "0123456789abcdef", 18);
	ft_strlcpy(upper_base, "0123456789ABCDEF", 18);
	if (base == UPPER)
		write_status = char_return(upper_base[number], fd, count);
	else
		write_status = char_return(lower_base[number], fd, count);
	if (write_status == -1)
		return (-1);
	return (0);
}

int	print_pointer(long long number, int fd, t_base base, int *count)
{
	int	write_status;

	write_status = write(1, "0x", 2);
	if (write_status == -1)
		return (-1);
	(*count) += 2;
	return (nbrbase_return(number, fd, base, count));
}

int	nbrbase_return(long long number, int fd, t_base base, int *count)
{
	int	write_status;
	int	base_num;

	if (base == NORMAL)
		base_num = 10;
	else
		base_num = 16;
	if (number < 0)
	{
		write_status = char_return('-', fd, count);
		if (write_status == -1)
			return (-1);
		return (nbrbase_return((number * -1), fd, base, count));
	}
	else if (number >= base_num)
	{
		write_status = nbrbase_return((number / base_num), fd, base, count);
		if (write_status == -1)
			return (-1);
		write_status = nbrbase_return((number % base_num), fd, base, count);
		if (write_status == -1)
			return (-1);
	}
	else
		return (print_number(number, fd, base, count));
	return (0);
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
