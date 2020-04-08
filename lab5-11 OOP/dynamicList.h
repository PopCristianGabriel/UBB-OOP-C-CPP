#pragma once
#include "evidence.h"
#include <stdlib.h>
#include <iostream>
#include "exceptions.cpp"
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include "File.h"
using namespace std;
template <typename object>
class dynamicList {
private:
	//object* evidenceList;
	//int size;
	//int maximumSize;
	vector<object> evidenceList;
public:

	dynamicList();
	~dynamicList();


	int get_evidence_position(object evidence);
	int get_position_by_id(char * idToFind);
	vector<object> get_evidence_list();
	int get_evidence_list_size();
	int dynamicList_add_to_list(object newEvidence);
	int dynamicList_delete_evidence(char* idToDelete);
	int dynamicList_add_element_by_id(dynamicList originalList, char* idToSave);
	int dynamicList_update_evidence(object newEvidence);


	

	object& operator[](int position);
};
	template<typename object>
	int dynamicList<object>::get_evidence_position(object evidenceToCheck)
	{
		int i = 0;
		for (evidence evidenceFromList : this->get_evidence_list()) {
			if (check_same_evidences(evidenceFromList, evidenceToCheck))
				return i;
			
			i++;
		}

		//for (int i = 0; i < this->get_evidence_list_size(); i++) {
		//	if (check_same_evidences(evidence, this->get_evidence_list()[i]))
		//		return i;
		//}
		return -1;
	}
	template<typename object>
	int dynamicList<object>::get_position_by_id(char * idToFind)
	{
		int i = 0;
		for (evidence evidence : this->get_evidence_list()) {
			if (strcmp(evidence.get_evidence_id(), idToFind) == 0) {
				return i;
			}
			i++;
		}

		//for (int i = 0; i < this->get_evidence_list_size(); i++) {
			//if (strcmp(this->get_evidence_list()[i].get_evidence_id(), idToFind) == 0) {
				//return i;
			//}
		//}
		return -1;
	}

	template<typename object>
	vector<object> dynamicList<object>::get_evidence_list()
	{
		return this->evidenceList;
	}
	template<typename object>
	int dynamicList<object>::get_evidence_list_size()
	{
		return this->evidenceList.size();
	}
	
	template<typename object>
	int dynamicList<object>::dynamicList_add_to_list(object newEvidence)
	{
		MyException2 exception("add error", "dynamicList.h",86 ,"dynamicList_add_to_list", "exception Popu");
		if (this->get_evidence_position(newEvidence) != -1) {
			throw exception;
			cout << "DAWD";
		}

		/*if (this->get_evidence_list_size() == this->get_maximum_size()) {
			this->realocate_dynamicList();
		}*/
		this->evidenceList.push_back(newEvidence);
		return 1;
	}

	template<typename object>
	int dynamicList<object>::dynamicList_delete_evidence(char * idToDelete)
	{
		evidence evidenceCopy;
		evidenceCopy.set_evidence_id(idToDelete);
		int positonOfEvidence = this->get_evidence_position(evidenceCopy);
		if (positonOfEvidence == -1) {
			throw "delete";
		}
		this->evidenceList.erase(this->evidenceList.begin() + positonOfEvidence);
		return 1;
	}
	template<typename object>
	int dynamicList<object>::dynamicList_add_element_by_id(dynamicList originalList, char * idToSave)
	{
		int positionInOriginal = originalList.get_position_by_id(idToSave);
		if (positionInOriginal == -1) {
			throw "add";
		}
		if (this->get_position_by_id(idToSave) != -1)
		{
			throw "add";
		}
		this->evidenceList.push_back(originalList.evidenceList[positionInOriginal]);
		return 1;
	}

	template<typename object>
	int dynamicList<object>::dynamicList_update_evidence(object newEvidence)
	{
		int posisitionOfOldEvidence = this->get_evidence_position(newEvidence);
		if (posisitionOfOldEvidence == -1) {
			throw "update";
		}
		this->evidenceList[posisitionOfOldEvidence] = newEvidence;
		return 1;
	}
	
	template<typename object>
	dynamicList<object>::dynamicList()
	{
		std::cout << this->evidenceList.size();
		
		
	}

	template<typename object>
	inline dynamicList<object>::~dynamicList()
	{
		
	}

	

	template<typename object>
	inline object & dynamicList<object>::operator[](int position)
	{
		return this->evidenceList.at(position);
	}





