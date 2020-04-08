#include "lab12.h"

using namespace std;

char mode = 'A';

char* QString_to_char(QString string) {
	char idToChar[20];
	QByteArray ba = string.toLocal8Bit();
	strcpy(idToChar, ba.data());
	return idToChar;
}


userInterface::userInterface(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	myUi.set_fileRepository_path("C:\\Users\\Pop\\source\\repos\\QtGuiApplication3\\QtGuiApplication3\\myRepo.txt");
	myUi.populate_from_file();
	this->listBIndex = 0;


	

	//to conect the button to that function
	connect(this->ui.listButton, SIGNAL(clicked()), this, SLOT(listAll()));
	connect(this->ui.addButton, SIGNAL(clicked()), this, SLOT(add_to_table()));
	connect(this->ui.UpdateButton, SIGNAL(clicked()), this, SLOT(update_the_table()));
	connect(this->ui.removeButton, SIGNAL(clicked()), this, SLOT(remove_evidence()));
	connect(this->ui.modeButton, SIGNAL(clicked()), this, SLOT(change_mode()));
	connect(this->ui.nextButton, SIGNAL(clicked()), this, SLOT(next()));
	connect(this->ui.myListButton, SIGNAL(clicked()), this, SLOT(print_saves()));
	connect(this->ui.saveIdButton, SIGNAL(clicked()), this, SLOT(save()));
	connect(this->ui.filterButton, SIGNAL(clicked()), this, SLOT(filter()));
}


evidence userInterface :: make_evidence_from_textbox() {
	QString Id = this->ui.textBoxId->text();
	QString Measurement = this->ui.textBoxMeasurement->text();
	QString	Photograph = this->ui.textBoxPhotograph->text();
	QString Quantity = this->ui.textBoxQuantity->text();
	//Quantity = Quantity.toInt;
	QString imageClarity = this->ui.textBoxImageClarity->text();
	//imageClarity = imageClarity.toFloat;
	evidence evidenceToAdd;


	bool ok = false;
	char idToAdd[20];
	strcpy(idToAdd, QString_to_char(Id));

	evidenceToAdd.set_evidence_id(idToAdd);
	evidenceToAdd.set_evidence_image_clarity(imageClarity.toFloat(&ok));
	char measurementToAdd[20];
	strcpy(measurementToAdd, QString_to_char(Measurement));
	evidenceToAdd.set_evidence_measurement(measurementToAdd);

	char photographToAdd[20];
	strcpy(photographToAdd, QString_to_char(Photograph));
	evidenceToAdd.set_evidence_photograph(photographToAdd);
	evidenceToAdd.set_evidence_quantity(Quantity.split(" ")[0].toInt());
	return evidenceToAdd;
}




void userInterface::listAll()
{
	if (mode == 'A') {
		vector<evidence> evidences = this->myUi.ui_get_list_of_evidences();
		this->ui.listWidget->clear();
		for (int index = 0; index < this->myUi.get_repository_size(); index++)
		{
			char stringImageClarity[10], stringQuantity[20];

			sprintf(stringImageClarity, "%f", evidences[index].get_evidence_image_clarity());
			sprintf(stringQuantity, "%d", evidences[index].get_evidence_quantity());
			QListWidgetItem* item = new QListWidgetItem(((new QString(evidences[index].get_evidence_id()) + *(new QString(" ")) + *(new QString(stringImageClarity))) + *(new QString(" ")) + (new QString(evidences[index].get_evidence_measurement()) + *(new QString(" ")) + *(new QString(evidences[index].get_evidence_photograph()))) + *(new QString(" ")) + *(new QString(stringQuantity))));
			this->ui.listWidget->addItem(item);



		}
		this->ui.listWidget->show();
	}
}







void userInterface::add_to_table()
{
	evidence evidenceToAdd = this->make_evidence_from_textbox();

	bool save = true;
	try {
		this->controller.controler_add(evidenceToAdd);
	}
	catch (MyException2 exception) {
		save = false;
	}
	if (save) {
		this->myUi.save_into_file();
	}
	

	//this->vL->removeWidget(Evidences);
	//delete this->Evidences;
	//this->Evidences = new QTableWidget{ this->ui.get_repository_size(),5 };
	//this->vL->addWidget(Evidences);
	this->listAll();
	
	cout << "dawd";



	
}

void userInterface::update_the_table()
{
	evidence evidenceToUpdate = this->make_evidence_from_textbox();
	this->myUi.ui_update(evidenceToUpdate);
	this->myUi.save_into_file();
	this->listAll();
	

}

void userInterface::remove_evidence()
{
	if (mode != 'A') {
		return;
	}
	QString Id = this->ui.textBoxId->text();
	char idToRemove[20];
	strcpy(idToRemove, QString_to_char(Id));
	this->myUi.remove(idToRemove);
	this->myUi.save_into_file();
	this->listAll();
}

void userInterface::change_mode()
{
	if (mode == 'A') {
		mode = 'B';
		this->ui.modeButton->setText("Mode B");
		return;
	}
	mode = 'A';
	this->ui.modeButton->setText("Mode A");
}

void userInterface::save()
{
	if (mode != 'B') {
		return;
	}
	QString Id = this->ui.idToSaveLine->text();
	char idToSave[20];
	strcpy(idToSave, QString_to_char(Id));
	this->myUi.save_evidence_into_saves(idToSave);

}

void userInterface::print_saves()
{
	if (mode != 'B') {
		return;
	}
	vector<evidence> evidences = this->myUi.get_list_of_saves();
	this->ui.modeBList->clear();
	for (int index = 0; index < this->myUi.get_myList_size(); index++)
	{
		char str[10], str2[20];

		sprintf(str, "%f", evidences[index].get_evidence_image_clarity());
		sprintf(str2, "%d", evidences[index].get_evidence_quantity());
		QListWidgetItem* item = new QListWidgetItem(((new QString(evidences[index].get_evidence_id()) + *(new QString(" ")) + *(new QString(str))) + *(new QString(" ")) + (new QString(evidences[index].get_evidence_measurement()) + *(new QString(" ")) + *(new QString(evidences[index].get_evidence_photograph()))) + *(new QString(" ")) + *(new QString(str2))));
		this->ui.modeBList->addItem(item);



	}
	this->ui.modeBList->show();

}

void userInterface::next()
{	
	if (mode != 'B') {
		return;
	}
	this->increase_list_index();
	this->list_an_evidence(this->myUi.get_list_of_evidences(), this->listBIndex);
}

void userInterface::filter()
{
	this->ui.modeBList->clear();
	QString measurement = this->ui.measurementFilterTextBox->text();
	QString quantity = this->ui.quantityFilterTextBox->text();
	char charMeasurement[20];
	char charQuantity[20];

	strcpy(charMeasurement,QString_to_char(measurement));
	strcpy(charQuantity, QString_to_char(quantity));
	int numberQuantity = atoi(charQuantity);

	vector<evidence> evidences = this->myUi.get_list_of_evidences();

	for (int index = 0; index < this->myUi.get_repository_size(); index++) {
		if (!strcmp(charMeasurement, evidences[index].get_evidence_measurement()) && numberQuantity <= evidences[index].get_evidence_quantity()) {
			char stringImageClarity[10], stringQuantity[20];

			sprintf(stringImageClarity, "%f", evidences[index].get_evidence_image_clarity());
			sprintf(stringQuantity, "%d", evidences[index].get_evidence_quantity());
			QListWidgetItem* item = new QListWidgetItem(((new QString(evidences[index].get_evidence_id()) + *(new QString(" ")) + *(new QString(stringImageClarity))) + *(new QString(" ")) + (new QString(evidences[index].get_evidence_measurement()) + *(new QString(" ")) + *(new QString(evidences[index].get_evidence_photograph()))) + *(new QString(" ")) + *(new QString(stringQuantity))));
			this->ui.modeBList->addItem(item);
		}
	}


}

void userInterface::increase_list_index()
{
	int sizeOfList = this->myUi.get_repository_size();
	this->listBIndex++;
	if (sizeOfList == listBIndex) {
		listBIndex = 0;
		return;
	}

}

void userInterface::list_an_evidence(vector<evidence> listOfEvidences,int index)
{
	this->ui.modeBList->clear();

	char str[10], str2[20];

	sprintf(str, "%f", listOfEvidences[index].get_evidence_image_clarity());
	sprintf(str2, "%d", listOfEvidences[index].get_evidence_quantity());
	QListWidgetItem* item = new QListWidgetItem(((new QString(listOfEvidences[index].get_evidence_id()) + *(new QString(" ")) + *(new QString(str))) + *(new QString(" ")) + (new QString(listOfEvidences[index].get_evidence_measurement()) + *(new QString(" ")) + *(new QString(listOfEvidences[index].get_evidence_photograph()))) + *(new QString(" ")) + *(new QString(str2))));
	this->ui.modeBList->addItem(item);
	this->ui.modeBList->show();
}


