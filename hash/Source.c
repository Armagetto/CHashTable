#include "header.h"

int main(int argc, char* argv[]) {
	initialize_table();
	
	//test
	user a = { "a",16,NULL };
	user b = { "b",16,NULL };
	user c = { "c",16,NULL };
	user d = { "d",16,NULL };
	user e = { "e",16,NULL };
	user f = { "f",16,NULL };
	user g = { "g",16,NULL };
	user h = { "h",16,NULL };
	user i = { "i",16,NULL };
	user j = { "j",16,NULL };
	
	insert_table(&a);
	insert_table(&b);
	insert_table(&c);
	insert_table(&d);
	insert_table(&e);
	insert_table(&f);
	insert_table(&g);
	insert_table(&h);
	insert_table(&i);
	insert_table(&j);
	
	print_table();
}

//for argv,argc

/*
//printing table 

if (strcmp(argv[1], "print") == 0)
	{
		print_table();
	}

*/

/*
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

*/