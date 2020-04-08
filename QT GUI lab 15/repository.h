#pragma once
#include "dynamicList.h"




class repository {
protected:
	dynamicList<evidence> listOfObjects;

public:

	vector<evidence> get_evidence_list();
	int get_evidence_list_size();
	
	repository();

	

	//void realocate_repository();

	  int repository_add_to_list(evidence newEvidence);

	//int get_evidence_position(evidence evidence);

	int repository_delete_evidence( char* idToDelete);

	//int get_position_by_id(char * idToFind);

	int repository_add_element_by_id(repository* originalRepository, char* idToSave);

	int repository_update_evidence(evidence newEvidence);

};

/*class repositoryFake : public repository{
public:
	repositoryFake() : repository() {};
	virtual int repository_add_to_list(evidence newEvidence) override {
		try {
			this->listOfObjects.dynamicList_add_to_list(newEvidence);
		}
		catch (MyException2& ex) {
			throw ex;
		}
		return 1;
	}
};*/





