/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:46:08 by corellan          #+#    #+#             */
/*   Updated: 2024/06/16 10:33:51 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef STRBUFFER
#  define STRBUFFER 2
# endif

# if STRBUFFER <= 0
#  undef STRBUFFER
#  define STRBUFFER 4096
# endif

# include <stdarg.h>
# include "libft/libft.h"

typedef enum e_typeprintf
{
	PRINTF,
	SPRINTF
}	t_typeprintf;

typedef enum e_base
{
	NORMAL,
	UPPER,
	LOWER
}	t_base;

typedef struct s_printf
{
	char			buffer[STRBUFFER + 1];
	char			ul_buf[21];
	char			*str_sprintf;
	int				count;
	int				return_status;
	int				fd;
	t_typeprintf	type;
	size_t			buffer_idx;
	size_t			index;
	size_t			pos_str;
}	t_printf;

int		ft_printf(const char *s, ...);
int		ft_dprintf(int fd, const char *s, ...);
int		ft_sprintf(char *str, const char *s, ...);
int		str_return(char *str, t_printf *data);
int		char_return(char c, t_printf *data);
int		nbr_return(long long number, t_base base, t_printf *data);
int		append_pointer(unsigned long number, t_base base, t_printf *data);
int		append_number(unsigned long number, t_base base, t_printf *data);
int		append_char(t_printf *data, char c, size_t idx);
int		append_str(t_printf *data, char const *str, size_t n);
int		return_interface(va_list *ar, t_printf *data);

#endif
