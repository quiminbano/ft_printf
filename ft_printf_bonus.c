/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:45:22 by corellan          #+#    #+#             */
/*   Updated: 2024/04/01 18:16:17 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	check_undef(const char *s, size_t *af, t_printf *data, va_list *ar)
{
	size_t	i;

	i = data->index;
	while (s[i] == '#' || s[i] == '+' || s[i] == '-' || s[i] == ' ' || \
		s[i] == '.' || s[i] == '*' || ft_isdigit(s[i]))
		i++;
	(*af) = i;
	if (s[i] == '\0')
	{
		data->index = ((*af) - 1);
		return (1);
	}
	if (s[i] != 'd' && s[i] != 'i' && \
		s[i] != 'c' && s[i] != 'p' && \
		s[i] != 'x' && s[i] != 'X' && \
		s[i] != 's' && s[i] != 'u' && \
		s[i] != '%')
	{
		data->index = (*af);
		return (1);
	}
	data->flags.ptr = ar;
	return (0);
}

static int	handle_variadic(va_list *ar, t_printf *data, const char *s)
{
	data->flags.conv = s[data->index];
	if (data->flags.conv == 'd' || data->flags.conv == 'i')
		return (nbr_return(va_arg(*ar, int), NORMAL, data));
	else if (data->flags.conv == 'c')
		return (char_return(va_arg(*ar, int), data, CHAR));
	else if (data->flags.conv == 'u')
		return (print_unsigned(va_arg(*ar, unsigned int), NORMAL, data));
	else if (data->flags.conv == 'x')
		return (print_unsigned(va_arg(*ar, unsigned int), LOWER, data));
	else if (data->flags.conv == 'X')
		return (print_unsigned(va_arg(*ar, unsigned int), UPPER, data));
	else if (data->flags.conv == 'p')
		return (print_unsigned(va_arg(*ar, unsigned long), LOWER, data));
	else if (data->flags.conv == 's')
		return (str_return(va_arg(*ar, char *), data));
	else if (data->flags.conv == '%')
		return (char_return('%', data, CHAR));
	return (0);
}

static int	check_flags(const char *s, va_list *ar, t_printf *data)
{
	size_t	after_fl;
	int		ident_status;

	after_fl = 0;
	ident_status = 0;
	if (check_undef(s, &after_fl, data, ar))
		return (0);
	fill_format(&(data->flags), data->index, after_fl, s);
	while (data->index < after_fl)
	{
		data->flags.begin = s[data->index];
		ident_status = fill_ident(&(data->flags), &(data->index), after_fl, s);
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
	return (handle_variadic(ar, data, s));
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
			data.return_status = char_return(s[data.index], &data, NOCONV);
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
			data.return_status = char_return(s[data.index], &data, NOCONV);
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
