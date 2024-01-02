#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if(argc < 4){
        printf("Program invocation 'program_name operator operand_1 operand_2'\n");
        return EXIT_FAILURE;
    }

    float result = 0;
    char operator = argv[1][0]; // Getting the first character of the second element
    double operand_1 = atof(argv[2]);
    double operand_2 = atof(argv[3]);

    switch (operator)
    {
    case '+':
        result = operand_1 + operand_2;
        break;
    case '-':
        result = operand_1 - operand_2;
        break;
    case 'x':
        result = operand_1 * operand_2;
        break;
    case '/':
        result = operand_1 / operand_2;
        break;
    default:
        printf("The operand wasn not recognized by the program. Please use one of the following operators: +, -, *, or /\n");
        break;
    }

    printf("%.2lf %c %.2lf = %.2f\n", operand_1, operator, operand_2, result);
    return EXIT_SUCCESS;
}