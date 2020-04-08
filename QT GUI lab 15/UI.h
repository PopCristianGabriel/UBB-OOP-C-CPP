#pragma once

#include "Controler.h"
#include <windows.h>


class UI {
private:
	controler* pointerController;
	char repositoryFilePath[200];
	char myListFilePath[200];
	char fileType[10];
public:


UI(controler* controller);

void ui_update(evidence evidenceToUpdate);

void remove(char* idToRemove);

vector<evidence> ui_get_list_of_evidences();

int get_myList_size();
int get_repository_size();

void set_fileRepository_path(char* path);

void populate_from_file();

void save_into_file();
vector<evidence> get_list_of_evidences();
vector<evidence> get_list_of_saves();
void save_evidence_into_saves(char* idToSave);
void list_an_evidence(evidence evidence);

void list_all_evidences( const char*);

void print_errors(const char* typeOfError);

char* read_a_command();

char* get_the_command(char* userInput);

void menu();
char* get_the_psychological_profile(char* userInput);


void ui_senior_clearance();

void increase_list_index( int & listIndex);


void ui_standard_clearance();

void list_filter( char*measurement, int numberQuantity);

};


