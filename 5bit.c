/*
	Walid Owais
	EID: wo783
	Section: 53845

	5bit -- translates binary Linux file into just "A-Z" and "0-5"

*/

#include <stdio.h>
#include <stdlib.h>

FILE * input;

// pre: input is initialized to file
void printfile(void){
	unsigned int c;

	if(input == NULL){
		fprintf(stderr, "5bit: Can't open file.\n");
		exit(1);
	}
	else{
		while((c = getc(input)) != EOF){
			fprintf(stdout, "0x%c", c);	
		}
	}
}

void encode(void){
	unsigned int c;

	if(input == NULL){
		fprintf(stderr, "5bit: Can't open file.\n");
		exit(1);
	}
	else{
		while((c = getc(input)) != EOF){
			// encoding process
		}
	}
}

void decode(void){
	unsigned int c;

	if (input == NULL){
		fprintf(stderr, "5bit: Can't open file.\n");
		exit(1);
	}
	else{
		while((c = getc(input)) != EOF){
			// decoding process
		}
	}
}

// main function
int main(int argc, char *argv[])
{
	int i;

	if(argc > 1){
		if(!strcmp(argv[1], "-d")){
			fprintf(stderr, "5bit: decode function not implemented\n");
			if(argc > 2){
				for(i = 2; i < argc; i++){
					// decode()
					// fprintf(stdout, "%s\n", argv[i]);
					input = fopen(argv[i], "r");
					printfile();
				}
			}
			else{
				input = stdin;
				//decode();
				printfile();
			}
		}
		else{
			fprintf(stderr, "5bit: encode function not implemented\n");
			for(i = 1; i < argc; i++){
				// encode()
				// fprintf(stdout, "\n--------%s\n", argv[i]);
				input = fopen(argv[i], "r");
				printfile();
			}
		}
	}
	else{
		fprintf(stderr, "5bit: encode function not implemented\n");
		input = stdin;
		// encode();
		printfile();
	}

	return 0;
}
