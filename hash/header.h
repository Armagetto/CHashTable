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
			printf("%i\t%s\n", i, user_hash_table[i]->name);
		}
	}
	printf("\n\n---END OF PRINT---\n\n");
}

int insert_table(user* user) {
	if (!user_valid(user)) { return 0; }

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
	return temp * i % TABLE_SIZE;
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