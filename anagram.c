#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//This program is meant to be run in the command line and will not work otherwise!

//An extremely complicated (in my opinion) anagram function that uses various helper functions 
//to determine if the user's input is an anagram.
//This code is taken from a part of a McGill course I completed an is not meant to be a solution for other students, 
//I advise you to attempt it yourself.


//This function ensures that the user input is all lowercase
//Without it, the code wouldn't work if a user inputted an uppercase letter

int is_all_lowercase(char *s)
{
    while (*s) {
        if (!islower((unsigned char)*s)) {
            return 0;
        }
        s++;
    }
    return 1;
}
//This function takes two pointers to char (strings) and makes arrays for the frequency of each string
//Each array has 26 elements for the letters of the alphabet
int is_anagram(char *s1, char *s2) {
    int freq1[26] = {0};
    int freq2[26] = {0};

	//This for loop adds the frequency of each letter in the string to its correct letter spot in the array
	//Example: input = abbccc. The array would look like {1, 2, 3, then 0s until the max of 26 (z) is reached
    
    for (int i = 0; s1[i]; i++) {
	//The condition s1[i] makes sure it stops before the null terminator '\0'
	//This condition is essentially s1[i] != '\0', ending the loop at the end of the string
        freq1[s1[i] - 'a']++;
    }
    for (int i = 0; s2[i]; i++) {
        freq2[s2[i] - 'a']++;
    }
	//Then this loop checks if the frequency of letters in s1 (string 1) is the same as the frequency of letters in s2
    for (int i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i]) {
            return 0;
        }
    }
    return 1;
}

//This function handles the results from the is_anagram function by printing the result the user.
//It also calle ths is_all_lowercase function to make sure the input is in the expected format
//"true" if s1 and s2 are anagrams, and "false" if they are not
int handle_anagram( char *argv[]) {
	if (!is_all_lowercase(argv[2]) || !is_all_lowercase(argv[3])) {
		fprintf(stderr, "Inputs must contain only lowercase letters.\n");
		return 1;
	} 

	if (is_anagram(argv[2], argv[3])) {
                printf("true\n");
        } else {
                printf("false\n");
        }
        return 0;
}

int main(int argc, char *argv[]) {
	//This condition ensures we aren't getting too much information from the user when nothing is happening
	//Otherwise without this, it would lead to a runtime error
	if (argc != 4) {
		fprintf(stderr, "Usage: %s anagram word1 word2\n", argv[0]);
		return 1;
	}
	else if (strcmp(argv[1], "anagram") == 0) { 
		 return handle_anagram(argc, argv);
	} else {
		fprintf(stderr, "unknown operation\n");
		return 1; 
	}
}

//You may notice that I am using input from the commandline instead of scanf like previous programs,
//That is because the beginning of the course focused on bash shell and the command line
//Leading us to adopt some unique methods on reading input other than scanf (argv[i] with i being the order of the input
//Ex: anagram potato tomato -> argv[0] = ./program, argv[1] = anagram, argv[2] = potato, argv[3] = tomato
