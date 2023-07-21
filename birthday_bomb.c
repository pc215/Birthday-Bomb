#include <stdio.h>
#include <stdlib.h>
#include "support.h"
#include "phases.h"

FILE *in_fp;

int main(int argc, char **argv) {
	char *name = "Pranav";
	char *input;

    if (argc == 1) {  
		in_fp = stdin;
    } else if (argc == 2) {
		char *file_name = argv[1];
		in_fp = fopen(file_name, "r");
		if (in_fp == NULL) {
			fprintf(stderr, "%s could not be opened!\n", file_name);
			return EXIT_FAILURE;
		}

	} else {
		fprintf(stderr, "Usage: ./birthday_bomb {psol.txt}\n");
		return EXIT_FAILURE;
	}

	// HAHAHAHA!!! I will destroy her birthday!!!!!!!!
	initialise_bomb(name);


	printf("Phase 1:\n");
	input = read_input(in_fp);
	phase_1(input); // She will never get this....
	phase_defused(); // Oh no, how did you do that???

	printf("Get ready for Phase 2!\n");
	input = read_input(in_fp);
	phase_2(input); // This one is too hard, she can't do it!
	phase_defused(); // Damnit, not this one too!!!

	printf("Last one! Can you get this?\n");
	input = read_input(in_fp);
	phase_3(input); // I can't let her get this one.
	phase_defused(); // How? HOWWWWWWWWWWWW????

	printf("BOMB DEFUSED! You have saved your birthday!!!\n");
	printf("Drat!!! You have got me this time %s, but I won't spare you next time!\n", name);
	// I WILL BE BACKKKKKKKKKKKKKKK

	if (in_fp != NULL) {
		fclose(in_fp);
	}
	return EXIT_SUCCESS;
}
