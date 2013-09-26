/*
	Walid Owais
	EID: wo783
	Section: 53845

	5bit -- translates binary Linux file into just "A-Z" and "0-5"

*/

#include <stdio.h>
#include <stdlib.h>

FILE * input;

void printfile(void){
	unsigned int c;

	if(input == NULL){
		fprintf(stderr, "5bit: Can't open file.\n");
		exit(1);
	}
	while((c = getc(input)) != EOF){
		fprintf(stdout, "%c", c);
	}
}

int main(int argc, char *argv[])
{
	int i;

	if(argc > 1){
		if(!strcmp(argv[1], "-d")){
			fprintf(stderr, "5bit: decode function not implemented\n");
			if(argc > 2){
				for(i = 2; i < argc; i++){
					//decode(input)
					fprintf(stdout, "%s\n", argv[i]);
					input = fopen(argv[i], "r");
					printfile();
				}
			}
			else{
				fprintf(stderr, "5bit: decode function not implemented\n");
				input = stdin;
				//decode();
				printfile();
			}
		}
		else{
			fprintf(stderr, "5bit: encode function not implemented\n");
			for(i = 1; i < argc; i++){
				//encode(input)
				fprintf(stdout, "\n--------%s\n", argv[i]);
				input = fopen(argv[i], "r");
				printfile();
			}
		}
	}
	else{
		fprintf(stderr, "5bit: decode function not implemented\n");
		input = stdin;
		//encode(input);
		printfile();
	}

	return 0;
}
