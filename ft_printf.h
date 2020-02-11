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

# define CHAR		0
# define SHORT		1
# define LONG		2
# define LONGLONG	3
# define LONGDOUBLE	4

typedef	struct	s_info
{
	va_list		ap;
	int			len;
	const char	*fm;
	int			mfw;
	int			prec;
	char		flag[5];
	char		length[5];
	int			signal;
}				t_info;

void    			ft_putll(long long i);
void    			ft_putui(unsigned long long i);
void    			ft_putoct(unsigned long long i);
void    			ft_puthex(unsigned long long i, char c);

t_info  			*deal_flags(t_info *s);
t_info  			*deal_min_field_width(t_info *s);
t_info  			*deal_precision(t_info *s);
t_info  			*deal_length(t_info *s);

t_info  			*deal_percentage(t_info *s);
t_info  			*deal_char(t_info *s);
t_info  			*deal_string(t_info *s);
t_info  			*deal_pointer(t_info *s);

t_info  			*deal_decimal_integer(t_info *s);
t_info      		*deal_octal(t_info *s);
t_info          	*deal_unsigned_int(t_info *s);
t_info          	*deal_hexadecimal(t_info *s);
t_info          	*deal_float(t_info *s);

unsigned long long	trans_ull(t_info *s, unsigned long long nbr);
long long           trans_ll(t_info *s, long long nbr);


#endif