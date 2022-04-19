#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *f_inp, *f_optab, *f_symtab, *f_inter;

    f_inp = fopen("input.txt", "r");
    f_optab = fopen("optab.txt", "r");
    f_symtab = fopen("symtab.txt", "w");
    f_inter = fopen("intermediate.txt", "w");

    int locctr = 0, starting_address;

    char label[10], opcode[10], operand[10], opcode_from_optable[10], mnemonic[10];
    fscanf(f_inp, "%s %s %x", label, opcode, &starting_address);
    printf("%s %s %x", label, opcode, starting_address);
    if (strcmp(opcode, "START") == 0)
    {
        locctr = starting_address;
        fprintf(f_inter, "- %s %s %x\n", label, opcode, starting_address);
        fscanf(f_inp, "%s %s %s", label, opcode, operand);
    }
    else
    {
        locctr = 0;
    }
    while (strcmp(opcode, "END") != 0)
    {
        fprintf(f_inter, "%x %s %s %s\n", locctr, label, opcode, operand);

        // check if there is a label
        if (strcmp(label, "-") != 0)
        {
            fprintf(f_symtab, "%s %x\n", label, locctr);
        }

        // search optab for opcode.
        while (!feof(f_optab))
        {
            fscanf(f_optab, "%s %s", opcode_from_optable, mnemonic);
            if (strcmp(opcode, opcode_from_optable) == 0)
            {
                locctr += 3;
                break;
            }
        }

        // else check for WORD, RESW, BYTE, RESB
        if (strcmp(opcode, "WORD") == 0)
            locctr += 3;
        else if (strcmp(opcode, "RESW") == 0)
            locctr += (3 * (atoi(operand)));
        else if (strcmp(opcode, "RESB") == 0)
            locctr += atoi(operand);
        else if (strcmp(opcode, "BYTE") == 0)
        {
            if (operand[0] == 'X')
                locctr++;
            else
            {
                int len = strlen(operand) - 3;
                locctr += len;
            }
        }
        fscanf(f_inp, "%s %s %s", label, opcode, operand);
    }
    // transfer last line to file
    fprintf(f_inter, "- %s %s %s\n", label, opcode, operand);

    int length = locctr - starting_address;
    printf("\nLength: %d", length);

    fclose(f_inp);
    fclose(f_optab);
    fclose(f_symtab);
    fclose(f_inter);

    return 0;
}