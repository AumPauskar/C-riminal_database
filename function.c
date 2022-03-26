#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int fetch() {
	struct data {
		char lname[64];
		char fname[64];
		char gender[64];
		char age[64];
		char pob[64];
	} d[64];

	int row = 0, col = 0;
	int count = 0;
	char buffer[1024];

	FILE *fp = fopen("data.csv", "r");
	if (!fp) {
		printf("Unable to open file\n");
	} else {
		printf("Yea\n");
	}

	char search[64];
	printf("Enter the search term: ");
	scanf("%s", search);

	while (fgets(buffer, 1024, fp)) {
		col = 0;
		row++;
		if (row == 1) {
			continue;
		}

		char* value = strtok(buffer, ", ");

		while (value) {

			value = strtok(NULL, ", ");

			// column 1
			if (col == 0) {
				strcpy(d[count].lname, value);
			}
			// col 2
			if (col == 1) {
				printf(d[count].fname, value);
			}
			// col 3
			if (col == 2) {
				printf(d[count].gender, value);
			}
			// column 4
			if (col == 3) {
				printf(d[count].age, value);
			}
			// column 5
			if (col == 4) {
				printf(d[count].pob, value);
			}

			printf("%s", value);
			col++;
		}
	}
}