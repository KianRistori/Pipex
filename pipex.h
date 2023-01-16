/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:29:32 by kristori          #+#    #+#             */
/*   Updated: 2023/01/16 15:32:44 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"
# include "get_next_line.h"

void	ft_child_one(int *pipefd, int *fd, char **argv, char **envp);
void	ft_child_two(int *pipefd, int *fd, char **argv, char **envp);
char	**ft_get_paths(char **envp);
char	*ft_path(char *cmd, char **envp);
void	ft_cmd_not_found(char **cmd);
void	ft_free(char **str);
void	ft_check_split(char **cmd);
void	ft_check_split2(char **cmd);
void	ft_check_fd1(int *fd, char **argv);
void	ft_check_fd2(int *fd, char **argv);
void	ft_remove_char(char *str, char c);

void	ft_error();
void	ft_execute(char *argv, char **envp);
int		ft_open_file(char *argv, int i);


#endif
