/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:45:22 by corellan          #+#    #+#             */
/*   Updated: 2024/03/13 17:13:39 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_variadic(const char *s, va_list *args, size_t index)
{
	if (s[index] == 'd' || s[index] == 'i')
		return (putnbr_returnable(va_arg(*args, int), 1));
}

int	ft_printf(const char *s, ...)
{
	va_list		args;
	t_printf	data;

	ft_bzero(&data, sizeof(data));
	va_start(args, s);
	while (s[data.index])
	{
		if (s[data.index] == '%' && s[data.index + 1] != '\0')
		{
			(data.index)++;
			data.return_status = handle_variadic(s, &args, data.index);
		}
		else if (s[data.index] != '\0')
			data.return_status = putchar_returnable(s[data.index], 1);
		(data.index)++;
	}
	va_end(args);
	return (0);
}
