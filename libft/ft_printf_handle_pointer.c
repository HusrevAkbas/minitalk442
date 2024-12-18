/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_pointer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 00:16:37 by husrevakbas       #+#    #+#             */
/*   Updated: 2024/11/25 15:12:52 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	set_prefix(t_flags *flags)
{
	char	*prefix;

	prefix = "";
	if (flags->space == 1)
		prefix = " ";
	if (flags->plus == 1)
		prefix = "+";
	free(flags->prefix);
	flags->prefix = (char *) ft_strjoin(prefix, "0x");
}

void	ft_handle_pointer(t_flags *flags, va_list args, int *res)
{
	char			*str_to_print;
	unsigned long	i;
	char			*num_str;

	i = (unsigned long) va_arg(args, void *);
	if (i == 0)
	{
		str_to_print = ft_set_flagged_str(flags, "(nil)");
		*res += write(1, str_to_print, ft_strlen(str_to_print));
	}
	else
	{
		set_prefix(flags);
		num_str = ft_itobase_ul(i, get_const("hex_low"));
		if (flags->zero && !flags->minus && !flags->precision)
			str_to_print = ft_set_zeropadded_str(flags, num_str);
		else
			str_to_print = ft_set_flagged_str(flags, num_str);
		*res += write(1, str_to_print, ft_strlen(str_to_print));
		free(num_str);
	}
	free(str_to_print);
}
