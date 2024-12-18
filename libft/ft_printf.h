/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:25:55 by huakbas           #+#    #+#             */
/*   Updated: 2024/11/25 15:12:03 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

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

typedef struct s_flags
{
	int		hash;
	char	id;
	int		minus;
	int		plus;
	int		precision;
	int		space;
	int		width;
	int		zero;
	char	*prefix;
}	t_flags;

int			ft_printf(const char *format, ...);
void		ft_handle_convertion(t_flags *flags, va_list args, int *res);
char		*ft_itobase_uint(unsigned int nbr, const char *base);
const char	*get_const(char *set);
char		*ft_itobase_ul(unsigned long nbr, const char *base);
void		ft_handle_char(t_flags *flags, va_list args, int *res);
void		ft_handle_int(t_flags *flags, va_list args, int *res);
void		ft_handle_string(t_flags *flags, va_list args, int *res);
void		ft_handle_pointer(t_flags *flags, va_list args, int *res);
void		ft_handle_uint(t_flags *f, va_list a, int *r, const char *b);
char		*ft_set_flagged_str(t_flags *flags, char *str);
char		*ft_set_zeropadded_str(t_flags *flags, char *str);
t_flags		*set_flags(char **checkpoint);

#endif // FT_PRINTF_H
