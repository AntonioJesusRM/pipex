/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:06:01 by aruiz-mo          #+#    #+#             */
/*   Updated: 2022/09/21 13:20:30 by aruiz-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	t_pipex	p;

	p.index = 1;
	if (argc == 5)
	{
		p.fd_in = open(argv[1], O_RDONLY);
		if (p.fd_in == -1)
			exit (ft_printf(".\n"));
		p.fd_out = open (argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(p.fd_in, STDIN_FILENO);
		pipex_exe(&p, argv[++p.index]);
		dup2(p.fd_out, STDOUT_FILENO);
		child_process(&p, argv[argc - 2]);
	}
	else
		ft_printf("Usage: ./pipex infile command1 command2 outfile \n");
	return (0);
}

void	pipex_exe(t_pipex *p, char *cmmd)
{
	if (pipe(p->pipe_fd) == -1)
		free_all(p, "Error: pipe failure.\n");
	p->pid = fork();
	if (p->pid == -1)
		free_all(p, "Error: pid failure.\n");
	if (p->pid > 0)
	{
		close(p->pipe_fd[1]);
		dup2(p->pipe_fd[0], STDIN_FILENO);
		close(p->pipe_fd[0]);
		dup2(p->fd_out, STDOUT_FILENO);
		waitpid(p->pid, NULL, 0);
	}
	else
	{
		close(p->pipe_fd[0]);
		dup2(p->pipe_fd[1], STDOUT_FILENO);
		close(p->pipe_fd[1]);
		child_process(p, cmmd);
	}
}

void	child_process(t_pipex *p, char *cmmd)
{
	int			i;
	extern char	**environ;

	i = -1;
	p->cmd = ft_split(cmmd, ' ');
	if (**p->cmd == '/' || **p->cmd == '.' || access(*p->cmd, X_OK) == 0)
		p->cmd_path = *p->cmd;
	else
	{
		while (environ[++i])
			if (ft_strncmp("PATH=", environ[i], 5) == 0)
				p->env = ft_substr(environ[i], 5, ft_strlen(environ[i]));
		if (!p->env)
			free_all(p, "Error: Command not found.\n");
		command_path(p);
	}
	execve(p->cmd_path, p->cmd, environ);
}

void	command_path(t_pipex *p)
{
	char	**env;
	char	*tmp2;
	char	*tmp;
	int		i;

	env = ft_split(p->env, ':');
	i = -1;
	tmp = ft_strjoin("/", *p->cmd);
	while (env[++i])
	{
		tmp2 = ft_strjoin(env[i], tmp);
		if (access(tmp2, X_OK) == 0)
			p->cmd_path = ft_strjoin(env[i], tmp);
		else
			free(tmp2);
	}
	if (!p->cmd_path)
		free_all(p, "Error: Command not found.\n");
	free (tmp);
	i = -1;
	while (env[++i])
		free (env[i]);
	free(env);
}

void	free_all(t_pipex *p, char *txt)
{
	int	i;

	i = -1;
	if (p->cmd_path != NULL)
		free (p->cmd_path);
	if (p->cmd != NULL)
	{
		while (p->cmd[++i])
			free (p->cmd[i]);
		free(p->cmd);
	}
	if (p->env != NULL)
		free (p->env);
	if (ft_strncmp(txt, " ", 1))
		ft_putstr_fd(txt, 2);
	exit(1);
}
