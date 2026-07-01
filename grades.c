#include <stdio.h>
#include <stdlib.h>

//A simple function that uses a lot of if statements to determine if the user's input falls within a grade range
const char *grade_checker(int gradeinp) {
	if (gradeinp >= 85) {
		return "You got an A!";
	}
	if (gradeinp >= 80 && gradeinp <= 84) {
		return "You got an A-";
	}
	if (gradeinp >= 75 && gradeinp <= 79) {
		return "You got a B+";
	}
	if (gradeinp >= 70 && gradeinp <= 74) {
		return "You got a B";
	}
	if (gradeinp >= 65 && gradeinp <= 69) {
		return "You got a B-";
	}
	if (gradeinp >= 60 && gradeinp <= 64) {
		return "You got a C+";
	}
	if (gradeinp >= 55 && gradeinp <= 59) {
		return "You got a C and passed!";
	}
	if (gradeinp >= 50 && gradeinp <= 54) {
		return "You got a D and did not pass";
	}
	if (gradeinp >= 0 && gradeinp <= 49) {
		return "You got an F and FAILED";
	}
	return "INVALID";
}

//The main function that takes user input, checks it validity, and uses the grade_checker function to return a letter grade
int main() {
	int gradeinp;

	printf("Enter your percentage grade for a McGill course: ");
	
	if(scanf("%d", &gradeinp) != 1) {
		printf("That was not a valid integer grade!");
		return 1;
	}
	if (gradeinp < 0 || gradeinp > 100) {
		printf("Grade not within the 0 to 100 range!");
		return 1;
	}
	printf("%s\n", grade_checker(gradeinp));
	return 0;
}
