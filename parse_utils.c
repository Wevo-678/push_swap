/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenet <mabenet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:18:24 by mabenet           #+#    #+#             */
/*   Updated: 2024/10/07 10:06:24 by mabenet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_checker(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-' && ('0' > s[i + 1] || s[i + 1] > '9'))
			return (0);
		if (!(('0' <= s[i] && s[i] <= '9') || s[i] == '-'))
			return (0);
		i++;
	}
	return (1);
}

int	tab_checker(char **tab, int i, int count)
{
	while (i < count)
	{
		if (str_checker(tab[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	countword(char *s)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
			i++;
		if ((s[i] != ' ' && s[i] != '\t' && s[i] != '\n') && s[i])
			count++;
		while ((s[i] != ' ' && s[i] != '\t' && s[i] != '\n') && s[i])
			i++;
	}
	return (count);
}

int	wordlen(char *s, int i)
{
	int	cnt;

	cnt = 0;
	while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
	{
		cnt++;
		i++;
	}
	return (cnt);
}

char	**ft_split(char *s)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (countword(s) + 1));
	while (s[i])
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
			i++;
		if (s[i])
		{
			k = 0;
			tab[j] = malloc(sizeof(char) * (wordlen(s, i) + 1));
			while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			{
				tab[j][k++] = s[i++];
			}
			tab[j++][k] = '\0';
		}
	}
	tab[j] = NULL;
	return (tab);
}
