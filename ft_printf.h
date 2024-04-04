/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:46:08 by corellan          #+#    #+#             */
/*   Updated: 2024/04/04 22:13:25 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define STRBUFFER 4096

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
	int		return_status;
	size_t	buffer_idx;
	size_t	mct;
	size_t	index;
	char	*str;
	char	buffer[STRBUFFER + 1];
}	t_printf;

int		ft_printf(const char *s, ...);
int		ft_dprintf(int fd, const char *s, ...);
int		str_return(char *str, t_printf *data);
int		char_return(char c, t_printf *data);
int		nbr_return(long long number, t_base base, t_printf *data);
int		append_pointer(unsigned long number, t_base base, t_printf *data);
int		append_number(unsigned long number, t_base base, t_printf *data);
int		append_char(t_printf *data, char c);
int		append_str(t_printf *data, char const *str, size_t n);
char	*copy_to_heap(char *s1, const char *s2, int count, size_t n);

#endif
