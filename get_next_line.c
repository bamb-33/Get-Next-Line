/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:17:43 by naadou            #+#    #+#             */
/*   Updated: 2023/11/20 21:56:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	f(char **buffer, char **tmp)
{
	int j;

	j = 0;
	if (*buffer)
	{
		while ((*buffer)[j])
		{
			if ((*buffer)[j] == '\n')
			{
				free(*tmp);
				*tmp = ft_substr(*buffer, 0, (j) + 1);
				if (!(*tmp))
					return (0);
				*buffer = (char *)ft_realloc(*buffer, &(*buffer)[(j) + 1], ft_strlen(*buffer));
				if (!(*buffer))
				{
					free(*tmp);
					return (0);
				}
				return (1);
			}
			(j)++;
		}
	}
	return (-1);
}

int	f2(char **buffer, char **tmp, int i)
{
	if (i == -1)
	{
		free(*tmp);
		if (*buffer)
			free(*buffer);
		return (0);
	}
	if (i == 0 && (!*buffer || (*buffer)[0] == 0))
	{
		free(*tmp);
		return (0);
	}
	else if (i == 0)
	{
		free(*tmp);
		*tmp = *buffer;
		*buffer = NULL;
		return (1);
	}
	*buffer = ft_strjoin(*buffer, *tmp, i);
	if (!(*buffer))
		return (0);
}

int	allocation(char **tmp, int fd)
{
	*tmp = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!(*tmp))
		return (0);
	if (read(fd, *tmp, 0) == -1)
	{
		free (*tmp);
		return (0);
	}
	(*tmp)[BUFFER_SIZE] = 0;
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*tmp;
	int			i;
	int			k;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE > SIZE_MAX || BUFFER_SIZE < 0)
		return (NULL);
	if (allocation(&tmp, fd) == 0)
		return (NULL);
	i = 0;
	while (1)
	{
		k = f(&buffer, &tmp);
		if (k == 1)
			return (tmp);
		else if (k == 0)
			return (NULL);
		i = read(fd, tmp, BUFFER_SIZE);
		k = f2(&buffer, &tmp, i);
		if (k == 1)
			return (tmp);
		else if (k == 0)
			return (NULL);
	}
	return (NULL);
}

// int main()
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	// printf("%s", r);
// 	for (int i = 0; i < 5; i++)
// 		printf("line :%s\n", get_next_line(fd));
// 	//system("leaks a.out");
// 	// get_next_line(fd);
// 	// char *rr = get_next_line(fd);
// 	// for (int i = 0; i < 1; i++)
// 	// 	printf("%d\n", rr[i]);
// 	close (fd);
// }   
