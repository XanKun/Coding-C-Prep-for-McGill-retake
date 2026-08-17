#include <stdio.h>

//Practice for question 2 of the exam, a short coding problem about parsing and command-line arguments

//Parses an array of strings to an array of ints (the array of strings should contain numbers)
//It then checks to max sure it is within the bounds of min a max
int parse_ints_bounded(int len, char *strs[], int nums[], int min, int max) {
  for(int i = 0; i < len; i++) {
    char *endptr;
    int val = strtol(strs[i], &endptr, 10);
    if (endptr == strs[i] || *endptr != '\0') {
      return i;
    }
    if (val > max || val < min) {
      return i; //too big/small
    }
    nums[i] = val;
  }
  return len;
}


//Reads command-lind arguments as ages with the bounds of 0 to 150
//It either prints the error naming the bad argument (not the index) or...
//prints how many ages were correctly parsed and then exits sucessfully.
int main(int argc, char *argv[]) {
  if (argc < 2) {
    return 2; //not enough cmd-line arguments
  }
  int len = argc - 1;
  int nums[len];
  
  int n = parse_ints_bounded(len, argv + 1, nums, 0, 150);
  
  if (n != len) {
    fprintf(stderr, "%s", argv[n+1]);
    return 3;
  }
  else{
    fprintf(stdout, "%d", n);
    return 0;
  }
}
