/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:30:15 by ftanon            #+#    #+#             */
/*   Updated: 2023/12/07 16:00:41 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getlength(long longnum)
{
	int		size;

	size = 0;
	if (longnum == 0)
		return (1);
	else if (longnum < 0)
		size++;
	while (longnum != 0)
	{
		size++;
		longnum = longnum / 10;
	}
	return (size);
}

static char	*copynumber(long longnum, int length)
{
	char	*string;

	string = (char *)malloc((length + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	string[length] = '\0';
	length--;
	if (longnum < 0)
	{
		string[0] = '-';
		longnum = -longnum;
	}
	else if (longnum == 0)
		string[0] = '0';
	while (longnum != 0)
	{
		string[length] = longnum % 10 + '0';
		longnum = longnum / 10;
		length--;
	}
	return (string);
}

char	*ft_itoa(int num)
{
	char	*string;
	long	longnum;
	int		length;

	longnum = (long)num;
	length = getlength(longnum);
	string = copynumber(longnum, length);
	return (string);
}

/* int main ()
{
int num = INT_MAX;
printf("%s\n",ft_itoa(num));
} */
