/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_lvl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 09:50:52 by vtiterin          #+#    #+#             */
/*   Updated: 2017/01/04 09:50:55 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_up_str(char **buf, int l, char *line)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(*buf);
	tmp = ft_strnew(len + l);
	ft_strncpy(tmp, *buf, len);
	ft_strncat(tmp, line, l);
	free(*buf);
	*buf = ft_strnew(len + l + 1);
	ft_strncpy(*buf, tmp, len + l);
	ft_strncat(*buf, "#", 1);
	free(tmp);
}

char	*read_matrix(char *arvg)
{
	char	*ret;
	char	*buf;
	int		fd;

	ret = ft_strnew(0);
	if ((fd = open(arvg, O_RDONLY)) == -1)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	while (get_next_line(fd, &buf))
	{
		ft_up_str(&ret, ft_strlen(buf), buf);
		free(buf);
	}
	free(buf);
	close(fd);
	return (ret);
}

char	**cr_map(char *arg)
{
	char	**ret;
	char	*str;

	str = read_matrix(arg);
	ret = ft_strsplit(str, '#');
	free(str);
	return (ret);
}
