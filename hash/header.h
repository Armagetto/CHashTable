#pragma once
#define _CTR_SECUTRE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_NAME 256
#define MAX_AGE 140
#define TABLE_SIZE 10

typedef struct user {
	char* name;
	int age;
	struct user* next;
}user;


//hash table
user* user_hash_table[TABLE_SIZE];
unsigned int user_hash_table_taken_size = 0;

//user valid?
unsigned int user_valid(user* user) {
	if (user == NULL) { return 0; }
	if (user->name == NULL) { return 0; }
	if (strlen(user->name) > MAX_NAME) { return 0; }
	if (user->age > MAX_AGE || user->age <= 0) { return 0; }
	return 1;
}

int chain_list(user** root, user* new_user) {
	if (root == NULL)
		return 0;
	if (new_user == NULL)
		return 0;

	int age = new_user->age;
	char* name = new_user->name;

	//ini new user
	user* new_new_user = (user*)malloc(sizeof(user));
	new_new_user->age = age;
	new_new_user->name = name;
	new_new_user->next = NULL;


	user* curr = *root;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = new_new_user;
}


int print_chain(user* root) {
	if (root == NULL)
		return 0;

	user* curr = root;
	while (curr->next != NULL) {
		printf("%s\t",curr->name);
		curr = curr->next;
	}
	if (curr != NULL) {
		printf("%s\t", curr->name); //print last name
	}
	printf("\n");
}

int lookup_chain(user* root, char* name) {
	if (root == NULL)
		return -1;
	int index = 0;

	user* curr = root;
	while (curr->next != NULL) {
		index++;
		if (strcmp(curr->name, name) == 0) {
			return index;
		}
		curr = curr->next;
	}
	if (curr != NULL) {
		index++;
		if (strcmp(curr->name, name) == 0) {
			return index;
		}
	}
	return -1;
}

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
			printf("%i\t---\n", i);
		}
		else {
			printf("%i\t", i);
			print_chain(user_hash_table[i]);
			//printf("%i\t%s\n", i, user_hash_table[i]->name);
		}
	}
	printf("\n\n---END OF PRINT---\n\n");
}

int insert_table(user* user) {
	if (!user_valid(user)) { return 0; }

	int index = hash(user->name);

	if (user_hash_table[index] != NULL) {
		chain_list(user_hash_table,user);
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
	return temp * i % TABLE_SIZE;
}


//table lookUp
int lookUp(char* name) {
	if (name == NULL) { return NULL; }
	int chain_result = 0;
	int index = hash(name);

	if (user_hash_table[index] != NULL) {
		return lookup_chain(user_hash_table[index], name);
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