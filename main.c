#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	FILE *fp = fopen("data.csv", "r");

	if (!fp) {
		printf("Unable to open file\n");
	} else {
		char buffer[1024];

		int row = 0;
		int col = 0;

		while (fgets(buffer, 1024, fp)) {
			col = 0;
			row++;
			if (row == 1) {
				continue;
			}
			char* value = strtok(buffer, ", ");
			while (value) {
				// column 1
				if (col == 0) {
					printf("Last name : ");
				}
				// col 2
				if (col == 1) {
					printf("\tFirst name : ");
				}
				// col 3
				if (col == 2) {
					printf("\tGender : ");
				}
				// column 4
				if (col == 3) {
					printf("\tAge : ");
				}
				// column 5
				if (col == 4) {
					printf("\tPlace of birth: ");
				}

				printf("%s", value);
				value = strtok(NULL, ", ");
				col++;
			}

			printf("\n");
		}
	}

	// Close the file
	fclose(fp);
	return 0;
}
    