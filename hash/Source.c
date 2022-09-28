#include "header.h"

int main(int argc, char* argv[]) {
	unsigned int operation_status = 0;
	initialize_table();
	print_table();

	user david = { "david",16,NULL };
	user ron = { "ron",11,NULL };
	user amit = { "amit",17,NULL };
	user shimi = { "shimi",10,NULL };
	user nevo = { "nevo",12,NULL };
	user sharon = { "sharon",22,NULL };
	user almog = { "almog",32,NULL };
	user bibi = { "bibi",32,NULL };
	user mi = { "mi",31,NULL };
	user hdidi = { "hdidi",32,NULL };
	user zasdsidi = { "zasdsidi",32,NULL };
	user a = { "a",32,NULL };
	user b = { "b",32,NULL };
	user c = { "c",32,NULL };
	user d = { "d",32,NULL };
	user e = { "e",32,NULL };
	user f = { "f",32,NULL };
	user g = { "g",32,NULL };

	insert_table(&david);
	print_table();

	insert_table(&ron);

	print_table();


	insert_table(&amit);
	print_table();


	insert_table(&shimi);
	print_table();

	insert_table(&nevo);
	print_table();

	insert_table(&sharon);
	print_table();

	insert_table(&almog);
	print_table();

	insert_table(&bibi);
	print_table();

	insert_table(&mi);
	print_table();

	insert_table(&a);
	print_table();
	
	insert_table(&b);
	print_table();
	
	insert_table(&c);
	print_table();


	insert_table(&d);
	print_table();

	insert_table(&e);
	print_table();


	insert_table(&f);
	print_table();

	insert_table(&g);
	print_table();

	remove_user("almog");
	remove_user("amit");
	remove_user("mi");
	remove_user("b");
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