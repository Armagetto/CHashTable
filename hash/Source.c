#include "header.h"


int main() {
	
	int c;

	initialize_table();
	print_table();


	user david = { "david",16 };
	user ron = { "ron",11 };
	user amit = { "amit",17 };
	user shimi = { "shimi",10 };

	insert_table(&david);
	insert_table(&ron);
	insert_table(&amit);
	insert_table(&shimi);

	print_table();


	//search test
	if (lookUp("ron") != -1) {
		printf("\nfound\n");
	}
	else
	{
		printf("\nnot found");
	}

	remove_user("ron");
	print_table();

	if (lookUp("ron") != -1) {
		printf("\nfound\n");
	}
	else
	{
		printf("\nnot found");
	}

	if (scanf_s("%d", &c) == NULL) { return 0; }
}