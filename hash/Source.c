#include "header.h"

int main(int argc, char* argv[]) {
	unsigned int operation_status = 0;
	initialize_table();
	print_table();

	user david = { "david",16,NULL };
	user ron = { "ron",11,NULL };
	user amit = { "amit",17,NULL };
	user shimi = { "shimi",10,NULL };

	insert_table(&david);
	print_table();

	insert_table(&ron);

	print_table();


	insert_table(&amit);
	print_table();


	insert_table(&shimi);
	print_table();
	
	remove_user("shimi");
	print_table();


	//search test
	if (lookUp("david") != -1) {
		printf("\nfound\n");
	}
	else
	{
		printf("\nnot found");
	}




	operation_status = 1;

	if (operation_status == 0) {
		return 0;
	}
	else
	{
		return 1;
	}

}