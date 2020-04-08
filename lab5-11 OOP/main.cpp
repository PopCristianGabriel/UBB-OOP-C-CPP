#pragma once

//#include "UI.h"
#include "Tests.h"



int main() {
	Tests t;
	//t.test_all();
	repositoryFake repositorySaves{};
	repositoryFake repository{};
	controler controller(&repository,&repositorySaves);
	//UI ui();
	//cout << ui;
	UI ui(&controller);
	ui.menu();
	return 0;

	
}