/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:53:07 by huakbas           #+#    #+#             */
/*   Updated: 2025/01/10 15:34:47 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **list)
{
	if (list == NULL || *list == NULL)
		return ;
	ft_lstclear(&(*list)->next);
	ft_lstdelone(*list);
	*list = NULL;
}
