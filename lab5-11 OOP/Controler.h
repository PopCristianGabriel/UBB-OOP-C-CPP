#pragma once
#include "repository.h"



class controler {
public:
	repository* repositoryPointerInputData;
	repository* repositoryPointerSavedInputData;
	controler() {

	}
	controler(repository* repositorySave, repository* repository);

	int controler_add( evidence newEvidence);

	int controler_update( evidence newEvidence);

	int controler_delete( char* idToDelete);

	int get_size_of_list();

	int  controller_save_evidence_with_id( char* idToSave);


	vector<evidence> get_list_by_index();
	vector<evidence> get_saves();
	int get_saves_size();

};


