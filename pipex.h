/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:29:32 by kristori          #+#    #+#             */
/*   Updated: 2022/11/28 12:58:56 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"

int		ft_child_one(int *pipefd, int fd, char **argv, char **envp);
int		ft_child_two(int *pipefd, int fd, char **argv, char **envp);
char	**ft_parsing(char **envp);

#endif
