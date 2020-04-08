#pragma once

#include "Controler.h"

controler* createControler(repository* repository) {
	controler*controller = (controler*)malloc(sizeof(controler));
	controller->pointerRepository = repository;
	return controller;
}

int controler_add(controler * controller, profile newProfile, undo_redo * indexes)
{
	int succesfullOperation = add(controller->pointerRepository, newProfile, indexes);
	return succesfullOperation;
}

int controler_update(controler * controller, profile newProfile, undo_redo * indexes)
{
	return update(controller->pointerRepository, newProfile, indexes);
}

int controler_delete_profile(controler * controller, int idToDelete, undo_redo * indexes)
{
	return delete_profile(controller->pointerRepository, idToDelete, indexes);
}


profileList* get_list_by_index(controler* controller)
{
	return controller->pointerRepository->profileMatrix;
}



