/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:54:35 by huakbas           #+#    #+#             */
/*   Updated: 2024/11/21 12:42:45 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*pointer;
	char	*pointer_to_char;

	if (!s)
		return (0);
	while (c >= 128)
		c = c - 128;
	pointer = (char *) s;
	pointer_to_char = 0;
	while (*pointer)
	{
		if (*pointer == c)
			pointer_to_char = pointer;
		pointer++;
	}
	if (*pointer == '\0' && c == 0)
		return (pointer);
	return (pointer_to_char);
}
