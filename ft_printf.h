/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:39:48 by qdang             #+#    #+#             */
/*   Updated: 2020/01/17 19:39:51 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdlib.h>
#include <stdarg.h>

# define HASH	0
# define ZERO	1
# define PLUS	2
# define MINUS	3
# define SPACE	4

typedef	struct	s_info
{
	va_list		ap;
	int			len;
	const char	*fm;
	int			mfw;
	char		flag[5];
	int			signal;
}				t_info;

void    		ft_putui(unsigned int i);
void    		ft_putoct(unsigned int i);
void    		ft_puthex(unsigned long long i, char c);

t_info  		*deal_flags(t_info *s);
t_info  		*deal_min_field_width(t_info *s);

t_info  		*deal_percentage(t_info *s);
t_info  		*deal_char(t_info *s);
t_info  		*deal_string(t_info *s);
t_info  		*deal_pointer(t_info *s);

t_info  		*deal_decimal_integer(t_info *s);
t_info      	*deal_octal(t_info *s);
t_info          *deal_unsigned_int(t_info *s);
t_info          *deal_hexadecimal(t_info *s);

#endif