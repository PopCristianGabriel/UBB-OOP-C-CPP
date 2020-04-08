#pragma once

#include "repository.h"
#include <stdio.h>
void init_repository(repository * repository) {
	repository->maximumSize = 30;
	repository->size = 0;

	repository->profileMatrix = (profileList*)malloc(30 * sizeof(profileList));

	for (int i = 0; i < repository->maximumSize; i++) {
		repository->profileMatrix[i].profileList = (profile*)malloc(30 * sizeof(profile));
		repository->profileMatrix[i].maximumSize = 30;
		repository->profileMatrix[i].size = 1;
	}
	}

void realocate_repository(repository* repository) {
	profileList* aux = (profileList*)realloc(repository->profileMatrix, sizeof(profileList) * 2 * repository->maximumSize);
	//repository->profileMatrix = aux;
	repository->maximumSize *= 2;
}

void realocate_profile_list(repository* repository,int index){
	realloc(repository->profileMatrix[index].profileList, repository->profileMatrix[index].maximumSize * 2 * sizeof(profile));
	repository->profileMatrix[index].maximumSize *= 2;
}





void dealocate_repository(repository* repository) {
	for (int i = 0; i < repository->maximumSize; i++) {
		free(repository->profileMatrix[i].profileList);
	}
	free(repository->profileMatrix);
//	free(repository);
}

profileList* get_matrix(repository repository)
{
	return repository.profileMatrix;
}


int undo(undo_redo* indexes) {
	if (indexes->currentIndex == 0) {
		return 0;
	}
	indexes->currentIndex--;
	return 1;
}

void check_redo(undo_redo* indexes) {
	

	if (indexes->currentIndex < indexes->maxIndex) {
		indexes->maxIndex = indexes->currentIndex;
	}
}

int redo(undo_redo* indexes) {
	if (indexes->currentIndex == indexes->maxIndex) {
		printf("i'm at the end\n");
		return;
	}
	if (indexes->currentIndex < indexes->maxIndex) {
		indexes->currentIndex++;
	}
}



profileList* make_a_new_list(profileList oldList) {
	profileList* newList = (profileList*)malloc(sizeof(profileList));
	newList->profileList = malloc(oldList.maximumSize * sizeof(profile));
	newList->maximumSize = oldList.maximumSize;
	newList->size = oldList.size;
	for (int i = 0; i < oldList.size; i++) {
		newList->profileList[i] = oldList.profileList[i];
	}
	
	return newList;
}


void add_a_new_list_to_matrix(repository* repository, profileList newList, int index) {
	if (repository->maximumSize == repository->size) {
		realocate_repository(&repository,index);
	}


	for (int i = 0; i < newList.size; i++) {

		repository->profileMatrix[index].profileList[i] = newList.profileList[i];
	}
	//repository->profileMatrix[index].size = newList.size;
	repository->profileMatrix[index].maximumSize = newList.maximumSize;
	repository->profileMatrix[index].size = newList.size;
}



int get_current_index(undo_redo indexes) {
	return indexes.currentIndex;
}






int search_profile(repository repository, profile profileToSearch,int index) {
	for (int i = 1; i < repository.profileMatrix[index].size; i++) {
		if (same_profile(repository.profileMatrix[index].profileList[i], profileToSearch) == 1) {
			return i;
		}
	}
	return -1;
}


int add(repository* repository, profile profileToAdd,undo_redo* indexes) {
	
	int positionOfProfile = search_profile(*repository, profileToAdd,indexes->currentIndex);
	if (positionOfProfile != -1) {
		return 0;
	}

	profileList* newList = make_a_new_list(repository->profileMatrix[indexes->currentIndex]);
	indexes->currentIndex++;
	indexes->maxIndex++;
	repository->size++;
	newList->size++;
	

	add_a_new_list_to_matrix(repository, *newList, indexes->currentIndex);
	
	if (repository->profileMatrix[indexes->currentIndex].maximumSize == repository->profileMatrix[indexes->currentIndex].size) {
		realocate_profile_list(repository,indexes->currentIndex);
	}

	repository->profileMatrix[indexes->currentIndex].profileList[repository->profileMatrix[indexes->currentIndex].size-1] = profileToAdd;
	
	free(newList->profileList);
	free(newList);
	return 1;

}

int update(repository* repository, profile newProfile,undo_redo* indexes) {
	int positionOfProfile = search_profile(*repository, newProfile,indexes->currentIndex);
	if (positionOfProfile == -1) {
		return 0;
	}

	profileList* newList = make_a_new_list(repository->profileMatrix[indexes->currentIndex]);
	indexes->currentIndex++;
	indexes->maxIndex++;
	repository->size++;

	add_a_new_list_to_matrix(repository, *newList, indexes->currentIndex);

	if (repository->profileMatrix[indexes->currentIndex].maximumSize == repository->profileMatrix[indexes->currentIndex].size) {
		realocate_profile_list(repository, indexes->currentIndex);
	}



	repository->profileMatrix[indexes->currentIndex].profileList[positionOfProfile] = newProfile;
	free(newList->profileList);
	free(newList);
	return 1;

}

int delete_profile(repository* repository, int profileIdNumber,undo_redo* indexes) {
	profile profileCopy;
	profileCopy.profileIdNumber = profileIdNumber;
	int positionOfProfile = search_profile(*repository, profileCopy,indexes->currentIndex);
	if (positionOfProfile == -1) {
		return 0;
	}
	profileList* newList = make_a_new_list(repository->profileMatrix[indexes->currentIndex]);
	indexes->currentIndex++;
	indexes->maxIndex++;
	repository->size++;

	add_a_new_list_to_matrix(repository, *newList, indexes->currentIndex);



	for (int j = positionOfProfile; j < repository->size - 1; j++) {
		repository->profileMatrix[indexes->currentIndex].profileList[j] = repository->profileMatrix[indexes->currentIndex].profileList[j + 1];
	}
	repository->profileMatrix[indexes->currentIndex].size--;

	free(newList->profileList);
	free(newList);
	return 1;

}

















