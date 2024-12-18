/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:08:58 by husrevakbas       #+#    #+#             */
/*   Updated: 2024/11/25 15:12:48 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_handle_string(t_flags *flags, va_list args, int *res)
{
	char	*str_to_print;
	char	*str;
	char	*substr;

	str = va_arg(args, char *);
	if (str)
	{
		if (flags->precision > 0 && flags->precision < (int) ft_strlen(str))
		{
			substr = (char *) ft_substr(str, 0, flags->precision);
			str_to_print = ft_set_flagged_str(flags, substr);
			free(substr);
		}
		else
			str_to_print = ft_set_flagged_str(flags, str);
	}
	else
		str_to_print = ft_set_flagged_str(flags, "(null)");
	*res += write(1, str_to_print, ft_strlen(str_to_print));
	free(str_to_print);
}
