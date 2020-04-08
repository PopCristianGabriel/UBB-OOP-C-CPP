#include <stdio.h>
#include "UI.h"


void dealocate_everything(UI* ui, controler* controller){
	free(controller);
	free(ui);
}

int main() {
	repository repository;
	
	init_repository(&repository);
	

	controler* controller = createControler(&repository);
	UI* ui = create_ui(controller);

	menu(ui);
	dealocate_repository(&repository);
	dealocate_everything(ui, controller);
	
}
	



