#include "header.h"

int main(int argc, char* argv[]) {
	initialize_table();
	
	FILE* fpointer;
	fopen_s(&fpointer, "data.txt", "r");
	if (fpointer == NULL) {
		return 0;
	}
	
	char line[21];
	char* real_line;
	user* new_user;

 while (fgets(line, sizeof(line), fpointer)) {

	 fscanf_s(fpointer,"%s",line,_countof(line));
	
	 real_line = (char*)malloc(sizeof(line));
	 if (real_line == NULL) {
		 return 0;
	 }
	 strcpy_s(real_line,sizeof(line),line);
	 puts(real_line);
	 new_user = (user*)malloc(sizeof(user));
	 if (new_user == NULL) {
		 return 0;
	 }
	 new_user->age = 10;
	 new_user->name = real_line;
	 new_user->next = NULL;

	 insert_table(new_user);
    }

	
	

	print_table();



	fclose(fpointer);

	return 0;
}

/*
while (!feof(fpointer)) {
		fgets(string, 10, fpointer);
		token = strtok_s(string,"\n", &token);
		puts(token);

		new_user = (user*)malloc(sizeof(user));
		if (new_user == NULL) {
			return 0;
		}
		new_user->age = rand() % 99 + 1;
		new_user->name = token;
		new_user->next = NULL;
		insert_table(new_user);
		new_user = NULL;
	}


*/

/*
* fgets(string, 10, fpointer);
	token = strtok_s(string, "\n", &tempo);
		//puts(token);
*/

/*
if (fscanf_s("%s", string) == NULL) {
			return 0;
		}

*/