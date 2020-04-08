#pragma once

#include <stdio.h>
#include "Controler.h"

typedef struct {
	controler* pointerControler;
}UI;


UI* create_ui();
void print_error(char* typeOfError);

void list_a_profile(profile profile);

char* get_the_command(char* userInput);
char* read_a_command();

void list_all_profiles(UI ui, int index);

void list_psihological_profile(UI ui, char* psychological, int index);
char* get_the_psychological_profile(char* userInput);

void menu(UI* ui);



