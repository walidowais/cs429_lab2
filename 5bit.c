/*
	Walid Owais
	EID: wo783
	Section: 53845
	Slip day: 1
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
int convert(char c);


FILE * input;


int line_length = 0;

// main function
int main(int argc, char *argv[])
{
	int i;

	if(argc > 1){
		if(!strcmp(argv[1], "-d")){
			// fprintf(stderr, "5bit: decode function not implemented\n");
			if(argc > 2){
				for(i = 2; i < argc; i++){
					input = fopen(argv[i], "r");
					// printfile();
					decode();
				}
			}
			else{
				input = stdin;
				// printfile();
				decode();
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
	int c;

	if(input == NULL){
		fprintf(stderr, "5bit: Can't open file.\n");
		exit(1);
	}
	else{
		while((c = getc(input)) != EOF){
			fprintf(stdout, "%c", c);	
		}
	}
}

void encode(void){
	int c;
	unsigned int q, five;
	int size, mask;

	size = 0;
	mask = 0x1F << ((sizeof(int) * 8) - 5);
	five = 0;
	q = 0;

	if(input == NULL){
		fprintf(stderr, "5bit: Can't open file.\n");
		exit(1);
	}
	else{
		while((c = getc(input)) != EOF){
			// encode process
			// fprintf(stdout, "0x%0x\n", c);
			q += ((unsigned) c) << (((sizeof(int) * 8) - 8) - size);
			// fprintf(stdout, "0x%0x\n", q);
			// fprintf(stdout, "0x%0x\n", (q >> (((sizeof(int)*8)-8)-size)) );

			size = size + 8;

			while(size >= 5){
				five = (mask & q);
				q = q << 5;
				size = size - 5;
				five = five >> ((sizeof(int) * 8) - 5);

				// fprintf(stdout, " -- 0x%0x\n", five);
				write(five);
				
			}

		}
		// fprintf(stdout, "%d_0x%0x\n", size, (q >> ((sizeof(int) * 8) - 5)));
		if(size > 0){
			write(q >> ((sizeof(int) * 8) - 5));
		}
		if(line_length > 0){
			fprintf(stdout, "\n");
		}
	}
}

void decode(void){
	int c;
	int x, size, mask;
	unsigned int q;

	size = 0;
	mask = 0xFF << ((sizeof(int) * 8) - 8);
	x = 0;
	q = 0;

	if (input == NULL){
		fprintf(stderr, "5bit: Can't open file.\n");
	}
	else{
		while((c = getc(input)) != EOF){
			// fprintf(stderr, "%c\n", c);
			x = convert(c);
			// fprintf(stderr, "0x%0x\n", x);

			if(x != -1){
				q += ((unsigned) x) << (((sizeof(int) * 8) - 5) - size);
				size = size + 5;
			}
			// fprintf(stderr, "0x%0x\n", q);

			while(size >= 8){
				x = (mask & q);
				q = q << 8;
				size = size - 8;
				x = x >> ((sizeof(int) * 8) - 8);

				fprintf(stdout, "%c", x);
			}

		}
	}
}

int convert(char c){
	if(c == 'A'){
		return 0x00;
	}
	else if(c == 'B'){
		return 0x01;
	}
	else if(c == 'C'){
		return 0x02;
	}
	else if(c == 'D'){
		return 0x03;
	}
	else if(c == 'E'){
		return 0x04;
	}
	else if(c == 'F'){
		return 0x05;
	}
	else if(c == 'G'){
		return 0x06;
	}
	else if(c == 'H'){
		return 0x07;
	}
	else if(c == 'I'){
		return 0x08;
	}
	else if(c == 'J'){
		return 0x09;
	}
	else if(c == 'K'){
		return 0x0A;
	}
	else if(c == 'L'){
		return 0x0B;
	}
	else if(c == 'M'){
		return 0x0C;
	}
	else if(c == 'N'){
		return 0x0D;
	}
	else if(c == 'O'){
		return 0x0E;
	}
	else if(c == 'P'){
		return 0x0F;
	}
	else if(c == 'Q'){
		return 0x10;
	}
	else if(c == 'R'){
		return 0x11;
	}
	else if(c == 'S'){
		return 0x12;
	}
	else if(c == 'T'){
		return 0x13;
	}
	else if(c == 'U'){
		return 0x14;
	}
	else if(c == 'V'){
		return 0x15;
	}
	else if(c == 'W'){
		return 0x16;
	}
	else if(c == 'X'){
		return 0x17;
	}
	else if(c == 'Y'){
		return 0x18;
	}
	else if(c == 'Z'){
		return 0x19;
	}
	else if(c == '0'){
		return 0x1A;
	}
	else if(c == '1'){
		return 0x1B;
	}
	else if(c == '2'){
		return 0x1C;
	}
	else if(c == '3'){
		return 0x1D;
	}
	else if(c == '4'){
		return 0x1E;
	}
	else if(c == '5'){
		return 0x1F;
	}
	else{
		return -1;
	}
}

void write(unsigned int five){
	// fprintf(stdout, "0x%0x\n", five);
	line_length++;
	if(line_length > 72){
		fprintf(stdout, "\n");
		line_length = 1;
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
		fprintf(stdout, "0");
	}
	else if(five == 0x1B){
		fprintf(stdout, "1");
	}
	else if(five == 0x1C){
		fprintf(stdout, "2");
	}
	else if(five == 0x1D){
		fprintf(stdout, "3");
	}
	else if(five == 0x1E){
		fprintf(stdout, "4");
	}
	else if(five == 0x1F){
		fprintf(stdout, "5");
	}
	else{
		fprintf(stderr, "%s\n", "ERROR: write()");
	}

}
