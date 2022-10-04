/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:07:08 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/09/21 13:10:02 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "./printf/includes/ft_printf.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

/*Structs*/

typedef struct s_pipex
{
	int		fd_in;
	int		fd_out;
	int		pipe_fd[2];
	int		index;
	pid_t	pid;
	char	*cmd_path;
	char	*env;
	char	**cmd;
}	t_pipex;

/*Functions*/

void	pipex_exe(t_pipex *p, char *cmd);
void	child_process(t_pipex *p, char *cmd);
void	free_all(t_pipex *p, char *txt);
void	command_path(t_pipex *p);
#endif
