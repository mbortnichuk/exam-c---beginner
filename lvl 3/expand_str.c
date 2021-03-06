/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:40:16 by mbortnic          #+#    #+#             */
/*   Updated: 2018/01/30 17:32:41 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	expand_str(char *s)
{
	int		i;

	i = -1;
	while (*s)
	{
		while (*s && (*s == ' ' || *s == '\t' || *s == '\n'))
			s++;
		if (*s && i != -1)
			write(1, "   ", 3);
		i = 0;
		while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			i++;
		write(1, s, i);
		s = s + i;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		expand_str(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}
