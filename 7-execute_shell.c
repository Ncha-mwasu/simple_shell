#include "shell.h"

/**
 * execute_shell - functions that initiates and controls shell execution.
 * @command: double pointer to the command inputed.
 * @cmd_type: checks the command type.
 *
 * Return: returns commands, type.
 */
void execute_shell(char **command, int cmd_type)
{
	int status;
	pid_t MyPid;

	if (cmd_type == EXTERNAL_CMD || cmd_type == PATH_CMD)
	{
		MyPid = fork();

		if (MyPid == 0)
		{
			execute(command, cmd_type);
		}

		if (MyPid < 0)
		{
			perror("failed to fork");
			exit(1);
		}

		else
			wait(&status);
	}

	else
		execute(command, cmd_type);
}

/**
 * check_command - detects the type of command and format of input.
 * @command: the inputted command.
 *
 * Return: returns the type of command.
 */
int check_command(char *command)
{
	int i = 0;
	char *int_cmd[] = {"exit", "cd", "env", NULL};

	while (command[i])
	{
		if (command[i] == '/')
			return (EXTERNAL_CMD);
		i++;
	}

	i = 0;

	while (int_cmd[i] != NULL)
	{
		if (_strcmp(command, int_cmd[i]) == 0)
			return (INTERNAL_CMD);
		i++;
	}
	return (INVALID_CMD);
}

/**
 * execute - execute function.
 * @commands: pointer to commands.
 * @cmd_type: command type.
 *
 * Return: no return.
 */
void execute(char **commands, int cmd_type)
{
	void (*func)(char **command);

	switch (cmd_type)
	{
		case EXTERNAL_CMD:
			{
				if (execve(commands[0], commands, NULL) == -1)
				{
					perror(_getenv("PWD"));
					exit(2);
				}
				break;
			}
		case INTERNAL_CMD:
			{
				func = _getfunc(commands[0]);
				func(commands);
				break;
			}
		case PATH_CMD:
			{
				break;
			}
		case INVALID_CMD:
			{
				break;
			}
	}
}

