#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*3. Dice Rolling Simulator

Roll a die many times and count results.

Expected Output:

1: *****
2: ********
3: ***
ETC...

*/

//The function that returns a random number between 1 and 6
int rollDie() {
	int r = rand() % 6 + 1;
	return r;
}

//This function runs the rollDie function the ammount of times selected by the user
//It then fills the array with the number of times each side was rolled
//This was a little weird since arrays start at 0 instead of 1 needing us to do an r-1 to get the correct values
void simulateRolls(int rolls, int counts[]) {
	int i;
	for(i = 0; i < rolls; i++) {
		int r = rollDie();
		counts[r - 1]++;
	}
}

//This function uses the array counts[] filled out by simulateRolls to print a visual graphic of the dice rolls
//It runs a nested loop that first prints the dice number 1-6 with a semicolon, then runs another loop
//The nested loop prints a number of *'s equal to the value within the counts[] array
//Finally a newline is created at the end of every number's *'s to make it easy to view and understand
void printHistogram(int counts[]) {
	int i;
	int j;
	for(i = 0; i < 6; i++) {
		printf("%d: ", i+1);
		for(j = 0; j < counts[i]; j++) {
			printf("*");
		}
		printf("\n");
	}
}

//The main function initalizes function rolls and initialized the counts[] array to all 0's
//It then asks and checks the user for input, then calls the designated functions above
int main(){
	int rolls;
	int counts[6] = {0};
	
	srand(time(NULL));

	printf("How many dice do you want to roll: ");
	if(scanf("%d", &rolls) != 1) {
		printf("That was not a valid number!");
		return 1;
	}

	simulateRolls(rolls, counts);

	printHistogram(counts);
	return 0;
}

//I'm hoping to improve the code later allowing the user to change the number of faces on a die (d4, d8, d12, d20, etc)
//I also want to try making it roll 2 dice at a time which would involve even more computations to, in the long run, achieve a decent bell curve
