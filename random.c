#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*3. Dice Rolling Simulator

Roll a die many times and count results.

Functions:

int rollDie();
void simulateRolls(int rolls, int counts[]);
void printHistogram(int counts[]);

Output:

1: *****
2: ********
3: ***

*/

int rollDie() {
	int r = rand() % 6 + 1;
	return r;
}

void simulateRolls(int rolls, int counts[]) {
	for(i = 0, i <= rolls, i++) {
		rollDie();
	}
	
}

void printHistogram(int counts[]) {

}


int main(){
	int rolls;
	char *counts[];
	
	srand(time(NULL));

	printf("How many dice do you want to roll: ");
	if(scanf("%d", &rolls) != 1) {
		printf("That was not a valid number!");
		return 1;
	}

	simulateRolls(rolls, counts);

	printHistogram(counts);
	return 0
}
