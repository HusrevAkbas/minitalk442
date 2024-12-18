/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:56:21 by husrevakbas       #+#    #+#             */
/*   Updated: 2024/11/25 15:12:59 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_handle_char(t_flags *flags, va_list args, int *res)
{
	unsigned char	the_char;
	char			*newstr;

	the_char = (unsigned char) va_arg(args, int);
	newstr = ft_set_flagged_str(flags, "");
	if (flags->minus == 1)
	{
		write(1, &the_char, 1);
		*res += write(1, newstr, ft_strlen(newstr)) + 1;
	}
	else
	{
		*res += write(1, newstr, ft_strlen(newstr)) + 1;
		write(1, &the_char, 1);
	}
	free(newstr);
}
