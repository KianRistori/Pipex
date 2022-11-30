/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:29:32 by kristori          #+#    #+#             */
/*   Updated: 2022/11/30 15:23:22 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include "stdio.h"
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"

void	ft_child_one(int *pipefd, int fd, char **argv, char **envp);
void	ft_child_two(int *pipefd, int fd, char **argv, char **envp);
char	**ft_get_paths(char **envp);
char	*ft_path(char *cmd, char **envp);
void	ft_cmd_not_found(char **cmd);
void	ft_free(char **str);
void	ft_check_split(char **cmd);
void	ft_remove_char(char *str, char c);

#endif
