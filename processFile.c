#include "monty.h"
/**
*processFile - open, read and tokentinze contents of our file
*@filename: the name of the  file we are supposed to open
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
        free_list(&h);
        free(buffer);
        close(fd);
        exit(EXIT_FAILURE);
    }
    push(&h, line, token);
}
else
{
op_func func = get_opcode(token);
if (func)
{
func(&h, line);
}
else
{
free_list(&h);
printf("L%d: unknown instruction %s\n", line, token);
free(buffer);
close(fd);
exit(EXIT_FAILURE);
}
}
line++;
token = strtok(NULL, "\n\t\a\r ;:");
}
free_list(&h);
free(buffer);
close(fd);
}*/
