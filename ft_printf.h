/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:22:46 by qdang             #+#    #+#             */
/*   Updated: 2019/11/22 13:42:00 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** flag: 1 - '#', 2 - '0', 3 - '-', 4 - '+', 5 - ' '
*/

# define HASH	2
# define ZERO	3
# define MINUS	5
# define PLUS	7
# define SPACE	11

/*
** length: 1 - hh, 2 - h, 3 - l, 4 - ll, 5 - L
*/

# define CHAR 	1
# define SHORT	2
# define LONG 	3
# define LL		4
# define LD		5

/*
** cp: 1 - c, 2 - s, 3 - p, 4 - d & i, 5 - o, 6 - u, 7 - x, 8 - X
*/

# define UC 		1
# define STRING		2
# define POINTER	3
# define SI		 	4
# define UOI		5
# define UI			6
# define UHIL		7
# define UHIU		8

typedef struct	s_info
{
	int		flag;
	int		mfw;
	int		prec;
	int		length;
	int		cp;
}				t_info;
void			get_all_info(char *p, t_info *s);

#endif
