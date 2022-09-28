#pragma once
#define _CTR_SECUTRE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
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
int user_hash_table_size[TABLE_SIZE] = { 0 }; //this is to follow the size of a linked lists (so save time on some oparations)
//unsigned int user_hash_table_taken_size = 0;

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
	if (new_new_user == NULL)
		return NULL;

	new_new_user->age = age;
	new_new_user->name = name;
	new_new_user->next = NULL;


	user* curr = root[hash(name)];
	while (curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = new_new_user;
	return 1;
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

user* delete_from_list(user* root,char* name) {
	if (root == NULL) {
		return -1;
	}
		
	//if root is this
	if (strcmp(root->name, name) == 0) {
		user* to_remove = root;
		root = root->next;
		//update in hash
		user_hash_table[hash(name)] = root;

		return root;
	}


	for (user* curr = root; curr->next != NULL ;curr = curr->next) {
		if (strcmp(curr->next->name, name) == 0) {
			user* to_remove = curr->next;
			curr->next = curr->next->next;

			if (to_remove != NULL)
				free(to_remove);

			return root;
		}
	}
	
	
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
			
		}
	}
	printf("\n\n---END OF PRINT---\n\n");
}

int insert_table(user* user) {
	if (!user_valid(user)) { return 0; }

	int index = hash(user->name);
	

	if (user_hash_table[index] != NULL) {
		if (chain_list(user_hash_table, user) != 0) {
			user_hash_table_size[index]++;
		}
		return 0;
	}
	else {
		user_hash_table[index] = user;
		user_hash_table_size[index]++;
		return 1;
	}
}


//hash function
int hash(char* name) {
	int temp = 0;
	int i = 0;
	for (; i < strlen(name); i++) {
		temp += name[i];
	}
	return (temp * i) % TABLE_SIZE;
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
		if (name == NULL) { return NULL; }
		//gets where it is
		int index = hash(name);
		//if it's location isn't null
		if (user_hash_table[index] != NULL) {
			delete_from_list(user_hash_table[index], name);
			return 1;
		}
		else {
			return -1;
		}
	
}

//crate new user
user* create_new_user(char* name, int age) {
	if (name == NULL || age <= 0) {
		return NULL;
	}
	

	//crate new user
	user* new_user = (user*)malloc(sizeof(user));
	if (new_user == NULL) {
		return NULL;
	}
		

	new_user->next = NULL;
	new_user->name = name;
	new_user->age = age;
	return new_user;
}