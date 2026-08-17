#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//A practice question practicing for question 3 of my upcoming exam
//This question focuses on structs and manual memory allocation

//The title goes up to 127 characters so +1 for '\0'
//Status is actually one of three: checked out, overdue, or returned
//We only need the first letter of status and assign it an int value
//Days late only goes up to 365 so short is the smallest possible
//Borrower is a name and goes up to 31 characters so +1 for '\0'
struct Book {
  char title[128];
  short status; //checked out = 0, overdue = 1, returned = 2
  short days_late;
  char borrower[32];
};

//Reads one line from a FILE f, parses it according to the format above...
//then dynamically allocates a struct Book, initializes it, and returns it.
//We are assuming that the file is well-formed (no formatting errors)
struct Book *parse_book(FILE *f) {
  if(f == NULL) {
    return NULL; //file couldn't be opened
  }
  //128 title + ~8 for status + 31 borrower + 3 commas + 1 newline = 171
  //256 to be safe but 175 could work
  char buf[256];
  //Only reads one line, no loop needed
  fgets(buf, sizeof(buf), f);
  char *titletok = strtok(buf, ",");
  char *statustok = strtok(NULL, ",");
  char *days_latetok = strtok(NULL, ",");
  char *borrowertok = strtok(NULL, "\n");
  
  //Dynamically allocated struct Book to hold our values
  struct Book *b = malloc(sizeof(struct Book));
  if(b == NULL) {
    return NULL; //malloc failed
  }

  strcpy(b->title, titletok);
  
  //Checks the first character of stutus and assigned the set int to the field
  if (statustok[0] == 'c') {
    b->status = 0; 
  }
  else if (statustok[0] == 'o') {
    b->status = 1; 
  }
  else{
    b->status = 2;
  }
  b->days_late = (short)strtol(days_latetok, NULL, 10);
  strcpy(b->borrower, borrowertok);
  return b;
}

//We only need to free what we allocated with malloc or calloc so just b
void destroy_book(struct Book *b) {
  free(b);
}


