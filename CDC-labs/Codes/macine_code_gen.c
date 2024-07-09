#include <stdio.h>
#include <string.h>

void generateMachineCode(const char* inputFile, const char* outputFile);

int main() {
    generateMachineCode("input.txt", "output.txt");
    return 0;
}

void generateMachineCode(const char* inputFile, const char* outputFile) {
    FILE *input, *output;
    char op[2], arg1[5], arg2[5], result[5];

    // Open input file for reading
    input = fopen(inputFile, "r");
    if (input == NULL) {
        perror("Error opening input file");
        return;
    }

    // Open output file for writing machine code
    output = fopen(outputFile, "w");
    if (output == NULL) {
        perror("Error opening output file");
        fclose(input);
        return;
    }

    // Read operations and operands from input file until end-of-file
    while (fscanf(input, "%s%s%s%s", op, arg1, arg2, result) == 4) {
        if (strcmp(op, "+") == 0) {
            fprintf(output, "\n MOV R0,%s", arg1);
            fprintf(output, "\n ADD R0,%s", arg2);
            fprintf(output, "\n MOV %s,R0", result);
        }
        else if (strcmp(op, "*") == 0) {
            fprintf(output, "\n MOV R0,%s", arg1);
            fprintf(output, "\n MUL R0,%s", arg2);
            fprintf(output, "\n MOV %s,R0", result);
        }
        else if (strcmp(op, "-") == 0) {
            fprintf(output, "\n MOV R0,%s", arg1);
            fprintf(output, "\n SUB R0,%s", arg2);
            fprintf(output, "\n MOV %s,R0", result);
        }
        else if (strcmp(op, "/") == 0) {
            fprintf(output, "\n MOV R0,%s", arg1);
            fprintf(output, "\n DIV R0,%s", arg2);
            fprintf(output, "\n MOV %s,R0", result);
        }
        else if (strcmp(op, "=") == 0) {
            fprintf(output, "\n MOV R0,%s", arg1);
            fprintf(output, "\n MOV %s,R0", result);
        }
        else {
            fprintf(stderr, "Invalid operation: %s\n", op);
            continue;
        }
    }

    // Close files
    fclose(input);
    fclose(output);
}
