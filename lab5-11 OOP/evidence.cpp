#pragma once
#include "evidence.h"
#include <stdio.h>
#include <iostream>



int count_nr_of_commas(char* command) {
	int commas = 0;
	for (int i = 0; i < strlen(command); i++) {
		if (command[i] == ',')
			commas++;
	}
	return commas;
}

evidence make_an_evidence(char* command) {
	evidence newEvidence;


	int nrOfCommas = count_nr_of_commas(command);
	if (nrOfCommas != 4) {
		throw "invalid evidence";
	}
	char *partOfTheEvidence;
	int i = 0;
	partOfTheEvidence = strtok(command, " ,");
	partOfTheEvidence = strtok(NULL, ",");
	while (partOfTheEvidence != NULL) {
		if (partOfTheEvidence[0] == ' ') {
			strcpy(partOfTheEvidence, partOfTheEvidence + 1);
		}

		switch (i)
		{
		case 0:
			newEvidence.set_evidence_id(partOfTheEvidence);
			break;
		case 1:
			newEvidence.set_evidence_measurement( partOfTheEvidence);
			break;
		case 2:
			for (int i = 0; i < strlen(partOfTheEvidence); i++) {
				if ((partOfTheEvidence[i] < '0' || partOfTheEvidence[i] > '9') && partOfTheEvidence[i] != '.') {
					printf("invalid evidence\n");
					throw "invalid evidence";
					/*char invalidMeasurement[2];
					strcpy(invalidMeasurement, "-1");
					newEvidence.set_evidence_measurement(invalidMeasurement);
					return newEvidence;*/
				}
			}
			newEvidence.set_evidence_image_clarity(atof(partOfTheEvidence));
			break;
		case 3:
			for (int i = 0; i < strlen(partOfTheEvidence); i++) {
				if (partOfTheEvidence[i] < '0' || partOfTheEvidence[i] > '9' ) {
					//printf("invalid evidence\n");
					throw "invalid evidence";
					//char invalidMeasurement[2];
					//strcpy(invalidMeasurement, "-1");
					//newEvidence.set_evidence_measurement(invalidMeasurement);
					//return newEvidence;
				}
			}
			newEvidence.set_evidence_quantity(atoi(partOfTheEvidence));
		case 4:
			newEvidence.set_evidence_photograph(partOfTheEvidence);
		default:
			break;
		}
		i++;
		partOfTheEvidence = strtok(NULL, ",");
	}
	return newEvidence;
	}

int check_same_evidences(evidence evidance1, evidence evidance2) {
	return strcmp(evidance1.get_evidence_id(), evidance2.get_evidence_id()) == 0;
}

char * evidence::get_evidence_id()
{
	return this->id;
}

char * evidence::get_evidence_measurement()
{
	return this->measurement;
}

char * evidence::get_evidence_photograph()
{
	return this->photograph;
}

int evidence::get_evidence_quantity()
{
	return this->quantity;
}

float evidence::get_evidence_image_clarity()
{
	return this->imageClarity;
}

void evidence::set_evidence_id(char * newEvidenceId)
{
	strcpy(this->id, newEvidenceId);
}

void evidence::set_evidence_measurement(char * newMeasurement)
{
	strcpy(this->measurement, newMeasurement);
}

void evidence::set_evidence_photograph(char * newPhotograph)
{
	strcpy(this->photograph, newPhotograph);
}

void evidence::set_evidence_quantity(int newQuantity)
{
	this->quantity = newQuantity;
}

void evidence::set_evidence_image_clarity(float newImageClarity)
{
	this->imageClarity = newImageClarity;
}
