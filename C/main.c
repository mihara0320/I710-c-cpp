#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const bool DEBUG = false;

const char *eventType[4] = { "index", "comma", "value", "semiColon" };

int getNumberOfIndex(const char *file_name) {
	FILE *f = fopen(file_name, "r");

	int numberOfIndex = 0;

	if (f != NULL)
	{
		int c;
		int i = 0;
		
		while ((c = fgetc(f)) != EOF) {
			char *currentEvent = eventType[i];
			if (currentEvent == eventType[0]) {
				numberOfIndex++;
			}
			if (i == 3) {
				i = 0;
			}
			else {
				i++;
			}
		}
		fclose(f);
	}
	return numberOfIndex;
}

int getDifference(int val_1, int val_2) {
	return val_2 - val_1;
}

int main(int argc, char **argv) {

	bool errorOccurred = false;

	char filename[] = "input.txt";

	int indices = getNumberOfIndex(filename);
	DEBUG && printf("Number of indices is: %i\n", indices);

	FILE* file = fopen(filename, "r");

	int *sortedArray = malloc(sizeof(int) * indices * 1);

	if (file != NULL)
	{
		int c;
		int i = 0;
		int indexPointer = 0;

		while ((c = fgetc(file)) != EOF) {
			char *currentEvent = eventType[i];
			int currentValue = c - '0';
			if (currentEvent == eventType[0]) {
				sortedArray[currentValue] = 0; // init index
				indexPointer = currentValue; // save index value
			}
			else if (currentEvent == eventType[2]) {
				sortedArray[indexPointer] = currentValue; // assign value to current index
			}
			
			if (i == 3) {
				i = 0;
			}
			else {
				i++;
			}
		}
		fclose(file);
	}
	if (DEBUG) {
		printf("Index	Value\n");
		for (size_t i = 0; i < indices; i++)
		{
			printf("%i	%i\n", i, sortedArray[i]);
		}
	}

	int *result = malloc(sizeof(int) * (indices-1) * 1);

	for (size_t i = 0; i < indices; i++)
	{
		if (i < indices-1) {
			result[i] = getDifference(sortedArray[i], sortedArray[i + 1]);
		}
	}

	for (size_t i = 0; i < indices-1; i++)
	{
		printf("%i", result[i]);
		(i < indices - 2) && printf(",");
	}

	free(sortedArray);
	free(result);

	return errorOccurred ? (fprintf(stderr, "Something went wrong!\n"), -1): (fprintf(stdout, "\n"), 0);
}