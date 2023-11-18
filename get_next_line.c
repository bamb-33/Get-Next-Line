/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:17:43 by naadou            #+#    #+#             */
/*   Updated: 2023/11/18 13:18:01 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t		size;
	static char	*buffer;
	char		*tmp;
	size_t		i;
	size_t		j;

	size = 1024;
	tmp = (char *) malloc (sizeof(char) * size);
	if (!tmp)
		return (NULL);
	tmp[size -1] = 0;
	i = 0;
	j = 0;
	while (1)
	{
		if (BUFFER_SIZE > size || i == size - 2)
		{
			size += BUFFER_SIZE;
			tmp = (char *) ft_realloc(tmp, size);
		}
		if (buffer)
		{
			while (buffer[j])
			{
				if (buffer[j] == '\n')
				{
					tmp = ft_substr(buffer, 0, j);
					buffer = (char *) ft_realloc(&buffer[j + 1], size); // WTF
					return (tmp);
				}
				j++;
			}
		}
		i = read(fd, &tmp[i], BUFFER_SIZE);
		if (i == 0 && !(*tmp) && *buffer)
			return (NULL);
		else if (i == 0)
			return (buffer);
		buffer = ft_strjoin(buffer, tmp);
	}
	return (NULL);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	// printf("%s", r);
	for (int i = 0; i < 5; i++)
		printf("returned line:  %s\n", get_next_line(fd));
	close (fd);
}
