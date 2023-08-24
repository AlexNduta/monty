#include "monty.h"
/**
 *main - main entry point of our program
 *@argc: argument count
 *@argv: argument vector
 *Return: zero in successful
 */
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
