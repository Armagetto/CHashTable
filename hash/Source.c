#include "header.h"


int main(int argc, char* argv[]) {

	//get working directory
	char cwd[MAX_DIRECTORY_SIZE];
	if (_getcwd(cwd, sizeof(cwd)) != NULL) {
		printf("Working directory: %s\n", cwd);
	}
	else {
		perror("getcwd() error");
	}
	//crate in working dirctory the paths
	create_new_mul_dir("nano", TABLE_SIZE);

	initialize_table();
	
	FILE* fpointer;
	fopen_s(&fpointer, "data.txt", "r");
	if (fpointer == NULL) {
		printf("File not found!\n");
		return 0;
	}
	
	char line[MAX_NAME];
	char* real_line;
	user* new_user;
	printf("Loading data into ram...\n");
 while (fgets(line, sizeof(line), fpointer)) {

	 fscanf_s(fpointer,"%s",line,_countof(line));
	
	 real_line = (char*)malloc(sizeof(line));
	 if (real_line == NULL) {
		 return 0;
	 }
	 strcpy_s(real_line,sizeof(line),line);
     
	 new_user = (user*)malloc(sizeof(user));
	 if (new_user == NULL) {
		 return 0;
	 }
	 new_user->age = rand()%99+1;
	 new_user->name = real_line;
	 new_user->next = NULL;

	 insert_table(new_user);
    }
	printf("\nDone!\nEnter what to look for (0 to exit): ");

	char to_look_up[MAX_NAME] = {NULL};

	scanf_s("%s", to_look_up, MAX_NAME);

	while (strcmp(to_look_up,"0") != 0 || to_look_up != NULL)
	{
		if (lookUp(to_look_up) >= 0) {
			printf("\n%s was found :)\n", to_look_up);
		}
		else
		{
			printf("\n%s was not found :(\n", to_look_up);
		}
		printf("\nEnter what to look for (0 to exit): ");
		scanf_s("%s", to_look_up, MAX_NAME);
	}
	

	fclose(fpointer);

	return 0;
}