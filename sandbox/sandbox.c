#define _GNU_SOURCE

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
bool timedout = 0;

void good_function(void)
{
	return;
}
void bad_function(void)
{
	exit(1);
}

void bad_infinite(void)
{
	while (1)
		;
}
void bad_kill(void)
{
	kill(getpid(), SIGKILL);
}

void signal_handler(int sig)
{
	kill(g_pid, SIGKILL);
	timedout = true;
	(void)sig;
}

int sandbox(void (*f)(void), unsigned int timeout, bool verbose)
{
	struct sigaction sa;
	int status;
	
	g_pid = fork();
	if (g_pid < 0)
		return -1;
	if (g_pid == 0)
	{
		f();
		exit(0);
	}
	sa.sa_handler = signal_handler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGALRM, &sa, NULL);
	alarm(timeout); //
	if (waitpid(g_pid, &status, 0) == -1)
		return (-1);
	alarm(0);
	if (timedout)
	{
		if (verbose)
			printf("Bad function: timed out after %d seconds\n", timeout);
		return 0;
	}
	else if ( WIFEXITED(status))
	{
		if (WEXITSTATUS(status) != 0)
		{
			if (verbose)
				printf("Bad function: exited with code %d\n", WEXITSTATUS(status));
			return (0);
		}
	}
	else if (WIFSIGNALED(status))
	{
		if	(WTERMSIG(status))
		{
			if (verbose)
				printf("Bad function: %s\n", strsignal(WTERMSIG(status)));
			return 0;
		}
	}
	if (verbose)
		printf("Nice function!\n");
	return 0;

	
}

int main(void)
{
	int exitstatus = sandbox(bad_function, 4, true);
	printf("Exit status: %d\n", exitstatus);
}








// {
// 	pid_t pid;
// 	int status;
// 	struct sigaction s;
// 	int exitcode;

// 	pid = fork();
// 	if (pid == -1)
// 		return -1;
// 	g_pid = pid;
// 	if (pid == 0)
// 	{
// 		f();
// 		exit(0);
// 	}
// 	s.sa_handler = signal_handler;
// 	s.sa_flags = SA_RESTART;
// 	if (sigaction(SIGALRM, &s, NULL) < 0)
// 		return (-1);
// 	alarm(timeout);
// 	if (waitpid(pid, &status, 0) == -1)
// 		return (-1);

// 	if (WIFEXITED(status))
// 	{
// 		exitcode = WEXITSTATUS(status);
// 		if (exitcode == 0)
// 		{
// 			if (verbose)
// 				printf("Nice function!\n");
// 			return 1;
// 		}
// 		else
// 		{
// 			if (verbose)
// 				printf("Bad function: exited with code %d\n", exitcode);
// 			return 0;
// 		}
// 	}
// 	if (WIFSIGNALED(status))
// 	{
// 		exitcode = WTERMSIG(status);
// 		if (exitcode == SIGKILL)
// 		{
// 			if (verbose && timeout > 0)
// 				printf("Bad function: timed out after %i seconds\n", timeout);
// 		}
// 		else
// 		{
// 			if (verbose)
// 				printf("Bad function: %s\n", strsignal(exitcode));
// 		}
// 		return 0;
// 	}
// 	return (-1);