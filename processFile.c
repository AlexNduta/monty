void processFile(const char *filename) {
int fd, line = 1;
ssize_t n_read;
char *buffer, *token;
stack_t *h = NULL;

typedef void (*op_func)(stack_t **, unsigned int);
/* file operation */
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
/* tokenise string */
token = strtok(buffer, "\n\t\a\r ;:");
while (token) {
if (strcmp(token, "push") == 0) {
push(&h, line, (token = strtok(NULL, "\n\t\a\r ;:")));
} else {
op_func func = get_opcode(token);
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
}
