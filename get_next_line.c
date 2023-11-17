/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:17:43 by naadou            #+#    #+#             */
/*   Updated: 2023/11/17 20:15:03 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t			size;
	char			*buffer;
	char			*tmp;
	static size_t	i;
	size_t			j;

	size = 1024;
	buffer = (char *) malloc (sizeof(char) * size);
	if (!buffer)
		return (NULL);
	buffer[size -1] = 0;
	i = 0;
	j = 0;
	while (1)
	{
		if (BUFFER_SIZE > size || i == size - 2)
		{
			size += BUFFER_SIZE;
			buffer = (char *) ft_realloc(buffer, size);
		}
		i += read(fd, &buffer[i], BUFFER_SIZE);
		if (i == j)
			return (buffer);
		if (!buffer[0])
			return (NULL);
		while (j < i)
		{
			if (buffer[j] == '\n')
			{
				tmp = ft_substr(buffer, 0, j);
				buffer = (char *) ft_realloc(&buffer[j + 1], size);
				i -= j + 1;
				return (tmp);
			}
			j++;
		}
	}
	return (NULL);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	// printf("%s", r);
	for (int i = 0; i < 5; i++)
		printf("%s\n", get_next_line(fd));
	close (fd);
}
