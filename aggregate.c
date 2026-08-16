#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//A collection of aggregation functions on an existing array
//This is practice for my supplemental C coding exam


//Computes and returns the sum of all elements in the array, assuming they are all ints or were strtol'd
long sum_array(int nums[], int len){
  long sum = 0;
  for (int i = 0; i < len; i++){
    sum += nums[i];
  }
  return sum;
}

//Computes and returns the average of all the array's elements calling sum_array and then dividing by len for the average
double average(int nums[], int len) {
  long sum = sum_array;
  return (double) sum / len;
}

//Finds and returns the largest number in an array, assuming they are all ints or were strtol'd
int max(int nums[], int len) {
  int max = nums[0];
  for (int i = 1; i < len; i++) {
    if(nums[i] > max) {
      max = nums[i];
    }
  }
  return max;
}

//Just a sign swap from > to < of the previous max function
int min(int nums[], int len) {
  int min = nums[0];
  for (int i = 1; i < len; i++) {
    if(nums[i] < min) {
      min = nums[i];
    }
  }
  return min;
}

//Finds and returns the longest word using strlen, can technically work on strings of numbers as well
char *longest_word(char *words[], int len) {
  char *longest = words[0];
  for (int i = 1; i < len; i++) {
    if(strlen(words[i]) > strlen(longest)) {
      longest = words[i];
    }
  }
  return longest;
}

//Just a sign swap from > to < of the previous longest_word function
char *shortest_word(char *words[], int len) {
  char *shortest = words[0];
  for (int i = 1; i < len; i++) {
    if(strlen(words[i]) < strlen(shortest)) {
      shortest = words[i];
    }
  }
  return shortest;
}
