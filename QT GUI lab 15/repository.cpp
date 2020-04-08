#pragma once
#include "repository.h"
#include <stdlib.h>





int repository::repository_add_to_list(evidence newEvidence) {
	try {
		this->listOfObjects.dynamicList_add_to_list(newEvidence);
	}
	catch (MyException2& ex) {
		throw ex;
	}
	return 1;
}



int repository::repository_delete_evidence( char* idToDelete)
{
	try {
		 this->listOfObjects.dynamicList_delete_evidence(idToDelete);
	}
	catch (const char*error) {
		return 0;
	}
	return 1;
}


int repository::repository_add_element_by_id(repository* originalRepository,char * idToSave)
{
	try {
		 this->listOfObjects.dynamicList_add_element_by_id(originalRepository->listOfObjects, idToSave);
	}
	catch (const char* error) {
		return 0;
	}
	return 1;

}

int repository::repository_update_evidence( evidence newEvidence)
{
	try {
		 this->listOfObjects.dynamicList_update_evidence(newEvidence);
	}
	catch (const char* error) {
		return 0;
	}
	return 1;
}

vector<evidence> repository::get_evidence_list()
{
	return this->listOfObjects.get_evidence_list();
}

int repository::get_evidence_list_size()
{
	return this->listOfObjects.get_evidence_list_size();
}

repository::repository()
{
}

