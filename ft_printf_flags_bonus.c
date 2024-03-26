/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:37:01 by corellan          #+#    #+#             */
/*   Updated: 2024/03/26 19:49:57 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	get_numbers(t_flags *fl, size_t *begin, size_t end, const char *s)
{
	char	*numbers;
	int		converted_number;
	size_t	numbers_size;

	converted_number = 0;
	numbers_size = 0;
	while (ft_isdigit(s + (*begin) + numbers_size))
		numbers_size++;
	if (!numbers_size)
		return (0);
	numbers = ft_substr(s, *begin, numbers_size);
	if (!numbers)
		return (-1);
	converted_number = ft_atoi(numbers);
	free(converted_number);
	numbers = NULL;
}

int	fill_identation(t_flags *fl, size_t *begin, size_t end, const char *s)
{
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
		else
			fl->has_zero = 1;
		(*begin)++;
	}
	if (!fl->has_minus)
		fl->has_pure_number = 1;
	if (s[*begin] == '0')
		fl->has_zero = 1;
	return (get_numbers(fl, begin, end, s));
}

void	fill_format_flags(t_flags *fl, size_t begin, size_t end, const char *s)
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
		else if ((s[end] == 'x' || s[end] == 'X') && s[iter] == '#')
			fl->has_sharp = 1;
		iter++;
	}
}
