#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void passOne(char label[10], char opcode[10], char operand[10], char code[10], char mnemonic[3]);
void display();
int main()
{
	char label[10], opcode[10], operand[10];
	char code[10], mnemonic[3];
	passOne(label, opcode, operand, code, mnemonic);
	return 0;
}
void passOne(char label[10], char opcode[10], char operand[10], char code[10], char mnemonic[3])
{
	int locctr, start, length;
	FILE *fp1, *fp2, *fp3, *fp4, *fp5;
	fp1 = fopen("input3.txt", "r");
	fp3 = fopen("symtab3.txt", "w");
	fp4 = fopen("intermediate3.txt", "w");
	fp5 = fopen("length3.txt", "w");
	fscanf(fp1, "%s\t%s\t%s", label, opcode, operand);
	if (strcmp(opcode, "START") == 0)
	{
		start = atoi(operand);
		locctr = start;
		fprintf(fp4, "\t%s\t%s\t%s\n", label, opcode, operand);
	}
	else
		locctr = 0;
	fscanf(fp1, "%s\t%s\t%s", label, opcode, operand);
	while (strcmp(opcode, "END") != 0)
	{
		fprintf(fp4, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);
		if (strcmp(label, "**") != 0)
		{
			fprintf(fp3, "%s\t%d\n", label, locctr);
		}
		fp2 = fopen("optab3.txt", "r");
		fscanf(fp2, "%s\t%s", code, mnemonic);
		while (strcmp(code, "END") != 0)
		{
			if (strcmp(opcode, code) == 0)
			{
				locctr += 3;
				break;
			}
			fscanf(fp2, "%s\t%s", code, mnemonic);
		}
		fclose(fp2);
		if (strcmp(opcode, "WORD") == 0)
			locctr += 3;
		else if (strcmp(opcode, "RESW") == 0)
			locctr += (3 * (atoi(operand)));
		else if (strcmp(opcode, "BYTE") == 0)
			{
				if((operand[0]=='C') || (operand[0]=='c'))
					locctr+=strlen(operand)-3;
				else
					locctr+=(strlen(operand)-3)/2;
			}
		else if (strcmp(opcode, "RESB") == 0)
			locctr += (atoi(operand));
		fscanf(fp1, "%s\t%s\t%s", label, opcode, operand);
	}
	fprintf(fp4, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);
	fclose(fp1);
	fclose(fp3);
	fclose(fp4);
	length = locctr - start;
	fprintf(fp5, "%d", length);
	fclose(fp5);
	printf("\nThe length of the code : %d\n", length);
}
