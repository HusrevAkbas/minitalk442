/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_const.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:23:12 by huakbas           #+#    #+#             */
/*   Updated: 2024/11/25 15:13:16 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
	#	The value should be converted to  an  "alternate  form".
		For x and X conversions, a nonzero result has the string
		"0x" (or "0X" for X conversions) prepended to it.
	0	The value should be zero padded. For d, i, u, x, X, a, A, e, E, f, F,
		g, and G  conversions,  the  converted value is padded on the left
		with zeros rather than blanks. If the 0 and - flags both appear, the
		0 flag is ignored. If a precision is given with a numeric conversion
		(d, i, o, u, x, and X), the 0 flag is ignored. For other conversions,
		the behavior is undefined.
	-	The converted value is to be left adjusted on the field boundary.
		(The default is right justification.) The converted value is padded
		on the right with blanks, rather than on the left with blanks or zeros.
		A - overrides a 0 if both are given.
	' '	(a space) A blank should be left before a positive number (or empty
		string) produced by a signed conversion.
	+	A sign (+ or -) should always be placed before a number produced by a
		signed conversion. By default, a sign is used only for negative numbers.
		A + overrides a space if both are used.
*/

const char	*get_const(char *set)
{
	if (!ft_strncmp(set, "flags", 5))
		return ("-0 #+");
	if (!ft_strncmp(set, "con_id", 6))
		return ("cspdiuxX%");
	if (!ft_strncmp(set, "hex_up", 6))
		return ("0123456789ABCDEF");
	if (!ft_strncmp(set, "hex_low", 7))
		return ("0123456789abcdef");
	if (!ft_strncmp(set, "decimal", 7))
		return ("0123456789");
	return ("");
}
