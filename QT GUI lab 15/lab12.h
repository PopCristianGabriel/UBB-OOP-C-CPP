#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGuiApplication3.h"
//#include "ui_lab1112.h"
#include "UI.h"
#include "repository.h"
#include"Controler.h"
#include "evidence.h"
#include <qtablewidget.h>
#include <QtWidgets/QApplication>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QVboxLayout>
#include<QFormLayout>
#include<QTableWidget>
#include<QGridLayout>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

class userInterface : public QMainWindow
{
	Q_OBJECT

public:
	userInterface(QWidget *parent = Q_NULLPTR);
	
private slots:
	void listAll();
	void add_to_table();
	void update_the_table();
	void remove_evidence();
	void change_mode();
	void save();
	void print_saves();
	void next();
	void filter();
private:
	int listBIndex;
	void increase_list_index();
	void list_an_evidence(vector<evidence> listOfEvidences,int index);

	
	repository repositoryInput;
	repository repositoryMyList;
	//myList MYLIST{};
	controler controller{ &repositoryInput,&repositoryMyList};
	UI myUi{ &controller };
	Ui::QtGuiApplication3Class ui;
	evidence make_evidence_from_textbox();
};
