/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:28:13 by kristori          #+#    #+#             */
/*   Updated: 2022/12/02 12:28:35 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_check_fd1(int *fd, char **argv)
{
	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] < 0)
	{
		perror("pipex: input");
		exit(EXIT_FAILURE);
	}
}

void	ft_check_fd2(int *fd, char **argv)
{
	fd[1] = open(argv[fd[2] - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd[1] < 0)
	{
		perror("pipex: input");
		exit(EXIT_FAILURE);
	}
}
