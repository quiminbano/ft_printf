/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:42:13 by corellan          #+#    #+#             */
/*   Updated: 2024/04/02 15:33:28 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*handle_return(char **s1, char *returned)
{
	if ((*s1))
		free((*s1));
	(*s1) = NULL;
	return (returned);
}

char	*append_char(char *s1, const char c)
{
	size_t	len;
	size_t	i;
	char	*res;

	len = 0;
	i = 0;
	if (s1)
		len = ft_strlen(s1);
	res = (char *)malloc(sizeof(char) * (len + 2));
	if (!res)
		return (handle_return(&s1, NULL));
	while (i < len)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = c;
	i++;
	res[i] = '\0';
	return (handle_return(&s1, res));
}

char	*append_str(char *s1, const char *s2, size_t n)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*res;

	i = 0;
	len1 = 0;
	len2 = n;
	if (n > ft_strlen(s2))
		len2 = ft_strlen(s2);
	if (s1)
		len1 = ft_strlen(s1);
	res = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (handle_return(&s1, NULL));
	while (i < (len1 + len2))
	{
		if (i < len1)
			res[i] = s1[i];
		else
			res[i] = s2[i - len1];
		i++;
	}
	res[i] = '\0';
	return (handle_return(&s1, res));
}

static size_t	calculate_length(int base, size_t number)
{
	size_t	result;

	result = 1;
	if (number == 0)
		return (result);
	while ((number / base) > 0)
	{
		number /= base;
		result++;
	}
	return (result);
}

size_t	length_number(const char c, va_list *ar, int base)
{
	va_list	copy;
	size_t	number;
	long	original;

	va_copy(copy, *ar);
	original = 0;
	number = 0;
	if (c == 'x' || c == 'X' || c == 'u')
		number = va_arg(copy, unsigned int);
	else if (c == 'd' || c == 'i')
	{
		original = va_arg(copy, int);
		if (original < 0)
			number = (size_t)(original * -1);
		else
			number = (size_t)original;
	}
	else
		number = va_arg(copy, unsigned long);
	va_end(copy);
	return (calculate_length(base, number));
}
