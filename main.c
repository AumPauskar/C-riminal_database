#include <stdio.h>

int main() {
	FILE *fp = fopen("data.csv", "r");
	fgetc(fp);
	ftell(fp);
	return 0;

}