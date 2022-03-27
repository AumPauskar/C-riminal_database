// importing stuff
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// the function
int fetch(char arg[]) {

	// --------------------
	// storing algorithm
	// creating a structure that stores all the data
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


	while (fgets(buffer, 1024, fp)) {
		col = 0;
		row++;
		if (row == 1) {
			continue;
		}

		char* value = strtok(buffer, ",");

		while (value) {

			if (col == 0) {
				strcpy(d[count].lname, value);
			} else if (col == 1) {
				strcpy(d[count].fname, value);
			} else if (col == 2) {
				strcpy(d[count].gender, value);
			} else if (col == 3) {
				strcpy(d[count].age, value);
			} else if (col == 4) {
				strcpy(d[count].pob, value);
			}

			value = strtok(NULL, ",");
			col++;
		}
		count++;
	}

	// storing algorithm ends
	// --------------------

	// --------------------
	// searching algorithm starts
	int index = 0;
	for (int i = 0; i < count; i++) {
		if (strcmp(arg, d[i].lname) == 0) {
			index = i;
			break;
		}
	}

	printf("Last name:\t%s\n", d[index].lname);
	printf("First name:\t%s\n", d[index].fname);
	printf("Gender:\t\t%s\n", d[index].gender);
	printf("Age:\t\t%s\n", d[index].age);
	printf("Birth:\t\t%s\n", d[index].pob);

}