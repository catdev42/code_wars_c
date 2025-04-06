#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <unistd.h>

int	picoshell(char **cmds[]);

int	picoshell(char **cmds[])
{
	int		i;
	pid_t	pid;
	int		status;
	int		pipefd[2];

	i = 0;
	while (cmds[i + 1])
	{
		if (pipe(pipefd) < 0)
			return (1);
		if ((pid = fork()) == -1)
			return (-1);
		if (pid == 0)
		{
			close(pipefd[0]);
			dup2(pipefd[1], 1);
			close(pipefd[1]);
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		close(pipefd[0]);
		wait(&status);
		i++;
	}
	if ((pid = fork()) == -1)
		return (-1);
	if (pid == 0)
	{
		execvp(cmds[i][0], cmds[i]);
		exit(1);
	}
 wait(&status);
	return 0;
}

int	main(int argc, char **argv)
{
	int cmds_size = 1;
	char ***cmds = NULL;
	int ret;

	// count pipes to deduce how many ***cmds, then malloc
	for (int i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i], "|"))
			cmds_size++;
	}
	cmds = calloc(cmds_size + 1, sizeof(char **));
	if (!cmds)
	{
		dprintf(2, "Malloc error: %m\n");
		return (1);
	}
	cmds[cmds_size] = NULL;

	cmds[0] = argv + 1;
	int cmds_i = 1;
	for (int i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i], "|"))
		{
			cmds[cmds_i] = argv + i + 1;
			argv[i] = NULL;
			cmds_i++;
		}
	}
	ret = picoshell(cmds);
	if (ret)
		perror("picoshell");
	free(cmds);
	return (ret);
}