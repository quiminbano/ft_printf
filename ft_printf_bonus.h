/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:46:08 by corellan          #+#    #+#             */
/*   Updated: 2024/03/28 00:13:21 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# define MAXBASE 17

# include <stdarg.h>
# include "libft/libft.h"

typedef enum e_base
{
	NORMAL,
	UPPER,
	LOWER
}	t_base;

typedef enum when
{
	BEFORE,
	AFTER
}	t_when;

typedef struct s_flags
{
	int		has_minus;
	int		has_dot;
	int		has_pure_number;
	int		has_zero;
	int		has_sharp;
	int		has_space;
	int		has_plus;
	int		size_string;
	int		size_print;
	int		number_for_dot;
	t_base	type_sharp;
}	t_flags;

typedef struct s_printf
{
	char	conversion;
	int		count;
	int		fd;
	int		return_status;
	size_t	index;
	size_t	size_number;
	t_flags	flags;
}	t_printf;

int		ft_printf(const char *s, ...);
int		ft_dprintf(int fd, const char *s, ...);
int		str_return(char *str, t_printf *data);
int		char_return(char c, t_printf *data);
int		nbr_return(long long number, t_base base, t_printf *data);
int		print_unsigned(unsigned long number, t_base base, t_printf *data);
int		print_number(unsigned long number, t_base base, t_printf *data);
void	fill_format(t_flags *fl, size_t begin, size_t end, const char *s);
int		fill_ident(t_flags *fl, size_t *begin, size_t end, const char *s);
size_t	length_number(const char c, va_list *ar, int base);
int		print_identation(t_printf *data, size_t size_parameter, t_when when);

#endif
