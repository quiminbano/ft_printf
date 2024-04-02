/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:45:22 by corellan          #+#    #+#             */
/*   Updated: 2024/04/02 19:40:09 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	end_and_free(va_list *ar, t_printf *data, int value)
{
	if (data->str)
		free(data->str);
	data->str = NULL;
	va_end(*ar);
	return (value);
}

static int	handle_variadic(const char *s, va_list *ar, t_printf *data)
{
	if (s[data->index] == 'd' || s[data->index] == 'i')
		return (nbr_return(va_arg(*ar, int), NORMAL, data));
	else if (s[data->index] == 'c')
		return (char_return(va_arg(*ar, int), data));
	else if (s[data->index] == 'u')
		return (append_number(va_arg(*ar, unsigned int), NORMAL, data));
	else if (s[data->index] == 'x')
		return (append_number(va_arg(*ar, unsigned int), LOWER, data));
	else if (s[data->index] == 'X')
		return (append_number(va_arg(*ar, unsigned int), UPPER, data));
	else if (s[data->index] == 'p')
		return (append_pointer(va_arg(*ar, unsigned long), LOWER, data));
	else if (s[data->index] == 's')
		return (str_return(va_arg(*ar, char *), data));
	else if (s[data->index] == '%')
		return (char_return('%', data));
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
			data.return_status = handle_variadic(s, &ar, &data);
		}
		else if (s[data.index] != '%' && s[data.index] != '\0')
			data.return_status = char_return(s[data.index], &data);
		if (data.return_status == -1 || data.count < 0)
			return (end_and_free(&ar, &data, -1));
		(data.index)++;
	}
	if (data.str && write(fd, data.str, ft_strlen(data.str)) == -1)
		return (end_and_free(&ar, &data, -1));
	return (end_and_free(&ar, &data, data.count));
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
			data.return_status = handle_variadic(s, &ar, &data);
		}
		else if (s[data.index] != '%' && s[data.index] != '\0')
			data.return_status = char_return(s[data.index], &data);
		if (data.return_status == -1 || data.count < 0)
			return (end_and_free(&ar, &data, -1));
		(data.index)++;
	}
	if (data.str && write(1, data.str, ft_strlen(data.str)) == -1)
		return (end_and_free(&ar, &data, -1));
	return (end_and_free(&ar, &data, data.count));
}
