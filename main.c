/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:17:36 by qdang             #+#    #+#             */
/*   Updated: 2019/11/22 13:37:05 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

int		ft_printf(const char *restrict format, ...)
{
	va_list ap;
	t_info	save;
	char	*p;

	ft_bzero(&save, sizeof(save));
	va_start(ap, format);
	p = ft_strchr(format, '%');
	if (p != NULL)
	{
		get_all_info(p, &save);
	}
	va_end(ap);
	printf("flag: %d, mfw: %d, prec: %d, length: %d, cp: %d",
			save.flag, save.mfw, save.prec, save.length, save.cp);
	return (0);
}

int		main()
{
//	char	*p;
	char	*s = "%.95llXx";
//	t_info	*s;

	ft_printf(s);
//	p = ft_strchr(s, '.');
//	printf("%d\n", ft_strnbr(s, '4'));
//	ft_printf("%d\n", i);
//	ft_printf("%s\n", "Amber");
//	ft_printf("%c\n", 'a');
	return (0);
}
