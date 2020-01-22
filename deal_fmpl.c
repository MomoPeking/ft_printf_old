/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_fmpl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:51:56 by qdang             #+#    #+#             */
/*   Updated: 2020/01/22 11:52:00 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_info  *deal_flags(t_info *s)
{
    ft_bzero(s->flag, 5);
    while (*s->fm == '#' || *s->fm == '0'
			|| *s->fm == '+' || *s->fm == '-' || *s->fm == ' ')
    {
        if (*s->fm == '#')
            s->flag[HASH] = '1'; 
        if (*s->fm == '0')
            s->flag[ZERO] = '1'; 
        if (*s->fm == '+')
            s->flag[PLUS] = '1'; 
        if (*s->fm == '-')
            s->flag[MINUS] = '1'; 
        if (*s->fm == ' ')
            s->flag[SPACE] = '1'; 
        s->fm++;
    }
    return (s);
}

t_info  *deal_min_field_width(t_info *s)
{
    s->mfw = 0;
    if (*s->fm >= '0' && *s->fm <= '9')
        s->mfw = ft_strnbr((char *)s->fm);
    while (*s->fm >= '0' && *s->fm <= '9')
        s->fm++;
    if (*s->fm == '*')
    {
        s->mfw = va_arg(s->ap, int);
        s->fm++;
    }
    return (s);
}
