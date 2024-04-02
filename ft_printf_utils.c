/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:10:34 by corellan          #+#    #+#             */
/*   Updated: 2024/04/02 19:31:21 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*handle_return(char **s1, char *returned)
{
	if ((*s1))
		free((*s1));
	(*s1) = NULL;
	return (returned);
}

char	*append_char(char *s1, const char c, int count)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	if (count < 0)
		return (handle_return(&s1, NULL));
	res = (char *)malloc(sizeof(char) * (count + 2));
	if (!res)
		return (handle_return(&s1, NULL));
	while (i < count)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = c;
	i++;
	res[i] = '\0';
	return (handle_return(&s1, res));
}

char	*append_str(char *s1, const char *s2, int count, size_t n)
{
	size_t	len2;
	size_t	i;
	char	*res;

	i = 0;
	len2 = n;
	res = NULL;
	if (n > ft_strlen(s2))
		len2 = ft_strlen(s2);
	if (count < 0)
		return (handle_return(&s1, NULL));
	res = (char *)malloc(sizeof(char) * ((size_t)count + len2 + 1));
	if (!res)
		return (handle_return(&s1, NULL));
	while (i < ((size_t)count + len2))
	{
		if (i < (size_t)count)
			res[i] = s1[i];
		else
			res[i] = s2[i - (size_t)count];
		i++;
	}
	res[i] = '\0';
	return (handle_return(&s1, res));
}
