/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_pcsp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:52:29 by qdang             #+#    #+#             */
/*   Updated: 2020/01/22 11:52:32 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_info          *deal_percentage(t_info *s)
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

t_info          *deal_char(t_info *s)
{
    char    c;

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

t_info          *deal_string(t_info *s)
{
    char    *str;
    int     strlen;

    str = va_arg(s->ap, char *);
    strlen = ft_strlen(str);
    if (s->flag[MINUS] == '1')
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
    if (s->flag[MINUS] != '1')
        ft_putstr(str);
    s->len += strlen;
    s->fm++;
    return (s);
}

static void     output_pointer(t_info *s, unsigned long long ptr, int ptrlen)
{
    if (s->flag[MINUS] == '1' || s->flag[ZERO] == '1')
        ft_putstr("0x");
    if (s->flag[MINUS] == '1')
        ft_puthex(ptr, 'x');
    if (s->mfw > ptrlen)
    {
        s->len += s->mfw - ptrlen;
        s->mfw++;
        if (s->flag[ZERO] == '1' && s->flag[MINUS] != '1')
            while (--s->mfw > ptrlen)
                ft_putchar('0');
        else
            while (--s->mfw > ptrlen)
                ft_putchar(' ');
    }
    if (s->flag[MINUS] != '1' && s->flag[ZERO] != '1')
        ft_putstr("0x");
    if (s->flag[MINUS] != '1')
        ft_puthex(ptr, 'x');
}

t_info          *deal_pointer(t_info *s)
{
    unsigned long long      ptr;
    unsigned long long      temp;
    int                     ptrlen;

    ptr = (unsigned long long)va_arg(s->ap, void *);
    temp = ptr;
    ptrlen = 2;
    while (temp > 0)
    {
        ptrlen++;
        temp /= 16;
    }
    output_pointer(s, ptr, ptrlen);
    s->len += ptrlen;
    s->fm++;
    s->signal = 1;
    return (s);
}
