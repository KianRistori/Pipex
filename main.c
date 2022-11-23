/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:29:19 by kristori          #+#    #+#             */
/*   Updated: 2022/11/23 11:57:18 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	int	pipefd[2];
	int	fd[2];

	if (argc == 5)
	{
		// if (pipe(pipefd) < 0)
		// 	printf("Error\n");
		ft_child_one(pipefd, fd[0], argv, envp);
	}
}

void	ft_child_one(int *pipefd, int fd, char **argv, char **envp)
{
	char	**cmd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	cmd = ft_split(argv[2], ' ');
}
