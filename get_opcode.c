#include "monty.h"

#define NUM_INSTRUCTIONS 16

/**
* get_opcode - function to select correct operation function
* @token1: 1st bytecode input (opcode)
* Return: pointer to correct operation function
void (*get_opcode(char *token1))(stack_t **stack, unsigned int line_number)
{
int i;
instruction_t instruction_s[NUM_INSTRUCTIONS] = {
{"pop", pop},
{"pall", pall},
{"pint", pint},
{"swap", swap},
{"add", _add},
{"sub", _sub},
{"mul", _mul},
{"div", _div},
{"mod", _mod},
{"pchar", pchar},
{"pstr", pstr},
{"nop", nop},
{"rotl", rotl},
{"rotr", rotr},
{NULL, NULL}
};

for (i = 0; i < NUM_INSTRUCTIONS; i++)
{
if (strcmp(token1, instruction_s[i].opcode) == 0)
return (instruction_s[i].f);
}

return (NULL);
}
*/



/**
 * get_op_func - function to select correct operation function
 * @token1: 1st bytecode input (opcode)
 * Return: pointer to correct operation function
 */
void (*get_opcode(char *token1))(stack_t **stack, unsigned int line_number)
{
    int i;

    instruction_t instruction_s[NUM_INSTRUCTIONS] = {
        {"pop", pop},
        {"pall", pall},
        {"pint", pint},
        {"swap", swap},
        {"add", _add},
        /*
        {"sub", _sub},
        {"mul", _mul},
        {"div", _div},
        {"mod", _mod},
        {"pchar", pchar},
        {"pstr", pstr},
        {"nop", nop},
        {"rotl", rotl},
        {"rotr", rotr},*/
        {NULL, NULL}
    };

    for (i = 0; i < NUM_INSTRUCTIONS; i++)
    {
        if (strcmp(token1, instruction_s[i].opcode) == 0)
            return instruction_s[i].f;
    }

    return NULL;
}

