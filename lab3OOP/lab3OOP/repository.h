#pragma once
#include "profile.h"
#include <stdlib.h>

typedef struct {
	char* command;
	char** arguments;
	int nrOfArguments;
}command;

typedef struct {
	command* commandList;
	int size;
	int maxSize;
}struct_commands;


typedef struct {
	profile* profileList;
	int size, maximumSize;
}profileList;

typedef struct {
	profileList* profileMatrix;
	int size;
	int maximumSize;
}repository;

profileList* make_a_new_list(profileList oldList);
typedef struct {
	int currentIndex;
	int maxIndex;
}undo_redo;


int undo(undo_redo* indexes);

void check_redo(undo_redo* indexes);

int redo(undo_redo* indexes);

void add_a_new_list_to_matrix(repository* repository, profileList newList, int index);

int search_profile(repository repository, profile profileToSearch);

void init_repository(repository * repository);

int add(repository* repository, profile profileToAdd,undo_redo* indexes);

int update(repository* repository, profile newProfile, undo_redo* indexes);

int delete_profile(repository* repository, int profileIdNumber, undo_redo* indexes);


void realocate_repository(repository* repository);

void dealocate_repository(repository* repository);

profileList* get_matrix(repository repository);

