#include "shell.h"
/**
 * help - help builtin command
 * @cmd: if command matches a builtin name, text file is sent to stdout
 * Return: 0 if sucess
 */
int help(char *cmd)
{
	char *file;
	int total = 0;
	int w = 0;
	int fd, r;
	char *s;

	if (!_strcmp(cmd, "cd"))
	{
		file = "help_cd";
		fd = open(file, O_RDWR);
		s = malloc(256);
		if (s == NULL)
			return (-1);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
			if  (r == -1)
			{
				return (-1);
			}
		}
		free(s);
		fd = close(fd);
		return (0);
	}
	else if (!_strcmp(cmd, "history"))
	{
		file = "help_hist";
		fd = open(file, O_RDWR);
		s = malloc(256);
		if (s == NULL)
			return (-1);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
			if  (r == -1)
			{
				return (-1);
			}
		}
		free(s);
		fd = close(fd);
		return (0);
	}
	else if (!_strcmp(cmd, "help"))
	{
		file = "help_hel";
		fd = open(file, O_RDWR);
		s = malloc(256);
		if (s == NULL)
			return (-1);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
			if  (r == -1)
			{
				return (-1);
			}
		}
		free(s);
		fd = close(fd);
		return (0);
	}
	else if (!_strcmp(cmd, "alias"))
	{
		file = "help_al";
		fd = open(file, O_RDWR);
		s = malloc(256);
		if (s == NULL)
			return (-1);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
			if  (r == -1)
			{
				return (-1);
			}
		}
		free(s);
		fd = close(fd);
		return (0);
	}
	else if (!_strcmp(cmd, "unset"))
	{
		file = "help_unset";
		fd = open(file, O_RDWR);
		s = malloc(256);
		if (s == NULL)
			return (-1);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
			if  (r == -1)
			{
				return (-1);
			}
		}
		free(s);
		fd = close(fd);
		return (0);
	}
	else if (!_strcmp(cmd, "unalias"))
	{
		file = "help_unal";
		fd = open(file, O_RDWR);
		s = malloc(256);
		if (s == NULL)
			return (-1);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
			if  (r == -1)
			{
				return (-1);
			}
		}
		free(s);
		fd = close(fd);
		return (0);
	}
	else if (!_strcmp(cmd, "env"))
	{
		file = "help_env";
		fd = open(file, O_RDWR);
		s = malloc(256);
		if (s == NULL)
			return (-1);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
			if  (r == -1)
			{
				return (-1);
			}
		}
		free(s);
		fd = close(fd);
		return (0);
	}
	else if (!_strcmp(cmd, "unsetenv"))
	{
		file = "help_unenv";
		fd = open(file, O_RDWR);
		s = malloc(256);
		if (s == NULL)
			return (-1);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
			if  (r == -1)
			{
				return (-1);
			}
		}
		free(s);
		fd = close(fd);
		return (0);
	}
	else if (!_strcmp(cmd, "setenv"))
	{
		file = "help_setenv";
		fd = open(file, O_RDWR);
		s = malloc(256);
		if (s == NULL)
			return (-1);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
			if  (r == -1)
			{
				return (-1);
			}
		}
		free(s);
		fd = close(fd);
		return (0);
	}
	else
	{
		s = "help: no help topics match.\n";
		r = _strlen(s);
		w = write(1, s, r);
		return (0);
	}
}
