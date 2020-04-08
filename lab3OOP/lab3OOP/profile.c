#include "profile.h"
#include <stddef.h>
#include <string.h>




int char_to_number(char* numberInChars)
{
	int numberFromChar = 0;
	for (int i = 0; i < strlen(numberInChars); i++) {
		numberFromChar = numberFromChar * 10 + (numberInChars[i]- '0');
	}
	return numberFromChar;
}


profile make_a_profile(char* command) {
	profile newProfile;

	char *partOfTheProfile;
	int i = 0;
	partOfTheProfile = strtok(command, " ,");
	partOfTheProfile = strtok(NULL, ",");
	while (partOfTheProfile != NULL){
		if (partOfTheProfile[0] == ' ') {
			strcpy(partOfTheProfile, partOfTheProfile + 1);
		}
	
		switch (i)
		{
		case 0:
			newProfile.profileIdNumber = char_to_number(partOfTheProfile);
			break;
		case 1:
			strcpy(newProfile.placeOfBirth, partOfTheProfile);
			break;
		case 2:
			strcpy(newProfile.psychologicalProfile, partOfTheProfile);
			break;
		case 3:
			newProfile.yearsOfService = char_to_number(partOfTheProfile);
		default:
			break;
		}
		i++;
		partOfTheProfile = strtok(NULL, ",");
	}
	return newProfile;
}

void set_place_of_birth(profile* profile, char* newPLaceOfBirth) {
	strcpy(profile->placeOfBirth, newPLaceOfBirth);
}

void set_psyhological_profile(profile* profile, char* psychologicalProfile) {
	strcpy(profile->psychologicalProfile, psychologicalProfile);
}

int get_profile_id_number(profile profile) {
	return profile.profileIdNumber;
}

int get_years_of_service(profile profile) {
	return profile.yearsOfService;
}

char* get_place_of_birth(profile profile) {
	return profile.placeOfBirth;
}

char* get_psyhological_profile(profile profile) {
	return profile.psychologicalProfile;
}


int same_profile(profile profile1, profile profile2) {
	return get_profile_id_number(profile1) == get_profile_id_number(profile2);
}
