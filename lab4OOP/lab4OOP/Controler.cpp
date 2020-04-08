#include "Controler.h"



controler::controler(repository * repositorySave, repository * repository)
{
	this->repositoryPointerInputData = repository;
	this->repositoryPointerSavedInputData = repositorySave;
}

int controler::controler_add( evidence newEvidence)
{
	try {
		return this->repositoryPointerInputData->repository_add_to_list(newEvidence);
	}
	catch (MyException2& ex) {
		throw ex;
	}
}

int controler::controler_update( evidence newEvidence)
{
	return this->repositoryPointerInputData->repository_update_evidence(newEvidence);
}

int controler::controler_delete( char* idToDelete)
{
	return this->repositoryPointerInputData->repository_delete_evidence(idToDelete);
}

int controler::get_size_of_list()
{
	return this->repositoryPointerInputData->get_evidence_list_size();
}

int controler::controller_save_evidence_with_id( char* idToSave)
{
	return this->repositoryPointerSavedInputData->repository_add_element_by_id(this->repositoryPointerInputData,idToSave);
}




vector<evidence> controler::get_list_by_index()
{
	return this->repositoryPointerInputData->get_evidence_list();
}

vector<evidence> controler::get_saves() {
	return this->repositoryPointerSavedInputData->get_evidence_list();
}

int controler::get_saves_size() {
	return this->repositoryPointerSavedInputData->get_evidence_list_size();
}


