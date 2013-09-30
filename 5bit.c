/*
	Walid Owais
	EID: wo783
	Section: 53845

	5bit -- translates binary Linux file into just "A-Z" and "0-5"

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

// function prototypes
void printfile(void);
void encode(void);
void decode(void);
void write(unsigned int five);
void print_binary(unsigned int x);


FILE * input;


int char_count = 0;

// main function
int main(int argc, char *argv[])
{
	int i;

	if(argc > 1){
		if(!strcmp(argv[1], "-d")){
			fprintf(stderr, "5bit: decode function not implemented\n");
			if(argc > 2){
				for(i = 2; i < argc; i++){
					input = fopen(argv[i], "r");
					printfile();
					// decode()
				}
			}
			else{
				input = stdin;
				printfile();
				//decode();
			}
		}
		else{
			// fprintf(stderr, "5bit: encode function not implemented\n");
			for(i = 1; i < argc; i++){
				input = fopen(argv[i], "r");
				// printfile();
				encode();
			}
		}
	}
	else{
		// fprintf(stderr, "5bit: encode function not implemented\n");
		input = stdin;
		// printfile();
		encode();
	}

	return 0;
}

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
	int c;
	unsigned int q, five;
	int size, i, mask;

	size = 0;
	mask = 0x1F << ((sizeof(int) * 8) - 5);
	five = 0;

	if(input == NULL){
		fprintf(stderr, "5bit: Can't open file.\n");
		exit(1);
	}
	else{
		while((c = getc(input)) != EOF){
			// fprintf(stdout, "0x%0x\n", c);
			q += ((unsigned) c) << (((sizeof(int) * 8) - 8) - size);
			// fprintf(stdout, "0x%0x\n", (q >> (((sizeof(int)*8)-8)-size)) );

			size = size + 8;

			while(size >= 5){
				five = (mask & q);
				q = q << 5;
				size -= 5;
				five = five >> ((sizeof(int) * 8) - 5);

				// fprintf(stdout, " -- 0x%0x\n", five);
				write(five);
				
			}

		}
		// fprintf(stdout, "%d_0x%0x\n", size, (q >> ((sizeof(int) * 8) - 5)));
		write(q >> ((sizeof(int) * 8) - 5));
	}
}

void decode(void){
	int c;

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

void write(unsigned int five){
	// fprintf(stdout, "0x%0x\n", five);
	char_count++;
	if(char_count > 72){
		fprintf(stdout, "\n");
	}

	// fprintf(stdout, "0x%0x\n", five);
	if(five == 0x0){
		fprintf(stdout, "A");
	}
	else if(five == 0x1){
		fprintf(stdout, "B");
	}
	else if(five == 0x2){
		fprintf(stdout, "C");
	}
	else if(five == 0x3){
		fprintf(stdout, "D");
	}
	else if(five == 0x4){
		fprintf(stdout, "E");
	}
	else if(five == 0x5){
		fprintf(stdout, "F");
	}
	else if(five == 0x6){
		fprintf(stdout, "G");
	}
	else if(five == 0x7){
		fprintf(stdout, "H");
	}
	else if(five == 0x8){
		fprintf(stdout, "I");
	}
	else if(five == 0x9){
		fprintf(stdout, "J");
	}
	else if(five == 0xA){
		fprintf(stdout, "K");
	}
	else if(five == 0xB){
		fprintf(stdout, "L");
	}
	else if(five == 0xC){
		fprintf(stdout, "M");
	}
	else if(five == 0xD){
		fprintf(stdout, "N");
	}
	else if(five == 0xE){
		fprintf(stdout, "O");
	}
	else if(five == 0xF){
		fprintf(stdout, "P");
	}
	else if(five == 0x10){
		fprintf(stdout, "Q");
	}
	else if(five == 0x11){
		fprintf(stdout, "R");
	}
	else if(five == 0x12){
		fprintf(stdout, "S");
	}
	else if(five == 0x13){
		fprintf(stdout, "T");
	}
	else if(five == 0x14){
		fprintf(stdout, "U");
	}
	else if(five == 0x15){
		fprintf(stdout, "V");
	}
	else if(five == 0x16){
		fprintf(stdout, "W");
	}
	else if(five == 0x17){
		fprintf(stdout, "X");
	}
	else if(five == 0x18){
		fprintf(stdout, "Y");
	}
	else if(five == 0x19){
		fprintf(stdout, "Z");
	}
	else if(five == 0x1A){
		fprintf(stdout, "1");
	}
	else if(five == 0x1B){
		fprintf(stdout, "2");
	}
	else if(five == 0x1C){
		fprintf(stdout, "3");
	}
	else if(five == 0x1D){
		fprintf(stdout, "4");
	}
	else if(five == 0x1E){
		fprintf(stdout, "5");
	}
	else{
		fprintf(stderr, "%s\n", "ERROR: write()");
	}

}