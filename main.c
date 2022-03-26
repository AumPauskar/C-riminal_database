#include <stdio.h>
#include "function.c"

int main() {
	char input[64];
	printf("Enter name: ");
	scanf("%s", input);
	fetch(input);
}