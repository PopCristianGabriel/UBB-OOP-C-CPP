#pragma once
#include "UI.h"



class errors {
public:
	errors() {  }
	void print_errors(const char* error);
};
void errors::print_errors(const char* typeOfError) {
	if (strcmp(typeOfError, "path") == 0) {
		printf("invalid path\n");
	}
	if (strcmp(typeOfError, "invalid") == 0) {
		printf("invalid evidence\n");
	}
	if (strcmp(typeOfError, "mode") == 0) {
		printf("invalid mode\n");
	}
	if (strcmp(typeOfError, "save") == 0) {
		printf("invalid id or already saved id\n");
	}
	if (strcmp(typeOfError, "add") == 0) {
		printf("already existing evidence\n");
	}
	if (strcmp(typeOfError, "update") == 0) {
		printf("the evidence hasn't been found\n");
	}
	if (strcmp(typeOfError, "undo") == 0) {
		printf("i'm at the begginnign\n");
	}
	if (strcmp(typeOfError, "redo") == 0) {
		printf("i'm at the end\n");
	}

}





UI::UI(controler* controller)
{
	this->pointerController = controller;
	
}

void UI::ui_update(evidence evidenceToUpdate)
{
	this->pointerController->controler_update(evidenceToUpdate);
}

void UI::remove(char* idToRemove)
{
	this->pointerController->controler_delete(idToRemove);
}

vector<evidence> UI::ui_get_list_of_evidences()
{
	return this->pointerController->get_list_by_index();
}

int UI::get_myList_size()
{
	return this->pointerController->get_saves_size();
}

int UI::get_repository_size()
{
	return this->pointerController->get_size_of_list();
}

void UI::set_fileRepository_path(char * path)
{
	strcpy(this->repositoryFilePath, path);
}

void UI::populate_from_file()
{
	char evidenceFromFile[255];
	char c;
	c = 'a';
	int nr;
	ifstream file(this->repositoryFilePath);
	if (!file) {
		int a = 5;
	}
	//file.getline(evidenceFromFile, 100);
	while(!file.eof()){
		file.getline(evidenceFromFile, 255);
		char userInput[200];
		if (strlen(evidenceFromFile) > 20) {
			strcpy(userInput, "add ");
			strcat(userInput, evidenceFromFile);
			evidence evidenceToAdd = make_an_evidence(userInput);
			this->pointerController->controler_add(evidenceToAdd);
		}
	}
	file.close();
	}

void modify_path(char path[100]) {
	int i = 0;
	while (i < strlen(path)) {
		if (path[i] == '\\') {
			path[strlen(path) + 1] = NULL;
			for (int j = strlen(path) - 1; j > i; j--) {
				path[j + 1] = path[j];
			}
			path[i + 1] = path[i];
			i = i + 2;
		}
		else i++;
	}
}

void UI::save_into_file()
{

	ofstream file(this->repositoryFilePath);
	for (evidence evidence : this->pointerController->get_list_by_index()) {
		file << evidence.get_evidence_id() << ", " << evidence.get_evidence_measurement() << ", " << evidence.get_evidence_image_clarity() << ", " << evidence.get_evidence_quantity() << ", " << evidence.get_evidence_photograph() << endl;
	}
	file.close();
	/*

	if (!(strcmp(this->fileType, "csv"))) {
		ofstream file(this->myListFilePath);
			for (evidence evidence : this->pointerController->get_saves()) {
				file << evidence.get_evidence_id() << ", " << evidence.get_evidence_measurement() << ", " << evidence.get_evidence_image_clarity() << ", " << evidence.get_evidence_quantity() << ", " << evidence.get_evidence_photograph() << endl;
			}
		file.close();
		LPCTSTR helpFile = this->myListFilePath;
		ShellExecute(NULL, "open", helpFile, NULL, NULL, SW_SHOWNORMAL);
	}

	else {
		ofstream file(this->myListFilePath);
		file << "<!DOCTYPE html>\n";
		file << "	<html>\n";
		file << "		<head>";
		file << "			<title>myList</title>\n";
		file << "		</head>\n";
		file << "		<body>";
		file << "			<table border=\"1\">";
		for (evidence evidence : this->pointerController->get_saves()) {
			file << "			<tr>";
			file << "<td>" << evidence.get_evidence_id() << "</td\n>";
			file << "<td>" << evidence.get_evidence_image_clarity() << "</td\n>";
			file << "<td>" << evidence.get_evidence_measurement() << "</td\n>";
			file << "<td>" << evidence.get_evidence_photograph() << "</td\n>";
			file << "<td>" << evidence.get_evidence_quantity() << "</td\n>";
			file << "			</tr>\n";
		}
		file << "</table>";
		file << "</body>";
		file << "</html>";
		file.close();
		LPCTSTR helpFile = this->myListFilePath;
		ShellExecute(NULL, "open", helpFile, NULL, NULL, SW_SHOWNORMAL);
	}*/
}

vector<evidence> UI::get_list_of_evidences()
{
	return this->pointerController->get_list_by_index();
}

vector<evidence> UI::get_list_of_saves()
{
	return this->pointerController->get_saves();
}

void UI::save_evidence_into_saves(char* idToSave)
{
	this->pointerController->controller_save_evidence_with_id(idToSave);
}

void UI::list_an_evidence(evidence evidence)
{
	printf("id: %s measurement: %s clarity: %g quantity: %d photograph: %s\n\n", evidence.get_evidence_id(), evidence.get_evidence_measurement(), evidence.get_evidence_image_clarity(), evidence.get_evidence_quantity(), evidence.get_evidence_photograph());
}
bool finalExit = false;
void UI::list_all_evidences(const char* whichOne)
{
	vector<evidence> evidenceList;
	int sizeOfList;
	if (strcmp(whichOne,"original") == 0) {
		 evidenceList = this->pointerController->get_list_by_index();
		 sizeOfList = this->pointerController->get_size_of_list();
	}
	else {
		 evidenceList = this->pointerController->get_saves();
		 sizeOfList = this->pointerController->get_saves_size();
	}
	for (int i = 0; i < sizeOfList; i++) {
		list_an_evidence(evidenceList[i]);
	}
}

void UI::print_errors(const char * typeOfError)
{
	if (strcmp(typeOfError, "path") == 0) {
		printf("invalid path\n");
	}
	if (strcmp(typeOfError, "invalid") == 0) {
		printf("invalid evidence\n");
	}
	if (strcmp(typeOfError, "mode") == 0) {
		printf("invalid mode\n");
	}
	if (strcmp(typeOfError, "save") == 0) {
		printf("invalid id or already saved id\n");
	}
	if (strcmp(typeOfError, "add") == 0) {
		printf("already existing evidence\n");
	}
	if (strcmp(typeOfError, "update") == 0) {
		printf("the evidence hasn't been found\n");
	}
	if (strcmp(typeOfError, "undo") == 0) {
		printf("i'm at the begginnign\n");
	}
	if (strcmp(typeOfError, "redo") == 0) {
		printf("i'm at the end\n");
	}
}


	char * UI::read_a_command()
	{
		char userInput[100];
		scanf("%99[^\n]", userInput);
		getchar();
		return userInput;
	}

	char* UI:: get_the_command(char* userInput) {
	char copyUserInput[200];
	strcpy(copyUserInput, userInput);
	char* command = strtok(copyUserInput, " ,");
	return command;
}



	
	char* UI::get_the_psychological_profile(char* userInput) {

	char copyUserInput[200];
	strcpy(copyUserInput, userInput);
	char psychologicalProfile[200];
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

void UI::ui_senior_clearance()
{
	errors errorHandler;
	char userInput[100];
	char * command;
	int successfulOperation;


	while (true) {
		if (finalExit == true) {
			break;
		}
		strcpy(userInput, read_a_command());
		
		command = get_the_command(userInput);
		if (strcmp(userInput, "exit") == 0) {
			command = NULL;
			this->save_into_file();
			
			finalExit = true;
			break;
		}

		if (strcmp(userInput, "mode B") == 0) {
			this->ui_standard_clearance();
		}


		 if (strcmp(command, "add") == 0) {
			evidence newEvidence;
			successfulOperation = 0;
			try {
				newEvidence = make_an_evidence(userInput);
				successfulOperation = this->pointerController->controler_add(newEvidence);
			}
			catch (MyException2& ex) {
				cout << ex.get_file() << " " << ex.get_func() << " " << ex.get_info() << " " << ex.get_line();
			}
			if (!successfulOperation) {
				errorHandler.print_errors("add");
			}
	  
		 }
	
		else if (strcmp(command, "delete") == 0) {
			char evidenceToDelete[20]; strcpy(evidenceToDelete, get_the_psychological_profile(userInput));
			successfulOperation = this->pointerController->controler_delete( evidenceToDelete);
			if (!successfulOperation) {
				errorHandler.print_errors("update");
			}
		}
		else if (strcmp(command, "update") == 0) {
			evidence newEvidence = make_an_evidence(userInput);
			successfulOperation = this->pointerController->controler_update(newEvidence);
			if (!successfulOperation) {
				errorHandler.print_errors("update");
			}
		}
		else if (strcmp(command, "list") == 0) {
			list_all_evidences("original");
		}
		

	}



}

void UI::increase_list_index(int & listIndex) {
	int sizeOfList = this->pointerController->get_size_of_list();
	listIndex++;
	if (sizeOfList == listIndex) {
		listIndex = 0;
		return;
	}
	


	
}

void UI::ui_standard_clearance()
{
	errors errorHandler;
	int listIndex = -1;
	char userInput[100];
	char * command;
	int successfulOperation;
	while (true) {
		if (finalExit == true) {
			break;
		}
		strcpy(userInput, read_a_command());
		command = get_the_command(userInput);

		if (strcmp(userInput, "exit") == 0) {
			this->save_into_file();
			finalExit = true;
			break;
		}

		if (strcmp(userInput, "mode A") == 0) {
			this->ui_senior_clearance();
		}

		if (strcmp(command, "next") == 0) {
			this->increase_list_index(listIndex);
			this->list_an_evidence(this->pointerController->get_list_by_index()[listIndex]);
		}
		if (strcmp(command, "save") == 0) {
			char idToSave[100];
			strcpy(idToSave ,get_the_psychological_profile(userInput));
			successfulOperation = this->pointerController->controller_save_evidence_with_id( idToSave);
			//free(idToSave);
			if (!successfulOperation) {
				errorHandler.print_errors("save");
			}
		}
		
		if (strcmp(command, "mylist") == 0) {
			this->list_all_evidences("saves");
		}
		if (strcmp(command, "list") == 0) {
			char measurement[20], quantity[10];
			char newCommand[20];
			strcpy(newCommand, get_the_psychological_profile(userInput));
			strcpy(measurement, get_the_command(newCommand));
			strcpy(quantity,get_the_psychological_profile(newCommand));
			int numberQuantity = atoi(quantity);
			this->list_filter(measurement, numberQuantity);
		}
	}
}

void UI::list_filter( char * measurement, int numberQuantity)
{

	vector<evidence> evidenceList = this->pointerController->get_list_by_index();
	int sizeOfList = this->pointerController->get_size_of_list();
	for (int i = 0; i < sizeOfList; i++) {
		if (!strcmp(measurement, evidenceList[i].get_evidence_measurement()) && numberQuantity <= evidenceList[i].get_evidence_quantity()) {
			this->list_an_evidence(evidenceList[i]);
		}
	}
}



char* get_the_file_type(char* userInput) {
	char copyUserInput[200];
	strcpy(copyUserInput, userInput);
	char* fileType = strtok(userInput, " ");
	fileType = strtok(NULL, ".");
	fileType = strtok(NULL, ".");
	return fileType;



}



void UI::menu() {
	//cout << this->pointerController;
	errors errorHandler;
	char userInput[200];
	char command[20];
	char mode[20];
	scanf("%200[^\n]", userInput);
	getchar();
	printf("\n");
	if (finalExit == true) {
		return;
	}
	int ok = 1;
	if (strcmp(mode, "exit") == 0) {
		finalExit = true;
		return;
	}
	
		char path[200];
		
		strcpy(command, get_the_command(userInput));
		if (!strstr(command, "fileLocation")) {
			this->menu();
		}
		strcpy(path, get_the_psychological_profile(userInput));
		//modify_path(path);
		//ifstream f(path);
		strcpy(this->repositoryFilePath, path);
		ofstream file(this->repositoryFilePath);
		file.close();


		



		this->populate_from_file();
		ok = 0;


		
		while (!ok) {
			ok = 1;
			scanf("%200[^\n]", userInput);
			strcpy(command, get_the_command(userInput));
			if (strcmp(command, "mylistLocation")) {
				ok = 0;
			}
		}

		strcpy(this->myListFilePath, get_the_psychological_profile(userInput));
		ok = 0;

		strcpy(this->fileType, get_the_file_type(userInput));
		cin.get();
	while (ok == 0) {
		scanf("%20[^\n]", mode);
		cin.get();
		if (strstr(mode, "mode A") == NULL && strstr(mode, "mode B") == NULL) {
			ok = 0;
			errorHandler.print_errors("mode");
			//this->menu();
		}
		else {
			ok = 1;
		}
	}
	if (strstr(mode, "mode A")) {
		this->ui_senior_clearance();
	}
	else {
		this->ui_standard_clearance();
	}
}

