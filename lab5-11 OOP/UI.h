#pragma once

#include "Controler.h"


class UI {
private:
	controler* pointerController;
	char repositoryFilePath[200];
	char myListFilePath[200];
	char fileType[10];
public:
	
UI(controler* controller);

void populate_from_file();

void save_into_file();

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


