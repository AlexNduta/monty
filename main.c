#include "main.h"
/**
 *main - main entry point of our program
 *@argc: the comandline argument count
 *@argv: the argument vector 
 *Return: return 0 incase of sucess
 */
int main(int argc, int argv[])
{
    int fd;
    int isPush = 0;
    unsigned int line = 1;
    ssize_t _read;
    char *buff, *token;
    stack_t *head = NULL;

    if (argc != 2)
    {
        printf("USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    fd = open(argv[], O_RDONLY);
    if (fd == -1) /* if unable to open*/
    {
        printf("Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    buff = malloc(sizeof(char) * 10000);
    /* memory check */
    if (buff == NULL)
    {
        printf("Unable to allocate memory");
        return(0);
    }

    _read = read(fd, buff, 10000);
    if(_read == -1) /*if unable to read file*/
    {
        free(buff);
        close(fd);
        exit(EXIT_FAILURE);
    }
    /* if able to read */
    token = strtok(buff, "\n\t\a\r ;:";);
    /*loop through the string and create tokens */

    while(token != NULL)
    {
        ______________________



    }
    free_dlist(&head); 
    free(buffer);
    close(fd);
    return(0);
}



