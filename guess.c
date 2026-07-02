#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//This function compares the user's input guess to the randomly generated number r 
//It also keeps track of how many guesses it took to get it right
void under_over(int r, int guess) {
	//Count starts at 1 since it only adds when a wrong answer is made, number of wrong + correct = total guesses
	int count = 1;
	while (guess != r) {
		if (guess > r) {
			printf("Too high! Try again!\n");
			count++;
		}
		else {
			printf("Too low! Try again!\n");
			count++;
		}

		printf("Enter a guess for a number between 1 and 100: ");
		scanf("%d", &guess);
	}
	printf("The number was %d! You got it in %d tries! Good job!\n", r, count);
}

//This main function sets the random number r using the current time as a seed, checks the user's input to ensure it is correct
//It then calls the over_under function 
int main() {
	srand(time(NULL));
	int r = rand() % 100 + 1;
	int guess;

	printf("Enter a guess for a number between 1 and 100: ");
	while (scanf("%d", &guess) != 1 || (guess < 0 || guess > 100)) {
		printf("Invalid, input must be a number between 1 and 100, try again\n");
		printf("Enter a guess for a number between 1 and 100: ");
	}
	
	under_over(r, guess, count);
	return 0;
}
