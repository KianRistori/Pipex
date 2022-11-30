/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:45:00 by kristori          #+#    #+#             */
/*   Updated: 2022/11/30 15:23:28 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_cmd_not_found(char **cmd)
{
	write(2, cmd[0], ft_strlen(cmd[0]));
	write(2, ": command not found\n", 20);
	ft_free(cmd);
	exit(127);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_check_split(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (ft_strncmp(cmd[i], "'", 1) == 0)
		{
			cmd[i] = ft_strjoin(cmd[i], " ");
			cmd[i] = ft_strjoin(cmd[i], cmd[i + 1]);
			ft_remove_char(cmd[i], 39);
			cmd[i + 1] = 0;
		}
		i++;
	}
}

void	ft_remove_char(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			str[j] = str[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
}
