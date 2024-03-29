/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:37:01 by corellan          #+#    #+#             */
/*   Updated: 2024/03/29 22:36:47 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>

static size_t	get_size(size_t *begin, const char *s)
{
	size_t	numbers_size;

	numbers_size = 0;
	while (ft_isdigit(s[(*begin) + numbers_size]))
		numbers_size++;
	return (numbers_size);
}

static int	get_numbers(t_flags *fl, size_t *begin, const char *s)
{
	char	*numbers;
	int		converted_number;
	size_t	numbers_size;

	converted_number = 0;
	numbers_size = get_size(begin, s);
	if (!numbers_size)
		return (1);
	numbers = ft_substr(s, (*begin), numbers_size);
	if (!numbers)
		return (-1);
	converted_number = ft_atoi(numbers);
	free(numbers);
	numbers = NULL;
	if (converted_number < 0 || numbers_size > 10)
		return (-1);
	if (!fl->has_minus && ((fl->begin != '.') || (fl->begin == '.' && \
		fl->conversion != 'c' && fl->conversion != 's')))
		fl->has_pure_number = 1;
	if (fl->begin == '.' && fl->conversion == 's')
		fl->size_string = converted_number;
	else
		fl->size_print = converted_number;
	(*begin) += numbers_size;
	return (0);
}

int	fill_ident(t_flags *fl, size_t *begin, size_t end, const char *s)
{
	fl->conversion = s[end];
	if (s[*begin] == '-')
	{
		fl->has_minus = 1;
		fl->has_pure_number = 0;
		(*begin)++;
	}
	else if (s[*begin] == '.')
	{
		if (s[end] == 's')
			fl->has_dot = 1;
		else if (s[end] != 'c')
			fl->has_zero = 1;
		(*begin)++;
	}
	if (s[*begin] == '0' && !fl->has_minus)
		fl->has_zero = 1;
	if (s[*begin] == '0')
		(*begin)++;
	return (get_numbers(fl, begin, s));
}

void	fill_format(t_flags *fl, size_t begin, size_t end, const char *s)
{
	size_t	iter;

	iter = begin;
	while (iter < end)
	{
		if ((s[end] == 'd' || s[end] == 'i') && \
			s[iter] == ' ' && !fl->has_plus)
			fl->has_space = 1;
		else if ((s[end] == 'd' || s[end] == 'i') && s[iter] == '+')
		{
			fl->has_plus = 1;
			fl->has_space = 0;
		}
		else if (s[end] == 'x' && s[iter] == '#')
		{
			fl->has_sharp = 1;
			fl->type_sharp = LOWER;
		}
		else if (s[end] == 'X' && s[iter] == '#')
		{
			fl->has_sharp = 1;
			fl->type_sharp = UPPER;
		}
		iter++;
	}
}
