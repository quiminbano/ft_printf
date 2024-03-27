/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:37:01 by corellan          #+#    #+#             */
/*   Updated: 2024/03/28 00:31:43 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	get_numbers(t_flags *fl, size_t *begin, const char *s)
{
	char	*numbers;
	int		converted_number;
	size_t	numbers_size;

	converted_number = 0;
	numbers_size = 0;
	while (ft_isdigit(s[((*begin) + 1) + numbers_size]))
		numbers_size++;
	if (!numbers_size)
		return (0);
	numbers = ft_substr(s, (*begin + 1), numbers_size);
	if (!numbers)
		return (-1);
	converted_number = ft_atoi(numbers);
	free(numbers);
	numbers = NULL;
	if (converted_number < 0 || numbers_size > 10)
		return (-1);
	if (fl->number_for_dot)
		fl->size_string = converted_number;
	else
		fl->size_print = converted_number;
	(*begin) += numbers_size;
	return (0);
}

int	fill_ident(t_flags *fl, size_t *begin, size_t end, const char *s)
{
	fl->number_for_dot = 0;
	if (s[*begin] == '-')
	{
		fl->has_minus = 1;
		fl->has_pure_number = 0;
	}
	else if (s[*begin] == '.')
	{
		if (s[end] == 's')
		{
			fl->has_dot = 1;
			fl->number_for_dot = 1;
		}
		else if (s[end] != 'c')
			fl->has_zero = 1;
	}
	if (!fl->has_minus)
		fl->has_pure_number = 1;
	if (s[*begin + 1] == '0' && !fl->has_minus)
		fl->has_zero = 1;
	if (s[*begin + 1] == '0')
		(*begin)++;
	return (get_numbers(fl, begin, s));
}

void	fill_format(t_flags *fl, size_t begin, size_t end, const char *s)
{
	size_t	iter;

	iter = begin;
	while (iter < end)
	{
		if (s[end] == 'd' && s[iter] == ' ' && !fl->has_plus)
			fl->has_space = 1;
		else if (s[end] == 'd' && s[iter] == '+')
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
