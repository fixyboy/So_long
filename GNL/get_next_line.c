/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:41:10 by fhassane          #+#    #+#             */
/*   Updated: 2025/01/25 17:41:19 by fhassane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_get_line(int fd, char *line)
{
	char	*buffer;
	ssize_t	read_bytes;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(line, 10) && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*ft_get_next_line(char *line)
{
	int		i;
	char	*str;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != 10)
		i++;
	str = (char *)malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != 10)
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] == 10)
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_line(char *str)
{
	int		i;
	int		j;
	char	*str2;

	i = 0;
	while (str[i] && str[i] != 10)
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	str2 = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!str2)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		str2[j++] = str[i++];
	str2[j] = '\0';
	free(str);
	return (str2);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_get_line(fd, buffer);
	if (!buffer)
		return (NULL);
	next_line = ft_get_next_line(buffer);
	buffer = new_line(buffer);
	return (next_line);
}
//     int main(void)
// {
// 	int fd;
// 	int i;
// 	char *line;
// 	i = 0;
// 	fd = open("test.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("%s",line);
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("line %02d: %s", i++, line);
// 		free(line);
// 	}
// 	close(fd);
// }