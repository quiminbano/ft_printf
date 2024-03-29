/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:45:22 by corellan          #+#    #+#             */
/*   Updated: 2024/03/29 22:41:29 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	check_undefined(const char *s, size_t *after_flags, t_printf *data)
{
	size_t	i;

	i = data->index;
	while (s[i] == '#' || s[i] == '+' || s[i] == '-' || s[i] == ' ' || \
		s[i] == '.' || ft_isdigit(s[i]))
		i++;
	(*after_flags) = i;
	if (s[i] == '\0')
	{
		data->index = ((*after_flags) - 1);
		return (1);
	}
	if (s[i] != 'd' && s[i] != 'i' && \
		s[i] != 'c' && s[i] != 'p' && \
		s[i] != 'x' && s[i] != 'X' && \
		s[i] != 's' && s[i] != 'u')
	{
		data->index = (*after_flags);
		return (1);
	}
	return (0);
}

static int	handle_variadic(va_list *ar, t_printf *data)
{
	if (data->flags.conversion == 'd' || data->flags.conversion == 'i')
		return (nbr_return(va_arg(*ar, int), NORMAL, data));
	else if (data->flags.conversion == 'c')
		return (char_return(va_arg(*ar, int), data, CHAR));
	else if (data->flags.conversion == 'u')
		return (print_unsigned(va_arg(*ar, unsigned int), NORMAL, data));
	else if (data->flags.conversion == 'x')
		return (print_unsigned(va_arg(*ar, unsigned int), LOWER, data));
	else if (data->flags.conversion == 'X')
		return (print_unsigned(va_arg(*ar, unsigned int), UPPER, data));
	else if (data->flags.conversion == 'p')
		return (print_unsigned(va_arg(*ar, unsigned long), LOWER, data));
	else if (data->flags.conversion == 's')
		return (str_return(va_arg(*ar, char *), data));
	else if (data->flags.conversion == '%')
		return (char_return('%', data, CHAR));
	return (0);
}

static int	check_flags(const char *s, va_list *ar, t_printf *data)
{
	size_t	after_flags;
	int		ident_status;

	after_flags = 0;
	ident_status = 0;
	if (check_undefined(s, &after_flags, data))
		return (0);
	fill_format(&(data->flags), data->index, after_flags, s);
	while (data->index < after_flags)
	{
		data->flags.begin = s[data->index];
		ident_status = fill_ident(&(data->flags), &(data->index), after_flags, s);
		if (ident_status == -1)
			return (-1);
		else if (ident_status && data->flags.begin != '.' && \
			data->flags.begin != '-' && data->flags.begin != '0')
			(data->index)++;
	}
	if (s[data->index] == 'x' || s[data->index] == 'X' || \
		s[data->index] == 'p')
		data->size_number = length_number(s[data->index], ar, 16);
	else if (s[data->index] == 'd' || s[data->index] == 'i' || \
		s[data->index] == 'u')
		data->size_number = length_number(s[data->index], ar, 10);
	return (handle_variadic(ar, data));
}

int	ft_dprintf(int fd, const char *s, ...)
{
	va_list		ar;
	t_printf	data;

	ft_bzero(&data, sizeof(data));
	va_start(ar, s);
	data.fd = fd;
	while (s[data.index])
	{
		ft_bzero(&(data.flags), sizeof(data.flags));
		if (s[data.index] == '%' && s[data.index + 1] != '\0')
		{
			(data.index)++;
			data.return_status = check_flags(s, &ar, &data);
		}
		else if (s[data.index] != '%' && s[data.index] != '\0')
			data.return_status = char_return(s[data.index], &data, CHAR);
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
	data.fd = 1;
	while (s[data.index])
	{
		ft_bzero(&(data.flags), sizeof(data.flags));
		if (s[data.index] == '%' && s[data.index + 1] != '\0')
		{
			(data.index)++;
			data.return_status = check_flags(s, &ar, &data);
		}
		else if (s[data.index] != '%' && s[data.index] != '\0')
			data.return_status = char_return(s[data.index], &data, CHAR);
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
