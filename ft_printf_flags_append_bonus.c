/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_append_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 23:42:23 by corellan          #+#    #+#             */
/*   Updated: 2024/04/03 10:28:54 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	special_case(t_printf *data)
{
	if (data->flags.has_dot && !data->flags.size_dot && !data->flags.orig_num)
		return (1);
	return (0);
}

int	append_sp_zero(size_t max, t_printf *data, char *tmp)
{
	size_t	iter;

	iter = 0;
	while (iter < max)
	{
		if ((max - iter) > 1000)
		{
			data->str = append_str(data->str, tmp, data->count, 1000);
			iter += 1000;
			data->count += 1000;
		}
		else
		{
			data->str = append_str(data->str, tmp, data->count, (max - iter));
			data->count += (max - iter);
			iter = max;
		}
		if (!data->str)
			return (-1);
	}
	return (0);
}

static int	append_special(t_printf *data, t_when when)
{
	char	buff[3];
	size_t	length;

	ft_bzero(buff, 3);
	if (when == BEFORE && data->flags.has_plus)
		ft_strlcpy(buff, "+", 2);
	if (when == BEFORE && data->flags.neg)
		ft_strlcpy(buff, "-", 2);
	else if (when == BEFORE && data->flags.has_space)
		ft_strlcpy(buff, " ", 3);
	else if (when == BEFORE && data->flags.has_sharp && \
		data->flags.type_sharp == UPPER)
		ft_strlcpy(buff, "0X", 3);
	else if (when == BEFORE && data->flags.has_sharp && \
		data->flags.type_sharp == LOWER)
		ft_strlcpy(buff, "0x", 3);
	length = ft_strlen(buff);
	data->str = append_str(data->str, buff, data->count, length);
	if (!data->str)
		return (-1);
	data->count += length;
	return (0);
}

static int	sp_zero(t_printf *data, size_t max, t_when when, char *tmp)
{
	int	status;

	status = 0;
	if (when == BEFORE && data->flags.has_pure_number && \
		append_sp_zero(max, data, tmp) == -1)
		return (-1);
	if (when == BEFORE && tmp == data->sp && append_special(data, when) == -1)
		return (-1);
	if (when == AFTER && data->flags.has_minus && \
		append_sp_zero(max, data, tmp) == -1)
		return (-1);
	return (0);
}

int	append_identation(t_printf *data, size_t size_parameter, t_when when)
{
	size_t	total_size;
	char	*tmp;

	total_size = data->flags.size_print;
	tmp = data->sp;
	if (data->flags.has_zero && data->flags.has_pure_number)
		tmp = data->zero;
	if (data->flags.has_plus || data->flags.has_space || data->flags.neg)
		size_parameter += 1;
	if (data->flags.has_sharp)
		size_parameter += 2;
	if (tmp == data->zero && append_special(data, when) == -1)
		return (-1);
	if (total_size >= size_parameter)
		total_size -= size_parameter;
	else
		total_size = 0;
	if (sp_zero(data, total_size, when, tmp) == -1)
		return (-1);
	return (0);
}
