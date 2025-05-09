#include <stdbool.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

pid_t g_pid = 0;

void good_function(void)
{
	return;
}

void bad_infinite(void)
{
	while (1)
		;
}

void signal_handler(int sig)
{
	kill(g_pid, SIGKILL);
	(void)sig;
}

int sandbox(void (*f)(void), unsigned int timeout, bool verbose)
{
	pid_t pid;
	int status;
	struct sigaction s;
	int exitcode;

	pid = fork();
	if (pid == -1)
		return -1;
	g_pid = pid;
	if (pid == 0)
	{
		f();
		exit(0);
	}
	s.sa_handler = signal_handler;
	s.sa_flags = SA_RESTART;
	if (sigaction(SIGALRM, &s, NULL) < 0)
		return (-1);
	alarm(timeout);
	if (waitpid(pid, &status, 0) == -1)
		return (-1);

	if (WIFEXITED(status))
	{
		exitcode = WEXITSTATUS(status);
		if (exitcode == 0)
		{
			if (verbose)
				printf("Nice function!\n");
			return 1;
		}
		else
		{
			if (verbose)
				printf("Bad function: exited with code %d\n", exitcode);
			return 0;
		}
	}
	if (WIFSIGNALED(status))
	{
		exitcode = WTERMSIG(status);
		if (exitcode == SIGKILL)
		{
			if (verbose && timeout > 0)
				printf("Bad function: timed out after %i seconds\n", timeout);
		}
		else
		{
			if (verbose)
				printf("Bad function: %s\n", strsignal(exitcode));
		}
		return 0;
	}
	return (-1);
}

int main(void)
{
	int exitstatus = sandbox(bad_infinite, 4, true);
	printf("Exit status: %d\n", exitstatus);
}