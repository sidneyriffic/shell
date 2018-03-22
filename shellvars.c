#include "shell.h"
#include "shellvars.h"

ShellVar *special;
ShellVar *vars;

int initsvars(int ac, char **av)
{
	ShellVar *ptr;
	int i = 0;
	char nums[2] = {0, 0};

	/* 0-9, #, $, ?, dash, underscore */
	special = malloc(sizeof(ShellVar) * 15);
	if (special == NULL)
		return (-1);
	special -> val = _strdup("0");
	special -> name = _strdup("?");
	ptr = special + 1;
	special -> next = ptr;
	while (av[i] != NULL)
	{
#ifdef DEBUGMODE
		printf("av[%d]=%s\n", i, av[i]);
#endif
		nums[0] = i + '0';
		ptr -> val = _strdup(av[i]);
		ptr -> name = _strdup(nums);
		ptr -> next = ptr + 1;
		ptr = ptr -> next;
		i++;
	}
	while (i < 10)
	{
		nums[0] = i + '0';
		ptr -> val = _strdup("0");
		ptr -> name = _strdup(nums);
		ptr -> next = ptr + 1;
		ptr = ptr -> next;
		i++;
	}
	ptr -> name = _strdup("$");
	ptr -> val = _strdup("0");
	ptr -> next = ptr + 1;
	ptr = ptr -> next;
	ptr -> name = _strdup("#");
	ptr -> val = _strdup("0");
	ptr -> next = NULL;
	return (0);
}

/* returns original argument if not found */
char *getsvar(char *name)
{
	ShellVar *ptr=special;

	while (ptr != NULL && _strcmp(ptr -> name, name))
	{
#ifdef DEBUGMODE
		printf("Checked .%s. against .%s.\n", name, ptr -> name);
#endif
		ptr = ptr -> next;
	}
	if (ptr != NULL)
	{
#ifdef DEBUGMODE
		printf("Returning special var %s:%s\n", ptr->name, ptr -> val);
#endif
		return (_strdup(ptr -> val));
	}
	ptr = vars;
	while (ptr != NULL && _strcmp(ptr -> name, name))
	{
#ifdef DEBUGMODE
		printf("Checked .%s. against .%s.\n", name, ptr -> name);
#endif
		ptr = ptr -> next;
	}
	if (ptr == NULL)
	{
#ifdef DEBUGMODE
		printf("Var not found %s\n", name);
#endif
		return (name);
	}
#ifdef DEBUGMODE
	printf("Returning var %s\n", ptr -> val);
#endif
	return (_strdup(ptr -> val));
}


int setsvar(char *name, char *val)
{
	ShellVar *ptr = special, *new;

#ifdef DEBUGMODE
	printf("in setsvar, special address: %p\n", special);
	printf("Got %s %s\n", name, val);
#endif
	while (_strcmp(ptr -> name, name) && ptr -> next != NULL)
	{
		ptr = ptr -> next;
	}
	if (!_strcmp(ptr -> name, name))
	{
#ifdef DEBUGMODE
		printf("Setting special %s to %s\n", ptr -> name, val);
		printf("ptr -> val %p\n", ptr->val);
#endif
		free(ptr -> val);
		ptr -> val = _strdup(val);
		return (0);
	}
	ptr = vars;
#ifdef DEBUGMODE
	printf("vars address %p\n", vars);
#endif
	if (ptr == NULL)
	{
#ifdef DEBUGMODE
		printf("Setting new list %s to %s\n", name, val);
#endif
		new = malloc(sizeof(ShellVar));
		if (new == NULL)
			return (-1);
		new -> name = _strdup(name);
		new -> val = _strdup(val);
		new -> next = NULL;
		vars = new;
		return (0);
	}
	while (_strcmp(ptr -> name, name) && ptr -> next != NULL)
		ptr = ptr -> next;
	if (ptr != NULL && !_strcmp(ptr -> name, name))
	{
#ifdef DEBUGMODE
		printf("Setting %s to %s\n", ptr -> name, val);
#endif
		free(ptr -> val);
		ptr -> val = _strdup(val);
	}
	else
	{
#ifdef DEBUGMODE
		printf("Setting new %s to %s\n", name, val);
#endif
		new = malloc(sizeof(ShellVar));
		if (new == NULL)
			return (-1);
		new -> name = _strdup(name);
		new -> val = _strdup(val);
		new -> next = NULL;
		ptr -> next = new;
	}
	return (0);
}


int unsetsvar(char *name)
{
	ShellVar *ptr = vars, *next;

	if (vars == NULL)
		return (0);
	if (ptr -> name == name)
	{
		vars = vars -> next;
		free(ptr -> name);
		free(ptr -> val);
		free(ptr);
		return (0);
	}
	while (ptr -> next != NULL && ptr -> next-> name != name)
		ptr = ptr -> next;
	if (ptr -> next -> name == name)
	{
		next = ptr -> next -> next;
		free(ptr -> next -> name);
		free(ptr -> next -> val);
		free(ptr -> next);
		ptr -> next = next;
	}
	return (0);
}

/*
int aliascmd(char *av[])
{
	AliasData *ptr = alist;
	int i;
	char *name, *val;

#ifdef DEBUGMODE
	printf("av1 %p ptr %p\n", av[1], ptr);
	printf("av1 %s\n", av[1]);
#endif
	if (av[1] == NULL)
	{
		while(ptr != NULL)
		{
			printf("%s=%s\n", ptr -> name, ptr-> val);
			ptr = ptr -> next;

		}
		return (0);
	}
#ifdef DEBUGMODE
	printf("Not blank args\n");
#endif
	for (i = 1; av[i] != NULL; i++)
	{
#ifdef DEBUGMODE
		printf("Setting alias %s\n", av[i]);
#endif
		name = strtok(av[1], "=");
		val = strtok(NULL,"=");
		name = _strdup(name);
		if (name == NULL)
			return (-1);
		val = _strdup(val);
		if (val == NULL)
		{
			free(name);
			return (-1);
		}
		return (setalias(name, val));
	}
	return (1);
}
*/
