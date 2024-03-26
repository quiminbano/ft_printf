/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:46:08 by corellan          #+#    #+#             */
/*   Updated: 2024/03/20 20:53:29 by corellan         ###   ########.fr       */
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


typedef struct s_flags
{
	int	has_minus;
	int	has_dot;
	int	has_pure_number;
	int	has_zero;
	int	has_sharp;
}	t_flags;

typedef struct s_printf
{
	int		count;
	size_t	index;
	int		return_status;
	size_t	flag_info;
	size_t	to_write;
	size_t	total_length;
}	t_printf;

int	ft_printf(const char *s, ...);
int	ft_dprintf(int fd, const char *s, ...);
int	str_return(char *str, int fd, int *count);
int	char_return(char c, int fd, int *count);
int	nbr_return(long long number, int fd, t_base base, int *count);
int	print_pointer(unsigned long number, int fd, t_base base, int *count);
int	print_number(unsigned long number, int fd, t_base base, int *count);

#endif
