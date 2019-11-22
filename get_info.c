/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:30:27 by qdang             #+#    #+#             */
/*   Updated: 2019/11/22 13:41:20 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static void		get_flag_info(char *p, t_info *s)
{
	if (*p == '#')
		s->flag *= HASH;
	if (*p == '0')
		s->flag *= ZERO;
	if (*p == '-')
		s->flag *= MINUS;
	if (*p == '+')
		s->flag *= PLUS;
	if (*p == ' ')
		s->flag *= SPACE;
}

static void		get_mfw_prec_info(char *p, t_info *s)
{
	char	*pp;

	if (s->flag % ZERO == 0)
	{
		while (*p != '0')
			p++;
		p++;
	}
	s->mfw = ft_strnbr(p, '.');
	pp = ft_strchr(p, '.');
	if (pp != NULL)
		s->prec = ft_strnbr(pp, 0);
}

static void		get_length_info(char *p, t_info *s)
{
	if (*p == 'h' && *(p + 1) == 'h')
		s->length = CHAR;
	if (*p == 'h' && *(p + 1) != 'h')
		s->length = SHORT;
	if (*p == 'l' && *(p + 1) != 'l')
		s->length = LONG;
	if (*p == 'l' && *(p + 1) == 'l')
		s->length = LL;
	if (*p == 'L')
		s->length = LD;
}

static void		get_cp_info(char *p, t_info *s)
{
	if (*p == 'c')
		s->cp = UC;
	if (*p == 's')
		s->cp = STRING;
	if (*p == 'p')
		s->cp = POINTER;
	if (*p == 'd' || *p == 'i')
		s->cp = SI;
	if (*p == 'o')
		s->cp = UOI;
	if (*p == 'u')
		s->cp = UI;
	if (*p == 'x')
		s->cp = UHIL;
	if (*p == 'X')
		s->cp = UHIU;
}

void			get_all_info(char *p, t_info *s)
{
	char	*temp;

	s->flag = 1;
	temp = p;
	if (*++temp == '%')
	{
		ft_putstr("%\n");
		return ;
	}
	temp = p;
	while (*++temp && *temp != '%' && !(*temp > '0' && *temp <= '9'))
		get_flag_info(temp, s);
	temp = p;
	if (*++temp && *temp != '%')
		get_mfw_prec_info(temp, s);
	temp = p;
	while (*++temp && *temp != '%' && s->length == 0)
		get_length_info(temp, s);
	temp = p;
	while (*++temp && *temp != '%' && s->cp == 0)
		get_cp_info(temp, s);
}
