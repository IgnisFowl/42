/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarie-c2@c1r4p1.42sp.org.br <aarie-c2@c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:03:05 by aarie-c2@c1       #+#    #+#             */
/*   Updated: 2025/01/20 13:11:47 by aarie-c2@c1      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_devurandom_write(char *buffer, ssize_t bytes_read)
{
	int	i;

	i = 0;
	while (i < bytes_read)
	{
		if (!ft_isprint(buffer[i]))
			buffer[i] = '.';
		i++;
	}
	write(STDOUT_FILENO, buffer, bytes_read);
}

int	handle_devurandom(char *argv)
{
	int		input;
	char	buffer[100];
	ssize_t	bytes_read;
	int		i;

	i = 5;
	input = open(argv, O_RDONLY);
	if (input == -1)
		error("Error opening from /dev/urandom");
	while (i--)
	{
		bytes_read = read(input, buffer, sizeof(buffer));
		if (bytes_read > 0)
			handle_devurandom_write(buffer, bytes_read);
		else if (bytes_read == -1)
		{
			close(input);
			error("Error reading from /dev/urandom");
		}
	}
	close(input);
	return (0);
}

void	child_process(char **argv, char **envp, int *fd)
{
	int		input;

	if (ft_strncmp(argv[1], "/dev/urandom", 12) == 0)
		input = handle_devurandom(argv[1]);
	else if (ft_strncmp(argv[1], "/dev/stdin", 10) == 0)
		input = 0;
	else
	{
		input = open(argv[1], O_RDONLY, 0644);
		if (input == -1)
			error("Error opening input file");
	}
	if ((dup2(fd[1], STDOUT_FILENO) == -1))
		error("Error duplicating stdout");
	if ((dup2(input, STDIN_FILENO) == -1))
		error("Error duplicating stdin");
	close(fd[0]);
	close(fd[1]);
	close(input);
	execute(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int	output;

	output = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output == -1)
		error("Error in output file");
	dup2(fd[0], STDIN_FILENO);
	dup2(output, STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	close(output);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	int		status;

	if (argc == 5)
	{
		if (argv[2] == NULL || ft_strlen(argv[2]) == 0)
			error("Invalid first command");
		if (argv[3] == NULL || ft_strlen(argv[3]) == 0)
			error("Invalid second command");
		if (pipe(fd) == -1)
			error("Error in pipe");
		pid1 = fork();
		if (pid1 == -1)
			error("Error in fork");
		if (pid1 == 0)
			child_process(argv, envp, fd);
		waitpid(pid1, &status, 0);
		parent_process(argv, envp, fd);
	}
	else
		error("Pipex usage: ./pipex <file1> <cmd1> <cmd2> <file2>");
	return (0);
}
