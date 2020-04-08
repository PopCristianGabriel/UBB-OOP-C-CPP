#pragma warning(disable : 4996)
#include <stdio.h>
#include <Windows.h>



int is_prime(int number) {
	if (number < 2) {
		return 0;
	}
	if (number == 2) {
		return 1;
	}
	if (!(number % 2)) {
		return 0;
	}
	for (int divisor = 3; divisor * divisor <= number; divisor += 2) {
		if (!(number%divisor)) {
			return 0;
		}
	}
	return 1;
}


int main() {

	char *readString = (char*)malloc(200 * sizeof(char));
	int* userInputs = (int*)malloc(200 * sizeof(int));





	scanf("%99[^\n]s", readString);
	char *digitsAsString = strtok(readString, " ");
	int lengthOfTheInput = 0;
	while (digitsAsString != NULL) {
		userInputs[lengthOfTheInput] = 0;
		for (int j = 0; j < strlen(digitsAsString); j++) {
			userInputs[lengthOfTheInput] = userInputs[lengthOfTheInput] * 10 + (digitsAsString[j] - '0');
		}
		digitsAsString = strtok(NULL, " ");
		lengthOfTheInput++;

	}
	




	int start = 0;
	int finish = 0;
	int currentSequenceLength = 1;
	int maximumSequenceLength = 0;
	int imInSequence = 0;
	int changed = 0;
	for (int i = 1; i < lengthOfTheInput; i++) {
		if (is_prime(userInputs[i] - userInputs[i - 1])) {
			if (imInSequence == 0) {
				changed = 0;
				start = i - 1;
				imInSequence = 1;
			}
			if (imInSequence) {
				currentSequenceLength++;
			}
			if (currentSequenceLength > maximumSequenceLength) {
				maximumSequenceLength = currentSequenceLength;
				changed = 1;
				finish = i;
			}
		}
		else {
			if (imInSequence == 1) {
				imInSequence = 0;
				currentSequenceLength = 0;
				if (changed == 1) {
					finish = i - 1;

				}
				
			}
		}
	}
	
	if(maximumSequenceLength > 0)
	for (int i = start; i <= finish; i++) {
		printf("%d ", userInputs[i]);
		
	}
	free(userInputs);
	free(readString);
	system("pause");

	return 0;
}