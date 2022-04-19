#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *f_inter, *f_optab, *f_symtab, *f_obj;
    f_inter = fopen("intermediate.txt", "r");
    f_obj = fopen("object_code.txt", "w");
    int length = 0x0012;
    int locctr, starting_address;
    char label[10], opcode[10], operand[10], blank[10];
    fscanf(f_inter, "%s %s %s %x", blank, label, opcode, &starting_address);
    fprintf(f_obj, "H %s %x %x\n", label, starting_address, length);
    fprintf(f_obj, "T %x 09", starting_address);
    fscanf(f_inter, "%x %s %s %s", &locctr, label, opcode, operand);
    // printf("here");
    while (!feof(f_inter))
    {
        // search optab for opcode
        char optab_opcode[10], symtab_label[10], text[20];
        int hexcode, sym_address;
        int found = 0;
        strcpy(text, "");
        f_optab = fopen("optab.txt", "r");
        while (!feof(f_optab))
        {
            fscanf(f_optab, "%s %x", optab_opcode, &hexcode);
            if (strcmp(optab_opcode, opcode) == 0)
            {
                found = 1;
                // search symtab for symbol
                f_symtab = fopen("symtab.txt", "r");
                while (!feof(f_symtab))
                {
                    fscanf(f_symtab, "%s %x", symtab_label, &sym_address);
                    if (strcmp(symtab_label, operand) == 0)
                    {
                        fprintf(f_obj, " %x%x", hexcode, sym_address);
                        break;
                    }
                }
                break;
            }
        }
        if (found == 0)
        {
            if (strcmp(opcode, "WORD") == 0 || strcmp(opcode, "BYTE") == 0)
            {
                int value = atoi(operand);
                fprintf(f_obj, "%x ", value);
            }
        }
        fscanf(f_inter, "%x %s %s %s", &locctr, label, opcode, operand);
    }
    // printf("here again");
    fprintf(f_obj, "\nE 001000");
    return 0;
}