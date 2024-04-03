/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:16:57 by corellan          #+#    #+#             */
/*   Updated: 2024/04/03 08:49:26 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	number_length(size_t n, size_t base)
{
	size_t	i;

	i = 1;
	if (n == 0)
		return (i);
	while ((n / base) > 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

static char	*create_string(size_t n, size_t base, const char *template)
{
	char	*digit;
	size_t	i;
	size_t	length;

	if (base > 16)
		return (NULL);
	length = number_length(n, base);
	digit = (char *)malloc(sizeof(char) * (length + 1));
	if (!digit)
		return (NULL);
	i = length;
	digit[i] = '\0';
	while (i-- > 0)
	{
		digit[i] = template[(n % base)];
		n /= base;
	}
	return (digit);
}

char	*ft_ultoa_base(size_t n, size_t base, size_t format)
{
	const char	*lower = "0123456789abcdef";
	const char	*upper = "0123456789ABCDEF";

	if (format % 2 == 0)
		return (create_string(n, base, lower));
	return (create_string(n, base, upper));
}
