#include <string.h>
#include <stdlib.h>
#include "support.h"
#define MAX_INPUT_SIZE 100

void initialise_bomb(char *name) {
	printf("Welcome to my little devilish birthday bomb, %s! BWAHAHAHAHAHHAAHA!!!\n", name);
	printf("You have three phases with which to blow yourself up! Have a nice day!\n");
	printf("BWAHAHAHAHAHAAHAHAHAHA\n");
}

char *read_input(FILE *in_fp) {
	char *line = malloc(MAX_INPUT_SIZE);
	if (fgets(line, MAX_INPUT_SIZE, in_fp) == NULL) {
		fgets(line, MAX_INPUT_SIZE, stdin);
	}
	// Strips new line
	return strtok(line, "\n");
}

void phase_defused( void ) {
	printf("Phase defused!\n\n");
}
