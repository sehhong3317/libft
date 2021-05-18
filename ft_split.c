/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 08:44:16 by sehhong           #+#    #+#             */
/*   Updated: 2021/05/18 10:24:31 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	malloc_fail(char **str, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static int		count_chunk(char *str, char c)
{
	int	ck_cnt;
	int	str_cnt;

	str_cnt = 0;
	ck_cnt = 0;
	while (*str)
	{
		if (*str != c)
			str_cnt++;
		else
		{
			if (str_cnt != 0)
			{
				ck_cnt++;
				str_cnt = 0;
			}
		}
		str++;
	}
	if (str_cnt)
		ck_cnt++;
	return (ck_cnt);
}

static	void	str_input(char *dest, char *src, char c)
{
	while (*src != c && *src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = '\0';
}

static void		str_malloc(char **ret, char *str, char c)
{
	int		j;
	int		ck;

	ck = 0;
	while (*str)
	{
		if (*str == c)
			str++;
		else
		{
			j = 0;
			while (str[j] != c && str[j] != '\0')
				j++;
			ret[ck] = (char*)malloc(sizeof(char) * (j + 1));
			if (!ret)
			{
				malloc_fail(ret, ck);
				return ;
			}
			str_input(ret[ck], str, c);
			ck++;
			str += j;
		}
	}
}

char			**ft_split(char *str, char c)
{
	char	**ret;
	int		len_chunk;

	if (str == NULL)
		return (NULL);
	len_chunk = count_chunk(str, c);
	ret = (char**)malloc(sizeof(char*) * (len_chunk + 1));
	if (!ret)
		return (NULL);
	ret[len_chunk] = 0;
	str_malloc(ret, str, c);
	return (ret);
}
