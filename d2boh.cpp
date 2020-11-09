// d2boh.cpp

#include <iostream>
#include "d2boh.h"
using namespace std;
int all(int input, char output[10], int num) {
  int reverse[10]; 
  int n = 0;         
  while (input > 0){
    reverse[n] = input % num;  
    input = input / num;
    n++;
  }
  for (int j = n - 1; j >=0; j--)  
    output[n - 1 - j] = '0' + reverse[j];
  return n;
}

int decimal_to_binary(int input, char output[10]) {
  return all(input,output,2);
}


int decimal_to_octal(int input, char output[10]) {
  return all(input,output,8);
}


int decimal_to_hexadecimal(int input, char output[10]) {
  char reverse[10];   //char array to store hexadecimal number
  int i = 0;          //couter for hexadecimal array
  while (input != 0){
    int store = 0;    //temporary storage for remainder
    store = input % 16;
    if (store < 10){
      reverse[i] = store + 48;
      i++;
    }
    else{
      reverse[i] = store + 55;
      i++;
    }
    input = input / 16;
  }
  for (int j = i - 1; j >= 0; j--)
    output[i - 1- j] = reverse[j];    
  return i;
}
