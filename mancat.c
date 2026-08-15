#include <stdio.h>

//A simple practice function that does the same as cat on the cmd line but written in C code
//Specifically it opens files provided by stdin as command-line arguments and prints the file's contents to stdout

//Intput: stdin which includes argc (number of arguments), and an array of strings with the actual arguments
//Output: printed contents of the argv files to stdout

int man_cat(int argc, char *argv[]) {
	//counter for problems encountered	
	int errors = 0;
	for(int i = 0; i < argc; i++){
		//Turns argv arguments into file pointers for fputs
		FILE *f = fopen(argv[i], "r");
		//Checks to see if the file could be opened read, otherwise increases errors
		if(f == NULL){
			errors++;
		}
		//A classic fgets loop reading the file, but the buffer is for the entire file
		char buf[256];
		while(fgets, (buf, sizeof(buf), f) != NULL) {
			fputs(buf, stdout);
		}
		//MAKE SURE TO CLOSE YOUR FILES!!!
		fclose(f);
	}
	//Returns the number of times a file could not be opened/read
	return errors;
}
