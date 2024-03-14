/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:45:22 by corellan          #+#    #+#             */
/*   Updated: 2024/03/14 21:59:27 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_variadic(const char *s, va_list *ar, int fd, t_printf *data)
{
	int	*count;

	count = &(data->count);
	if (s[data->index] == 'd' || s[data->index] == 'i')
		return (nbr_return(va_arg(*ar, int), fd, NORMAL, count));
	else if (s[data->index] == 'c')
		return (char_return(va_arg(*ar, int), fd, count));
	else if (s[data->index] == 'u')
		return (print_number(va_arg(*ar, unsigned int), fd, NORMAL, count));
	else if (s[data->index] == 'x')
		return (print_number(va_arg(*ar, unsigned int), fd, LOWER, count));
	else if (s[data->index] == 'X')
		return (print_number(va_arg(*ar, unsigned int), fd, UPPER, count));
	else if (s[data->index] == 'p')
		return (print_pointer(va_arg(*ar, unsigned long), fd, LOWER, count));
	else if (s[data->index] == 's')
		return (str_return(va_arg(*ar, char *), fd, count));
	else if (s[data->index] == '%')
		return (char_return('%', fd, count));
	return (0);
}

int	ft_dprintf(int fd, const char *s, ...)
{
	va_list		ar;
	t_printf	data;

	ft_bzero(&data, sizeof(data));
	va_start(ar, s);
	while (s[data.index])
	{
		if (s[data.index] == '%' && s[data.index + 1] != '\0')
		{
			(data.index)++;
			data.return_status = handle_variadic(s, &ar, fd, &data);
			(data.count) -= 2;
		}
		else if (s[data.index] != '%' && s[data.index] != '\0')
			data.return_status = char_return(s[data.index], fd, &data.count);
		if (data.return_status == -1)
		{
			va_end(ar);
			return (-1);
		}
		(data.index)++;
	}
	va_end(ar);
	return (data.count);
}

int	ft_printf(const char *s, ...)
{
	va_list		ar;
	t_printf	data;

	ft_bzero(&data, sizeof(data));
	va_start(ar, s);
	while (s[data.index])
	{
		if (s[data.index] == '%' && s[data.index + 1] != '\0')
		{
			(data.index)++;
			data.return_status = handle_variadic(s, &ar, 1, &data);
		}
		else if (s[data.index] != '%' && s[data.index] != '\0')
			data.return_status = char_return(s[data.index], 1, &data.count);
		if (data.return_status == -1)
		{
			va_end(ar);
			return (-1);
		}
		(data.index)++;
	}
	va_end(ar);
	return (data.count);
}
