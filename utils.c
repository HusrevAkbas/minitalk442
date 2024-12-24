/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:25:38 by huakbas           #+#    #+#             */
/*   Updated: 2024/12/24 11:40:18 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_stringholder	*init_string()
{
	t_stringholder	*string;

	string = malloc(sizeof(t_stringholder));
	if (!string)
		return (NULL);
	string->str = ft_calloc(BUFF_SIZE + 1, sizeof(char));
	if (!string->str)
	{
		free(string);
		return (NULL);
	}
	ft_bzero(string->bin, 9);
	string->i_bin = 0;
	string->i_str = 0;
	string->is_long = 0;
	string->is_long_set = 0;
	return (string);
}
