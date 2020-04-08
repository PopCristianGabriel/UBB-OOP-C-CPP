#pragma once

typedef struct {
	int profileIdNumber;
	char placeOfBirth[20];
	char psychologicalProfile[20];
	int yearsOfService;
	
}profile;



int char_to_number(char* numberInChars);

profile make_a_profile(char* command);

void set_place_of_birth(profile* profile, char* newPLaceOfBirth);

void set_psyhological_profile(profile* profile, char* psychologicalProfile);

int get_profile_id_number(profile profile);

int get_years_of_service(profile profile);

char* get_place_of_birth(profile profile);

char* get_psyhological_profile(profile profile);


int same_profile(profile profile1, profile profile2);

