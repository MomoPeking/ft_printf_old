/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:39:48 by qdang             #+#    #+#             */
/*   Updated: 2020/03/10 23:38:45 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>

# define HASH		0
# define ZERO		1
# define PLUS		2
# define MINUS		3
# define SPACE		4
# define CHAR		0
# define SHORT		1
# define LONG		2
# define LONGLONG	3
# define LONGDOUBLE	4

typedef	struct		s_info
{
	va_list		ap;
	int			len;
	const char	*fm;
	int			mfw;
	int			prec;
	char		flag[5];
	char		length[5];
	int			signal;
	int			point;
}					t_info;

int					ft_printf(const char *restrict format, ...);

t_info				*deal_flags(t_info *s);
t_info				*deal_min_field_width(t_info *s);
t_info				*deal_precision(t_info *s);
t_info				*deal_length(t_info *s);

t_info				*deal_percentage(t_info *s);
t_info				*deal_char(t_info *s);
t_info				*deal_string(t_info *s);
t_info				*deal_pointer(t_info *s);
t_info				*deal_decimal_integer(t_info *s);
t_info				*deal_octal(t_info *s);
t_info				*deal_unsigned_int(t_info *s);
t_info				*deal_hexadecimal(t_info *s);
t_info				*deal_float(t_info *s);
t_info				*deal_longdouble(t_info *s);

int					di_length(t_info *s, long long nbr);
void				di_minus(t_info *s, long long nbr, int nbrlen, int z);
void				di_nonminus(t_info *s, long long nbr, int nbrlen, int z);
int					fl_length(t_info *s, long double nbr);
void				fl_minus(t_info *s, long double nbr, int nbrlen);
void				fl_nonminus(t_info *s, long double nbr, int nbrlen);

void				ft_putll(long long i);
void				ft_putui(unsigned long long i);
void				ft_putoct(unsigned long long i);
void				ft_puthex(unsigned long long i, char c);
void				ft_putf(t_info *s, long double nbr, int nbrlen);

unsigned long long	trans_ull(t_info *s, unsigned long long nbr);
long long			trans_ll(t_info *s, long long nbr);
long double			round_up(long double nbr, int declen);

#endif
