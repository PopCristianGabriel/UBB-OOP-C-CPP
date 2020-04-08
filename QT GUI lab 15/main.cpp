#include "QtGuiApplication3.h"
#include <QtWidgets/QApplication>
#include "lab12.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	userInterface ui;
	ui.show();

	
	
	return a.exec();
}
