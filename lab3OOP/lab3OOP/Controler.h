#pragma once

#include "repository.h"


typedef struct {
	repository* pointerRepository;
}controler;

controler* createControler(repository* repository);

int controler_add(controler* controller, profile newProfile, undo_redo* indexes);

int controler_update(controler* controller, profile newProfile, undo_redo* indexes);

int controler_delete_profile(controler* controller, int idToDelete, undo_redo* indexes);


profileList* get_list_by_index(controler* controller);
