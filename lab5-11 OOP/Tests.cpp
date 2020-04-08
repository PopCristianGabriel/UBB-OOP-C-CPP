#include "Tests.h"



Tests::Tests()
{
}

void Tests::test_all()
{
	this->test_evidence();
	this->test_controller();
}

void Tests::test_evidence()
{
	evidence evidence2;
	evidence evError;
	char userInput[100];
	char userInput2[100];
	char userInput3[100];
	strcpy(userInput3, "add 12sd24, 22X33X44, 11.3, 20");
	strcpy(userInput, "add 12sd23, 23X12X10, 2313, 25, DSC13241.jpg");
	strcpy(userInput2, "add 12sd23, 23X12X10, 2313, 25, DSC13241.jpg");
	evidence evidence = make_an_evidence(userInput);
	evidence2 = make_an_evidence(userInput2);
	assert (1 == 1);
	assert(!strcmp(evidence.get_evidence_id() , "12sd23"));
	assert(evidence.get_evidence_image_clarity() == 2313.00000);
	assert(!strcmp(evidence.get_evidence_measurement(), "23X12X10"));
	assert(!strcmp(evidence.get_evidence_photograph(), "DSC13241.jpg"));
	assert(evidence.get_evidence_quantity() == 25);
	char change[10];
	strcpy(change, "dawd");
	evidence.set_evidence_id(change);
	assert(!strcmp(evidence.get_evidence_id(), "dawd"));
	evidence.set_evidence_image_clarity(33);
	assert(evidence.get_evidence_image_clarity() == 33);
	evidence.set_evidence_measurement(change);
	assert(!strcmp(evidence.get_evidence_measurement(), "dawd"));
	evidence.set_evidence_photograph(change);
	assert(!strcmp(evidence.get_evidence_photograph(), "dawd"));
	evidence.set_evidence_quantity(33);
	assert(evidence.get_evidence_quantity() == 33);

	assert(check_same_evidences(evidence, evidence2) == 0);

	try {
		evError = make_an_evidence(userInput3);
	}
	catch (const char* error) {
		cout << error;
	}
	strcpy(userInput, "add 12sd24, 22X33X44, 11.q3, 20, dawd.jpg");
	try {
		evError = make_an_evidence(userInput);
	}
	catch (const char* error) {
		cout << error;
	}


	
}

void Tests::test_controller()
{

	evidence evidence2;
	repositoryFake rep1{};
	repositoryFake rep2{};
	controler controller(&rep1, &rep2);
	vector<evidence> v = controller.get_saves();
	v = controller.get_list_by_index();
	char userInput[100];
	char userInput2[100];
	strcpy(userInput, "add 12sd23, 23X12X10, 2313, 25, DSC13241.jpg");
	strcpy(userInput2, "add 12sd25, 22X33X44, 14, 15, dawd22.jpg");
	assert(controller.get_saves_size() == 0);
	assert(controller.get_size_of_list() == 0);
	evidence evidence = make_an_evidence(userInput);
	 evidence2 = make_an_evidence(userInput2);
	assert(controller.controler_add(evidence) == 1);
	assert(controller.controler_add(evidence) == 0);
	assert(controller.controler_update(evidence2) == 0);
	strcpy(userInput2, "add 12sd23, 22X33X44, 14, 15, dawd22.jpg");
	evidence2 = make_an_evidence(userInput2);
	assert(controller.controler_update(evidence2) == 1);
	strcpy(userInput, "12sd23");
	assert(controller.controler_delete(userInput) == 1);
	assert(controller.controler_delete(userInput) == 0);
	strcpy(userInput, "12sd23");
	controller.controler_add(evidence);
	assert(controller.controller_save_evidence_with_id(userInput) == 1);
	strcpy(userInput, "dawd");
	assert(controller.controller_save_evidence_with_id(userInput) == 0);
	
}


Tests::~Tests()
{
}
