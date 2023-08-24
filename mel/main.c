#include "monty.h"

/**
 * main - entry into interpreter
 * @argc: argc counter
 * @argv: arguments
 * Return: 0 on success
int main(int argc, char *argv[])
{
	int fd, ispush = 0;
	unsigned int line = 1;
	ssize_t n_read;
	char *buffer, *token;
	stack_t *h = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	buffer = malloc(sizeof(char) * 10000);
	if (!buffer)
		return (0);
	n_read = read(fd, buffer, 10000);
	if (n_read == -1)
	{
		free(buffer);
		close(fd);
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, "\n\t\a\r ;:");
	while (token != NULL)
	{
		if (ispush == 1)
		{
			push(&h, line, token);
			ispush = 0;
			token = strtok(NULL, "\n\t\a\r ;:");
			line++;
			continue;
		}
		else if (strcmp(token, "push") == 0)
		{
			ispush = 1;
			token = strtok(NULL, "\n\t\a\r ;:");
			continue;
		}
		else
		{
			if (get_op_func(token) != 0)
			{
				get_op_func(token)(&h, line);
			}
			else
			{
				free_dlist(&h);
				printf("L%d: unknown instruction %s\n", line, token);
				exit(EXIT_FAILURE);
			}
		}
		line++;
		token = strtok(NULL, "\n\t\a\r ;:");
	}
	free_dlist(&h); free(buffer);
	close(fd);
	return (0);
} */

/*_________________________________________________________________*/
/*#include "monty.h"

typedef void (*op_func)(stack_t **, unsigned int);

void processFile(const char *filename);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    processFile(argv[1]);

    return 0;
}

void processFile(const char *filename) {
    int fd, line = 1;
    ssize_t n_read;
    char *buffer, *token;
    stack_t *h = NULL;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    buffer = malloc(sizeof(char) * 10000);
    if (!buffer) return;

    n_read = read(fd, buffer, 10000);
    if (n_read == -1) {
        free(buffer);
        close(fd);
        exit(EXIT_FAILURE);
    }

    token = strtok(buffer, "\n\t\a\r ;:");
    while (token) {
        if (strcmp(token, "push") == 0) {
            push(&h, line, (token = strtok(NULL, "\n\t\a\r ;:")));
        } else {
            op_func func = get_op_func(token);
            if (func) {
                if (strcmp(token, "push") != 0)
                    func(&h, line);
            } else {
                free_dlist(&h);
                printf("L%d: unknown instruction %s\n", line, token);
                exit(EXIT_FAILURE);
            }
        }
        line++;
        token = strtok(NULL, "\n\t\a\r ;:");
    }

    free_dlist(&h);
    free(buffer);
    close(fd);
}*/

int main(int argc, char *argv[])
{
if (argc != 2)
{
printf("USAGE: monty file\n");
exit(EXIT_FAILURE);
}

processFile(argv[1]);

return (0);
}

void processFile(const char *filename)
{
int fd, line = 1;
ssize_t n_read;
char *buffer, *token;
stack_t *h = NULL;

typedef void (*op_func)(stack_t **, unsigned int);
fd = open(filename, O_RDONLY);
if (fd == -1)
{
printf("Error: Can't open file %s\n", filename);
exit(EXIT_FAILURE);
}
buffer = malloc(sizeof(char) * 10000);
if (!buffer)
{
    perror("Memory allocation error");
    exit(EXIT_FAILURE);
}
n_read = read(fd, buffer, 10000);
if (n_read == -1)
{
    perror("File read error");
free(buffer);
close(fd);
exit(EXIT_FAILURE);
}
token = strtok(buffer, "\n\t\a\r ;:");
while (token)
{
if (strcmp(token, "push") == 0)
{
    token = strtok(NULL, "\n\t\a\r ;:");
    if (!token)
    {
        printf("Ettor: Missing argument for push at line %d\n", line);
        free_dlist(&h);
        free(buffer);
        close(fd);
        exit(EXIT_FAILURE);
    }
    push(&h, line, token);
}
else
{
op_func func = get_op_func(token);
if (func)
{
func(&h, line);
}
else
{
free_dlist(&h);
printf("L%d: unknown instruction %s\n", line, token);
free(buffer);
close(fd);
exit(EXIT_FAILURE);
}
}
line++;
token = strtok(NULL, "\n\t\a\r ;:");
}
free_dlist(&h);
free(buffer);
close(fd);
}
