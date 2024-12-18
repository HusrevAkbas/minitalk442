/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:05:12 by husrevakbas       #+#    #+#             */
/*   Updated: 2024/11/25 15:12:54 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_handle_int(t_flags *flags, va_list args, int *res)
{
	char	*str_to_print;
	char	*num_str;

	num_str = ft_itoa(va_arg(args, int));
	free(flags->prefix);
	if (num_str && num_str[0] == '-')
	{
		flags->prefix = ft_strdup("-");
		ft_memmove(num_str, &num_str[1], ft_strlen(num_str));
	}
	else if (flags->plus == 1)
		flags->prefix = ft_strdup("+");
	else if (flags->space == 1)
		flags->prefix = ft_strdup(" ");
	else
		flags->prefix = ft_strdup("");
	if (flags->zero && !flags->minus && !flags->precision)
		str_to_print = ft_set_zeropadded_str(flags, num_str);
	else
		str_to_print = ft_set_flagged_str(flags, num_str);
	if (str_to_print)
		*res += write(1, str_to_print, ft_strlen(str_to_print));
	free(num_str);
	free(str_to_print);
}
