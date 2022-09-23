#define _CTR_SECUTRE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct user {
	char name[MAX_NAME];
	int age;
}user;


//hash table
user * user_hash_table[TABLE_SIZE];
unsigned int user_hash_table_taken_size = 0;

//initialize table
void initialize_table() {
	for (int i = 0; i < TABLE_SIZE; i++) {
		user_hash_table[i] = NULL;
	}
}

//print table
int print_table() {
	printf("---NEW PRINT---\n\n");
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (user_hash_table[i] == NULL) {
			printf("%i\t---\n",i);
		}
		else {
			printf("%i\t%s\n", i, user_hash_table[i]->name);
		}
	}
	printf("\n\n---END OF PRINT---\n\n");
}

int insert_table(user* user) {
	if (user == NULL) { return 0; }

	int index = hash(user->name);
	if (user_hash_table[index] != NULL) {
		return 0;
	}
	else {
		user_hash_table[index] = user;
		return 1;
	}
}


//hash function
unsigned int hash(char* name) {
	unsigned int temp = 0;
	unsigned int i = 0;
	for (; i < strlen(name); i++) {
		temp += name[i];
	}
	return temp* i % TABLE_SIZE;
}


//table lookUp
int lookUp(char* name) {
	if (name == NULL) { return NULL; }
	
	int index = hash(name);

	if (user_hash_table[index] != NULL) {
		if (strcmp(user_hash_table[index]->name, name) == 0) {
			return index;
		}
	}
	else {
		return -1;
	}
}

//delete
user* remove_user(char* name) {
	int index = lookUp(name);
	if (index >= 0) {
		user* temp = user_hash_table[index];
		user_hash_table[index] = NULL;
		return temp;
	}
	else {
		return NULL;
	}
}



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