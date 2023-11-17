/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:17:43 by naadou            #+#    #+#             */
/*   Updated: 2023/11/17 23:33:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t			size;
	static char	*buffer;
	char			*tmp;
	size_t			i;
	size_t			j;


	size = 1024;
	if (!buffer)
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
		if (!buffer[0])
			return (NULL);
		if (i == j)
			return (buffer);
		while (j < i)
		{
			if (buffer[j] == '\n')
			{
				tmp = ft_substr(buffer, 0, j);
				printf("buffer before: %s\n", buffer);
				buffer = (char *) ft_realloc(&buffer[j + 1], size); // WTF
				printf("buffer after: %s\n\n\n", buffer);
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
		printf("r:%s\n", get_next_line(fd));
	close (fd);
}
