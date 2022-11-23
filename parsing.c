/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:53:10 by kristori          #+#    #+#             */
/*   Updated: 2022/11/23 11:56:15 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_paths(char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	return (paths);
}

char	*path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*tmp;
	int		i;

	i = 0;
	if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
		return (cmd);
	paths = get_paths(envp);
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!access(path, F_OK))
			return (path);
		free(path);
		i++;
	}
	return (0);
}
