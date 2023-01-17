/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:46:02 by kristori          #+#    #+#             */
/*   Updated: 2023/01/17 11:09:53 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(void)
{
	perror("Error\n");
	exit(EXIT_FAILURE);
}

void	ft_execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = ft_path(cmd[0], envp);
	if (!path)
	{
		ft_free(cmd);
		free(cmd);
		ft_error();
	}
	if (execve(path, cmd, envp) == -1)
		ft_error();
}

int	ft_open_file(char *argv, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		file = open(argv, O_RDONLY, 0777);
	if (file == -1)
		ft_error();
	return (file);
}

int	get_next_line(char **line)
{
	char	*buffer;
	char	c;
	int		i;
	int		r;

	i = 0;
	r = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (0);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[i + 1] = '\0';
	*line = buffer;
	free(buffer);
	return (r);
}
