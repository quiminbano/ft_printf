/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:46:08 by corellan          #+#    #+#             */
/*   Updated: 2024/04/03 12:03:46 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# define MAXBASE 17

# include <stdarg.h>
# include <limits.h>
# include "libft/libft.h"

typedef enum e_base
{
	NORMAL,
	UPPER,
	LOWER
}	t_base;

typedef enum e_char
{
	CHAR,
	NUMBER,
	NOCONV
}	t_char;

typedef enum when
{
	BEFORE,
	AFTER
}	t_when;

typedef struct s_flags
{
	char	begin;
	char	conv;
	int		orig_num;
	int		dot_number;
	int		has_minus;
	int		has_dot;
	int		has_pure_number;
	int		has_zero;
	int		has_sharp;
	int		has_space;
	int		has_plus;
	int		neg;
	size_t	size_dot;
	size_t	size_print;
	t_base	type_sharp;
	va_list	*ptr;
}	t_flags;

typedef struct s_printf
{
	char	*str;
	char	zero[1001];
	char	sp[1001];
	int		count;
	int		return_status;
	size_t	index;
	size_t	size_number;
	t_flags	flags;
}	t_printf;

int		ft_printf(const char *s, ...);
int		ft_dprintf(int fd, const char *s, ...);
int		str_return(char *str, t_printf *data);
int		char_return(char c, t_printf *data, t_char flag);
int		nbr_return(long long number, t_base base, t_printf *data);
int		append_unsigned(unsigned long number, t_base base, t_printf *data);
int		append_number(unsigned long number, t_base base, t_printf *data);
int		no_conv(t_printf *data, const char *s);
char	*append_str(char *s1, const char *s2, int count, size_t n);
char	*append_char(char *s1, const char c, int count);
int		check_undef(const char *s, size_t *af, t_printf *data, va_list *ar);
void	fill_format(t_flags *fl, size_t begin, size_t end, const char *s);
int		fill_ident(t_flags *fl, size_t *begin, size_t end, const char *s);
size_t	length_number(const char c, va_list *ar, int base);
int		append_identation(t_printf *data, size_t size_parameter, t_when when);
int		append_sp_zero(size_t max, t_printf *data, char *tmp);
int		special_case(t_printf *data);

#endif
