/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_print_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 23:42:23 by corellan          #+#    #+#             */
/*   Updated: 2024/03/28 00:15:19 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	print_special(t_printf *data, t_when when)
{
	int	write_status;

	write_status = 0;
	if (when == BEFORE && data->flags.has_plus)
	{
		write_status = write(data->fd, "+", 1);
		(data->count)++;
	}
	else if (when == BEFORE && data->flags.has_sharp && \
		data->flags.type_sharp == UPPER)
	{
		write_status = write(data->fd, "0X", 2);
		data->count += 2;
	}
	else if (when == BEFORE && data->flags.has_sharp && \
		data->flags.type_sharp == LOWER)
	{
		write_status = write(data->fd, "0x", 2);
		data->count += 2;
	}
	if (write_status == -1)
		return (-1);
	return (0);
}

static int	sp_zero(t_printf *data, size_t size_parameter, t_when when, char c)
{
	int		write_status;
	size_t	iter;

	iter = 0;
	while (data->flags.has_pure_number && iter < size_parameter)
	{
		write_status = write(data->fd, &c, 1);
		if (write_status == -1)
			return (-1);
		iter++;
		(data->count)++;
	}
	if (when == BEFORE && c == ' ' && print_special(data, when) == -1)
		return (-1);
	return (0);
}

int	print_identation(t_printf *data, size_t size_parameter, t_when when)
{
	size_t	total_size;
	char	c;

	total_size = data->flags.size_print;
	if (data->flags.has_zero && data->flags.has_pure_number)
		c = '0';
	else
		c = ' ';
	if (data->flags.has_plus)
		size_parameter += 1;
	if (data->flags.has_sharp)
		size_parameter += 2;
	if (c == '0' && print_special(data, when) == -1)
		return (-1);
	if (total_size >= size_parameter)
		total_size -= size_parameter;
	else
		total_size = 0;
	if (when == BEFORE && sp_zero(data, size_parameter, when, c) == -1)
		return (-1);
	if (when == AFTER && sp_zero(data, size_parameter, when, c) == -1)
		return (-1);
	return (0);
}
