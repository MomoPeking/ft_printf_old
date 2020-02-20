/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:27:34 by qdang             #+#    #+#             */
/*   Updated: 2020/02/19 14:27:39 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"

int     main()
{
    int     a;
    int     b;

    a = ft_printf("%5u", 4294967295);
    printf("Return Value of ft_printf: %d\n", a);
    b = printf("%5u", 4294967295);
    printf("Return Value of printf: %d\n", b);
    return (0);
}