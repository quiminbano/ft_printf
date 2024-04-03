/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_no_conv_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:41:08 by corellan          #+#    #+#             */
/*   Updated: 2024/04/03 14:13:57 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	index_percentage(size_t start, const char *s)
{
	size_t	index;

	index = start;
	while (s[index] != '%' && s[index] != '\0')
		index++;
	return (index);
}

int	no_conv(t_printf *data, const char *s)
{
	char	*substr;
	size_t	end_index;
	size_t	length;

	substr = NULL;
	end_index = index_percentage(data->index, s);
	substr = ft_substr(s, data->index, (end_index - data->index));
	if (!substr)
		return (-1);
	length = ft_strlen(substr);
	data->str = append_str(data->str, substr, data->count, length);
	free(substr);
	substr = NULL;
	if (!data->str)
		return (-1);
	data->index = (end_index - 1);
	data->count += length;
	return (0);
}
