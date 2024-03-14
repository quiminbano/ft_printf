/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:46:08 by corellan          #+#    #+#             */
/*   Updated: 2024/03/14 14:54:00 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define MAXBASE 17

# include <stdarg.h>
# include "libft/libft.h"

typedef enum e_base
{
	NORMAL,
	UPPER,
	LOWER
}	t_base;

typedef struct s_printf
{
	int		count;
	size_t	index;
	int		return_status;
}	t_printf;

int	ft_printf(const char *s, ...);
int	ft_dprintf(int fd, const char *s, ...);
int	str_return(char *str, int fd, int *count);
int	char_return(char c, int fd, int *count);
int	nbrbase_return(long long number, int fd, t_base base, int *count);
int	print_pointer(long long number, int fd, t_base base, int *count);

#endif
