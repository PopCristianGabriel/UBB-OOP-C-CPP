#pragma once
#include <string.h>


class evidence {

private:
	char id[20], measurement[20], photograph[20];
	int quantity;
	float imageClarity;
public:
	char* get_evidence_id();
	char* get_evidence_measurement();
	char* get_evidence_photograph();
	int   get_evidence_quantity();
	float get_evidence_image_clarity();

	void set_evidence_id(char* newEvidenceId);
	void set_evidence_measurement(char* newMeasurement);
	void set_evidence_photograph(char* newPhotograph);
	void set_evidence_quantity(int newQuantity);
	void set_evidence_image_clarity(float newImageClarity);
};

evidence make_an_evidence(char* command);


int check_same_evidences(evidence evidance1, evidence evidance2);