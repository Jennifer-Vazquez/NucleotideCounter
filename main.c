/*
 ============================================================================
 Name        : JVazquezNucleotideCounter.c
 Author      : Jennifer Vazquez
 Version     :
 Copyright   : 
 Description : Nucleotide Counter, Counts the number of As,Cs,Gs,Ts for each line
 of the inputed text then writes the results to a file
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	char inFilename[BUFSIZ];
	char outFilename[BUFSIZ];


	puts("Enter input filename:");
	fgets(inFilename, BUFSIZ, stdin);
	puts("Enter output filename:");
	fgets(outFilename, BUFSIZ, stdin);

	/*get rid of newline character*/
	int lengthInFile = strlen(inFilename);
	inFilename[lengthInFile - 1] = '\0';

	int lengthOutFile = strlen(outFilename);
	outFilename[lengthOutFile - 1] = '\0';

	/*creates file pointer*/
	FILE *pIn = fopen(inFilename, "r");
	FILE *pOut = fopen(outFilename, "w"); /*creates a file to write to*/

	/*reads file*/
	if (pIn != NULL) { /*makes sure the user did not put in a nonexistent file*/
		char myChar;
		 int countA = 0;
		 int countC = 0;
		 int countG = 0;
		 int countT = 0;
		while (!feof(pIn)) { /*keep iterating until the end of the file is reached*/
			myChar = fgetc(pIn);
			switch (myChar) {
			case 'A':
				countA++;
				break;
			case 'C':
				countC++;
				break;
			case 'G':
				countG++;
				break;
			case 'T':
				countT++;
				break;
			case '\n': /*if it comes across a new line character, make sure to write the number of As, Cs, Gs,Ts for that line and reset the counter for next line*/
				fprintf(pOut, " %d %d %d %d\n", countA, countC, countG, countT);
				countA = 0;
				countC = 0;
				countG = 0;
				countT = 0;
				break;
			}

		}

	}
	fclose(pIn);
	fclose(pOut);
	printf("Complete\n");
	return EXIT_SUCCESS;
}
