/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:04:32 by fhassane          #+#    #+#             */
/*   Updated: 2025/04/06 20:04:33 by fhassane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	strlen_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i);
}

int	ft_so_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	ft_len(int n)
{
	long int	nbr;
	int			i;

	nbr = (long int)n;
	i = 0;
	if (!nbr)
		return (1);
	if (nbr < 0)
	{
		nbr = nbr * -1;
		i++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	nbr;

	nbr = (long int)n;
	i = ft_len(n);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * -1;
	}
	str[i] = '\0';
	while (nbr > 0)
	{
		i--;
		str[i] = (nbr % 10) + 48;
		nbr = nbr / 10;
	}
	return (str);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc((ft_strlen_name(s) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
