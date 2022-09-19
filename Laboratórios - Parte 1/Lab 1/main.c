#include <stdio.h> 

/*
gcc -c -o main.o  main.c // gcc -c main.c -o main.o
gcc -c -o say.o say.c // gcc -c say.c -o say.o

gcc -o main main.o say.o // gcc main.o say.o -o main

./main
*/


void sayHello();

int main() {
    sayHello();
    return 0; 
}