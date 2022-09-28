#include "header.h"

int main(int argc, char* argv[]) {
	initialize_table();
	
	if (argc > 2) {

		//adding new user
		if (strcmp(argv[1],"add") == 0) {
			user* new_user = create_new_user(argv[2], atoi(argv[3]));
				if (new_user != NULL) {
					insert_table(new_user);
					printf("User %s(%d) added! ", new_user->name, new_user->age);
					print_table();
				}
				else
				{
					printf("Adding user failed\n");
				}
				
			
		}
		else if (strcmp(argv[1], "delete") == 0)
		{

		}
		

	//user david = { "david",16,NULL };
	


	return 1;
	}
	else {
		printf("Too few argumants, try again");
		return 0;
	}
}

/*
//printing table 

if (strcmp(argv[1], "print") == 0)
	{
		print_table();
	}

*/