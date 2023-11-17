/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:54:47 by naadou            #+#    #+#             */
/*   Updated: 2023/11/17 13:03:02 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_realloc(void *add, size_t size)
{
	void	*new_add;
	int		i;

	new_add = malloc (size);
	i = 0;
	while (((char *)add)[i])
	{
		((char *) new_add)[i] = ((char *) add)[i];
		i++;
	}
	((char *) new_add)[size - 1] = 0;
	return (new_add);
}
