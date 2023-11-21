/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:54:47 by naadou            #+#    #+#             */
/*   Updated: 2023/11/21 16:21:32 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_realloc(size_t index, void *add, size_t size)
{
	void	*new_add;
	size_t	i;

	new_add = malloc ((size) * sizeof(char));
	if (!new_add)
	{
		free(add);
		return (NULL);
	}
	i = 0;
	while (((char *)add)[index + i + 1])
	{
		((char *) new_add)[i] = ((char *) add)[index + i + 1];
		i++;
	}
	while (i < size)
	{
		((char *) new_add)[i] = 0;
		i++;
	}
	free(add);
	return (new_add);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	subs = (char *) malloc ((len + 1) * sizeof(char));
	if (subs == NULL)
	{
		free(s);
		return (NULL);
	}
	i = 0;
	while (i < len && s[start + i])
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = 0;
	return (subs);
}

static char	*ft_strdup(char *s1, int len_read)
{
	char	*scpy;
	int		i;

	i = 0;
	scpy = (char *) malloc ((len_read + 1) * sizeof(char));
	if (!scpy)
	{
		free (s1);
		return (NULL);
	}
	while (i < len_read)
	{
		scpy[i] = s1[i];
		i++;
	}
	scpy[i] = 0;
	return (scpy);
}

static char	*glue(char *s1, char *s2, char *p, int len_read)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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

char	*ft_strjoin(char *s1, char *s2, int len_read)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2, len_read));
	p = (char *) malloc ((ft_strlen(s1) + len_read + 1) * sizeof(char));
	if (!p)
	{
		free (s1);
		free (s2);
		return (NULL);
	}
	return (glue(s1, s2, p, len_read));
}
