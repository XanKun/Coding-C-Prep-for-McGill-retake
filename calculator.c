#include <stdio.h>
#include <string.h>

//Here are all the functions for each operation, their names are long since div is already a function in stdio.h
//This program is a little over-complication since I wanted to practice passing values instead of just returning them

void add(int x, int y, int *ans) {
	*ans = x + y;
}

void subtract(int x, int y, int *ans) {
	*ans = x - y;
}

void multiply(int x, int y, int *ans) {
	*ans = x * y;
}

void divide(int x, int y, int *ans) {
	*ans = x / y;
}

//This main function takes the user's input and passes it to the appropriate function
//It also checks for unusual input and returns an ERROR if it doesn't seem to fit properly
int main() {
	char str[100];
	int x, y;
	int ans;

	printf("Give an operation (add, subtract, multiply, divide) then two numbers separated by a space below.\n");
	printf("Input: ");

	scanf("%99s %d %d", str, &x, &y);

	if (strcmp(str, "add") == 0) {
		add(x, y, &ans);
	}
	else if (strcmp(str, "subtract") == 0) {
		subtract(x, y, &ans);
	}
	else if (strcmp(str, "multiply") == 0) {
                multiply(x, y, &ans);
	}
	else if (strcmp(str, "divide") == 0) {
//When dividing in C, it's important not to divide by zero because it will cause an error due to undefined behavior!
                if (y == 0) {
			printf("ERROR: cannot divide by zero!\n");
			return 1;
		}
		divide(x, y, &ans);
	}
	else{
		printf("ERROR");
		return 1;
	}
	printf("Answer: %d"\n, ans);
}

