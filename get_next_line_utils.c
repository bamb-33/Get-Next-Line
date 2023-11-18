/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:54:47 by naadou            #+#    #+#             */
/*   Updated: 2023/11/18 18:30:32 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_realloc(void *add, void *half_add, size_t size)
{
	void	*new_add;
	int		i;

	new_add = malloc (size);
	if (!new_add)
		return (NULL);
	i = 0;
	while (((char *)half_add)[i])
	{
		((char *) new_add)[i] = ((char *) half_add)[i];
		i++;
	}
	((char *) new_add)[size - 1] = 0;
	free(add);
	return (new_add);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	subs = (char *) malloc ((len + 1) * sizeof(char));
	if (subs == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = 0;
	return (subs);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*scpy;
	int		slen;
	int		i;

	i = 0;
	slen = ft_strlen(s1) + 1;
	scpy = (char *) malloc (slen * sizeof(char));
	if (!scpy)
		return (0);
	while (i < slen)
	{
		scpy[i] = s1[i];
		i++;
	}
	return (scpy);
}

char	*ft_strjoin(char *s1, char *s2, int len_read)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	p = (char *) malloc ((ft_strlen(s1) + len_read) * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (s1[i] || j < len_read)
	{
		if (s1[i])
		{
			p[i + j] = s1[i];
			i++;
		}
		else
		{
			p[i + j] = s2[j];
			j++;
		}
	}
	free(s1);
	p[i + j] = 0;
	return (p);
}
