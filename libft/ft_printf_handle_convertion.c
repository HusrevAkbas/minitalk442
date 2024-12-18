/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_convertion.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:34:47 by huakbas           #+#    #+#             */
/*   Updated: 2024/10/13 20:28:10 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_handle_convertion(t_flags *flags, va_list args, int *res)
{
	if (flags->id == '%')
		*res += write(1, "%", 1);
	if (flags->id == 'c')
		ft_handle_char(flags, args, res);
	if (flags->id == 'd' || flags->id == 'i')
		ft_handle_int(flags, args, res);
	if (flags->id == 's')
		ft_handle_string(flags, args, res);
	if (flags->id == 'p')
		ft_handle_pointer(flags, args, res);
	if (flags->id == 'u')
		ft_handle_uint(flags, args, res, get_const("decimal"));
	if (flags->id == 'x')
		ft_handle_uint(flags, args, res, get_const("hex_low"));
	if (flags->id == 'X')
		ft_handle_uint(flags, args, res, get_const("hex_up"));
}
