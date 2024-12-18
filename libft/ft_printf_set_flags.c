/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_set_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:38:00 by husrevakbas       #+#    #+#             */
/*   Updated: 2024/11/25 15:12:34 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	1) Each conversion specification is introduced by the character %, and ends
	with a conversion specifier.
	2) In between there may be (in this order)
		1- zero or more flags,				-0. #+
		2- an optional minimum field width,	any positiv number
		3- an optional precision and 		THE '.' FLAG
		4- an optional length modifier.		NOT INCLUDED
		5- convertion identifiers			cspdiuxX%
*/
t_flags	*init_flag(void)
{
	t_flags	*flags;

	flags = (t_flags *) malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	flags->id = 0;
	flags->hash = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->precision = 0;
	flags->prefix = ft_strdup("");
	flags->space = 0;
	flags->width = 0;
	flags->zero = 0;
	return (flags);
}

void	set_flagset(t_flags *flags, char **checkpoint)
{
	while (**checkpoint && ft_strchr(get_const("flags"), **checkpoint))
	{
		if (**checkpoint == '0')
			flags->zero = 1;
		if (**checkpoint == '-')
			flags->minus = 1;
		if (**checkpoint == '+')
			flags->plus = 1;
		if (**checkpoint == '#')
			flags->hash = 1;
		if (**checkpoint == ' ')
			flags->space = 1;
		*checkpoint += 1;
	}
}

t_flags	*set_flags(char **checkpoint)
{
	t_flags	*flags;

	flags = init_flag();
	if (flags == NULL)
		return (NULL);
	set_flagset(flags, checkpoint);
	flags->width = ft_atoi(*checkpoint);
	while (ft_isdigit(**checkpoint))
		*checkpoint += 1;
	if (**checkpoint == '.')
	{
		*checkpoint += 1;
		flags->precision = ft_atoi(*checkpoint);
		while (ft_isdigit(**checkpoint))
			*checkpoint += 1;
	}
	if (ft_strchr(get_const("con_id"), **checkpoint))
		flags->id = **checkpoint;
	return (flags);
}
