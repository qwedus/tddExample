#include "c_example.h"

int add_ints(int a, int b) {
  return a + b;
}

int multiply_ints(int a, int b) {
  return a * b;
}

int fizzbuzz(int inputNumber) {
    int result=0;

    if( (inputNumber%15)==0)
    {
        result= 15000; // FizzBuzz
    } else if ( (inputNumber % 3) == 0) {
        result= 300; // Fizz
    } else if( (inputNumber%5)==0)
    {
        result= 500;
    } else 
       return result; // Not Fizz or Buzz
    
}
