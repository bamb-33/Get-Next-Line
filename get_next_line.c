/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:17:43 by naadou            #+#    #+#             */
/*   Updated: 2023/11/20 18:49:36 by naadou           ###   ########.fr       */
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
	if (fd < 0 || fd > 1023 || BUFFER_SIZE > SIZE_MAX || BUFFER_SIZE < 0)
		return (NULL);
	tmp = (char *) malloc (sizeof(char) * size);
	if (!tmp)
		return (NULL);
	if (read(fd, tmp, 0) < 0)
	{
		free (tmp);
		return (NULL);
	}
	tmp[size -1] = 0;
	i = 0;
	j = 0;
	while (1)
	{
		if (BUFFER_SIZE > size)
		{
			size += BUFFER_SIZE;
			tmp = (char *) ft_realloc(tmp, tmp, size);
		}
		if (buffer)
		{
			while (buffer[j])
			{
				if (buffer[j] == '\n')
				{
					free (tmp);
					tmp = ft_substr(buffer, 0, j + 1);
					if (!tmp)
					{
						free (buffer);
						return (NULL);
					}
					buffer = (char *) ft_realloc(buffer, &buffer[j + 1], ft_strlen(buffer));
					if (!buffer)
					{
						free (tmp);
						return (NULL);
					}
					return (tmp);
				}
				j++;
			}
		}
		i = read(fd, tmp, BUFFER_SIZE);
		if (i < 0)
		{
			free(tmp);
			if (buffer)
				free(buffer);
			return (NULL);
		}
		if (i == 0 && (!buffer || buffer[0] == 0))
		{
			free (tmp);
			return (NULL);
		}
		else if (i == 0)
		{
			free(tmp);
			tmp = buffer;
			buffer = NULL;
			return (tmp); // IDK mybe later
		}
		buffer = ft_strjoin(buffer, tmp, i);
		if (!buffer)
			return (NULL);
	}
	return (NULL);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	//int fd1 = open("test1.txt", O_RDONLY);
	// printf("%s", r);
	// for (int i = 0; i < 5; i++)
	printf("returned line :%s\n", get_next_line(fd));
	printf("returned line :%s\n", get_next_line(fd));
	printf("returned line :%s\n", get_next_line(fd));
	printf("returned line :%s\n", get_next_line(fd));
	printf("returned line :%s\n", get_next_line(fd));
	printf("returned line :%s\n", get_next_line(fd));
	printf("returned line :%s\n", get_next_line(fd));
	system("leaks a.out");
	// get_next_line(fd);
	// char *rr = get_next_line(fd);
	// for (int i = 0; i < 1; i++)
	// 	printf("%d\n", rr[i]);
	close (fd);
}
