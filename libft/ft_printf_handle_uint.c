/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_uint.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:13:50 by husrevakbas       #+#    #+#             */
/*   Updated: 2024/11/25 15:12:44 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_prefix(t_flags *flags)
{
	free(flags->prefix);
	if (flags->id == 'x')
		flags->prefix = ft_strdup("0x");
	else if (flags->id == 'X')
		flags->prefix = ft_strdup("0X");
	else
		flags->prefix = ft_strdup("");
}

void	ft_handle_uint(t_flags *flags, va_list args, int *res, const char *base)
{
	char			*str_to_print;
	char			*num_str;
	unsigned int	num;

	num = va_arg(args, unsigned int);
	num_str = ft_itobase_uint(num, base);
	if (flags->hash == 1 && num != 0)
		set_prefix(flags);
	if (flags->zero && !flags->minus && !flags->precision)
		str_to_print = ft_set_zeropadded_str(flags, num_str);
	else
		str_to_print = ft_set_flagged_str(flags, num_str);
	*res += write(1, str_to_print, ft_strlen(str_to_print));
	free(str_to_print);
	free(num_str);
}
