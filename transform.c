/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 11:36:29 by qdang             #+#    #+#             */
/*   Updated: 2020/02/11 11:36:30 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long trans_ull(t_info *s, unsigned long long nbr)
{
    if (s->length[CHAR] == '1')
        nbr = (unsigned char)nbr;
    else if (s->length[SHORT] == '1')
        nbr = (unsigned short)nbr; 
    else if (s->length[LONG] == '1')
        nbr = (unsigned long)nbr; 
    else if (s->length[LONGLONG] == '1')
        nbr = (unsigned long long)nbr;
    else
        nbr = (unsigned int)nbr;
    return (nbr);
}

long long           trans_ll(t_info *s, long long nbr)
{
    if (s->length[CHAR] == '1')
        nbr = (char)nbr;
    else if (s->length[SHORT] == '1')
        nbr = (short)nbr; 
    else if (s->length[LONG] == '1')
        nbr = (long)nbr; 
    else if (s->length[LONGLONG] == '1')
        nbr = (long long)nbr;
    else
        nbr = (int)nbr;
    return (nbr);
}