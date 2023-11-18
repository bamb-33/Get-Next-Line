/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:17:43 by naadou            #+#    #+#             */
/*   Updated: 2023/11/18 20:24:00 by naadou           ###   ########.fr       */
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
	if (fd <= 0) //handle the SIZE_MAX case
		return (NULL);
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
			tmp = (char *) ft_realloc(tmp, tmp, size);
		}
		if (buffer)
		{
			while (buffer[j])
			{
				if (buffer[j] == '\n')
				{
					//free (tmp); // TF?????
					tmp = ft_substr(buffer, 0, j + 1);
					buffer = (char *) ft_realloc(buffer, &buffer[j + 1], size);
					return (tmp);
				}
				j++;
			}
		}
		i = read(fd, tmp, BUFFER_SIZE);
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
			return (tmp);
		}
		buffer = ft_strjoin(buffer, tmp, i);
	}
	return (NULL);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	// printf("%s", r);
	for (int i = 0; i < 5; i++)
		printf("line :%s\n", get_next_line(fd));
	system("leaks a.out");
	// get_next_line(fd);
	// char *rr = get_next_line(fd);
	// for (int i = 0; i < 1; i++)
	// 	printf("%d\n", rr[i]);
	close (fd);
}
