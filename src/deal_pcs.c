/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_pcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 16:05:28 by qdang             #+#    #+#             */
/*   Updated: 2020/03/10 19:51:39 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_info			*deal_percentage(t_info *s)
{
	if (s->flag[MINUS] == '1')
		ft_putchar('%');
	if (s->mfw > 1)
	{
		s->len += s->mfw - 1;
		s->mfw++;
		if (s->flag[ZERO] == '1' && s->flag[MINUS] != '1')
			while (--s->mfw > 1)
				ft_putchar('0');
		else
			while (--s->mfw > 1)
				ft_putchar(' ');
	}
	if (s->flag[MINUS] != '1')
		ft_putchar('%');
	s->len++;
	s->fm++;
	s->signal = 1;
	return (s);
}

t_info			*deal_char(t_info *s)
{
	char	c;

	c = (char)va_arg(s->ap, int);
	if (s->flag[MINUS] == '1')
		ft_putchar(c);
	if (s->mfw > 1)
	{
		s->len += s->mfw - 1;
		s->mfw++;
		if (s->flag[ZERO] == '1' && s->flag[MINUS] != '1')
			while (--s->mfw > 1)
				ft_putchar('0');
		else
			while (--s->mfw > 1)
				ft_putchar(' ');
	}
	if (s->flag[MINUS] != '1')
		ft_putchar(c);
	s->len++;
	s->fm++;
	s->signal = 1;
	return (s);
}

static t_info	*deal_string_2(t_info *s, char *str, char *temp, int strlen)
{
	if (s->flag[MINUS] == '1' && s->point != 1)
		ft_putstr(str);
	if (s->mfw > strlen)
	{
		s->len += s->mfw - strlen;
		s->mfw++;
		if (s->flag[ZERO] == '1' && s->flag[MINUS] != '1')
			while (--s->mfw > strlen)
				ft_putchar('0');
		else
			while (--s->mfw > strlen)
				ft_putchar(' ');
	}
	if (s->flag[MINUS] != '1' && s->point != 1)
		ft_putstr(str);
	s->len += strlen;
	s->fm++;
	s->signal = 1;
	free(str);
	if (ft_strcmp(temp, "(null)") == 0)
		free(temp);
	return (s);
}

t_info			*deal_string(t_info *s)
{
	char	*str;
	char	*temp;
	int		strlen;

	temp = va_arg(s->ap, char *);
	if (temp == NULL)
	{
		temp = ft_strnew(6);
		ft_strcpy(temp, "(null)");
	}
	if (s->prec == 0)
	{
		str = ft_strnew(ft_strlen(temp));
		ft_strcpy(str, temp);
	}
	else
	{
		str = ft_strnew(s->prec);
		ft_strncpy(str, temp, s->prec);
	}
	if (s->point != 1)
		strlen = ft_strlen(str);
	else
		strlen = 0;
	return (deal_string_2(s, str, temp, strlen));
}
