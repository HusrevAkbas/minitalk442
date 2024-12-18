/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_set_flagged_str.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:23:46 by huakbas           #+#    #+#             */
/*   Updated: 2024/11/25 15:12:40 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_width(t_flags *flags, size_t len_str, size_t len_pfix)
{
	size_t	width;
	size_t	precision;
	int		i;

	i = 0;
	while (ft_strchr(get_const("flags"), flags->id))
		i++;
	width = flags->width;
	precision = flags->precision;
	if (width < len_str + len_pfix)
		width = len_str + len_pfix;
	if (precision + len_pfix > width && flags->id != 's')
		width = precision + len_pfix;
	if (flags->id == 'c' && width > 0)
		width--;
	return (width);
}

void	left_align(t_flags *flags, char *str_new, char *str, char *prefix)
{
	size_t	precision;
	size_t	len_str;
	size_t	len_pfix;

	precision = flags->precision;
	len_str = ft_strlen(str);
	len_pfix = ft_strlen(flags->prefix);
	if (precision > len_str + len_pfix && flags->id != 's')
	{
		ft_memcpy(str_new, prefix, len_pfix);
		ft_memset(str_new + len_pfix, '0', precision - len_str);
		ft_memcpy(str_new + len_pfix + precision - len_str, str, len_str);
	}
	else
	{
		ft_memcpy(str_new + len_pfix, str, len_str);
		ft_memcpy(str_new, prefix, len_pfix);
	}
}

void	right_align(t_flags *flags, char *str_new, char *str, char *prefix)
{
	size_t	precision;
	size_t	len_str;
	size_t	len_pfix;
	size_t	width;

	precision = flags->precision;
	len_str = ft_strlen(str);
	len_pfix = ft_strlen(flags->prefix);
	width = get_width(flags, len_str, len_pfix);
	if (precision > len_str && flags->id != 's')
	{
		ft_memcpy(str_new + (width - precision - len_pfix), prefix, len_pfix);
		ft_memset(str_new + (width - precision), '0', precision - len_str);
		ft_memcpy(str_new + (width - len_str), str, len_str);
	}
	else
	{
		ft_memcpy(str_new + (width - len_str - len_pfix), prefix, len_pfix);
		ft_memcpy(str_new + (width - len_str), str, len_str);
	}
}

char	*ft_set_flagged_str(t_flags *flags, char *str)
{
	char	*str_new;
	size_t	width;
	size_t	len_str;
	size_t	len_pfix;

	len_str = ft_strlen(str);
	len_pfix = ft_strlen(flags->prefix);
	width = get_width(flags, len_str, len_pfix);
	str_new = ft_calloc(width + 1, sizeof(char));
	if (str_new == NULL)
		return (NULL);
	ft_memset(str_new, ' ', width);
	if (flags->minus == 1)
		left_align(flags, str_new, str, flags->prefix);
	else
		right_align(flags, str_new, str, flags->prefix);
	return (str_new);
}
