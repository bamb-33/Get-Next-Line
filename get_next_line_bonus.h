/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:22:23 by naadou            #+#    #+#             */
/*   Updated: 2023/11/25 19:25:05 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

void	*ft_realloc(size_t index, void *add, size_t size);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2, int len_read);
char	*get_next_line(int fd);

#endif