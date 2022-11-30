/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:54:41 by kristori          #+#    #+#             */
/*   Updated: 2022/11/30 15:23:24 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_get_paths(char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	return (paths);
}

char	*ft_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*tmp;
	int		i;

	i = 0;
	if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
		return (cmd);
	paths = ft_get_paths(envp);
	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!access(path, F_OK))
		{
			ft_free(paths);
			return (path);
		}
		free(path);
	}
	ft_free(paths);
	return (0);
}
