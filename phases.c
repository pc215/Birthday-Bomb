#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "phases.h"

// Exiting the program when the bomb explodes
void explode_bomb( void ) {
	printf("BOOOOOOOOM! Bomb exploded.\n");
	exit(EXIT_FAILURE);
}

void phase_1(char *input) {
	char *not_passwd = "Janam din ki baddhaiya!";
	if (strcmp(input, not_passwd) != 0) {
		explode_bomb();
	}
	free(input);
}

static void read_six_numbers(char *input, int (*nums)[6]) {
	char *saveptr;
	char *token = strtok_r(input, " ", &saveptr);
	for (int i = 0; i < 6; i++) {
		if (token != NULL) {
			(*nums)[i] = atoi(token);
		} else {
			explode_bomb();
		}

		token = strtok_r(NULL, " ", &saveptr);
	}

	// Making sure only six numbers are entered
	if (token != NULL) {
		explode_bomb();
	}
}

void phase_2(char *input) {
	int nums[6];
	read_six_numbers(input, &nums);
	
	int value = 1;
	for (int i = 0; i < 6; i++) {
		if (value != nums[i]) {
			explode_bomb();
		}
		value *= 4;
	}
	free(input);
}

static int recursive_func(int num) {
	if (num < 0) {
		explode_bomb();
	}

	if (num == 0) {
		return 0;
	}

	return num + recursive_func(num - 2);
}

void phase_3(char *input) {
	int num1, num2;
	const char *format = "%d %d";
	sscanf(input, format, &num1, &num2);
	if (num1 < 5) {
		explode_bomb();
	}

	if (recursive_func(num1) != num2) {
		explode_bomb();
	}
	free(input);
}
