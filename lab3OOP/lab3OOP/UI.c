#pragma once
#include "UI.h"
#include <string.h>





UI * create_ui(controler* controller)
{
	UI* ui = (UI*)malloc(sizeof(UI));
	ui->pointerControler = controller;
	return ui;
}

void print_error(char * typeOfError)
{
	if (strcmp(typeOfError, "add") == 0) {
		printf("already existing profile");
	}
	if (strcmp(typeOfError, "update") == 0) {
		printf("the profile hasn't been found");
	}
	if (strcmp(typeOfError, "undo") == 0) {
		printf("i'm at the begginnign");
	}
	if (strcmp(typeOfError, "redo") == 0) {
		printf("i'm at the end");
	}
	if (strcmp(typeOfError, "years") == 0) {
		printf("no profile has matched your years of service\n");
	}
	if (strcmp(typeOfError, "psychological") == 0) {
		printf("no profile has matched your psychological description\n");
	}
}



void list_a_profile(profile profile) {
	printf("id:%d , place of birth:%s , psychological status:%s, years served: %d   \n", profile.profileIdNumber, profile.placeOfBirth, profile.psychologicalProfile, profile.yearsOfService);
}

void list_all_profiles(UI ui,int index) {
	profileList* profileMatrix = get_list_by_index(ui.pointerControler);
	for(int i = 1; i < profileMatrix[index].size; i++) {
		list_a_profile(profileMatrix[index].profileList[i]);
	}
}


char* get_the_command(char* userInput) {
	char copyUserInput[100];
	strcpy(copyUserInput, userInput);
	char* command = strtok(copyUserInput, " ,");
	return command;
}

char* read_a_command() {
	char userInput[100];
	scanf("%99[^\n]", userInput);
	getchar();
	return userInput;
}


void list_years_of_service(UI ui, int yearsOfService, int index) {

	int howManyProfilesWithTheDescriptionGivenIveFound = 0;
	profileList* profileMatrix = get_list_by_index(ui.pointerControler);

	for (int i = 1; i < profileMatrix[index].size; i++) {
		if (profileMatrix[index].profileList[i].yearsOfService <= yearsOfService) {
			list_a_profile(profileMatrix[index].profileList[i]);
			howManyProfilesWithTheDescriptionGivenIveFound++;
		}
	}
	if (!howManyProfilesWithTheDescriptionGivenIveFound) {
		print_error("years");

	}

}

void list_psihological_profile(UI ui, char* psychological, int index) {
	int howManyProfilesWithTheDescriptionGivenIveFound = 0;
	profileList* profileMatrix = get_list_by_index(ui.pointerControler);
	for (int i = 1; i < profileMatrix[index].size; i++) {
		if (strcmp(profileMatrix[index].profileList[i].psychologicalProfile, psychological) == 0) {
			list_a_profile(profileMatrix[index].profileList[i]);
			howManyProfilesWithTheDescriptionGivenIveFound++;
		}
	}
	if (!howManyProfilesWithTheDescriptionGivenIveFound) {
		print_error("psychological");
	}

}





char* get_the_psychological_profile(char* userInput) {

	char copyUserInput[100];
	strcpy(copyUserInput, userInput);
	char psychologicalProfile[100];
	char* psychologicalProfileSubpart = strtok(copyUserInput, " ,");
	psychologicalProfileSubpart = strtok(NULL, " ,");
	strcpy(psychologicalProfile, psychologicalProfileSubpart);
	while (psychologicalProfileSubpart) {
		psychologicalProfileSubpart = strtok(NULL, " ,");
		if (psychologicalProfileSubpart != NULL) {
			strcat(psychologicalProfile, " ");
			strcat(psychologicalProfile, psychologicalProfileSubpart);
		}
	}
	return psychologicalProfile;

}


void menu(UI* ui) {
	undo_redo indexes;
	indexes.currentIndex = 0;
	indexes.maxIndex = 0;
	char userInput[100];
	char* command = (char*)malloc(100);
	int successfulOperation;

	while (1) {
		//printf("enter a command:\n");
		strcpy(userInput, read_a_command());
		command = get_the_command(userInput);
		if (strcmp(userInput, "exit") == 0) {
			break;
		}

		if (strcmp(command, "add") == 0) {
			check_redo(&indexes);
			profile newProfile = make_a_profile(userInput);

			successfulOperation = controler_add(ui->pointerControler, newProfile, &indexes);
			if (!successfulOperation) {
				print_error("add");
			}
		}

		else if (strcmp(command, "undo") == 0) {
			successfulOperation = undo(&indexes);
			if (!successfulOperation) {
				print_error("undo");
			}
		}

		else if (strcmp(command, "redo") == 0) {
			successfulOperation = redo(&indexes);
			if (!successfulOperation) {
				print_error("redo");
			}
		}

		else if (strcmp(command, "update") == 0) {
			check_redo(&indexes);
			profile newProfile = make_a_profile(userInput);
			successfulOperation = controler_update(ui->pointerControler, newProfile, &indexes);
			if (!successfulOperation) {
				print_error("update");
			}
		}
		else if (strcmp(command, "list") == 0 && strlen(userInput) < 6) {
			list_all_profiles(*ui, indexes.currentIndex);
		}
		else if (strcmp(command, "delete") == 0) {
			check_redo(&indexes);
			char idToDelete[100];
			strcpy(idToDelete, get_the_psychological_profile(userInput));
			successfulOperation = controler_delete_profile(ui->pointerControler, char_to_number(idToDelete), &indexes);
			if (!successfulOperation) {
				print_error("update");
			}
		}


		else {
			char psyhologicalProfile[100];
			strcpy(psyhologicalProfile, get_the_psychological_profile(userInput));
			if (strchr("0123456789", psyhologicalProfile[0]) == NULL) {
				list_psihological_profile(*ui, psyhologicalProfile, indexes.currentIndex);
			}
			else {
				int yearsOfService = char_to_number(psyhologicalProfile);
				list_years_of_service(*ui, yearsOfService, indexes.currentIndex);
			}
		}
	}
}
