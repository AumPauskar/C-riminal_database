// importing all the libraries
#include <stdio.h>
#include "function.c"

// the user will pass an argument to another function
int main() {
	char input[64];
	printf("Enter name: ");
	scanf("%s", input);
	fetch(input);
}