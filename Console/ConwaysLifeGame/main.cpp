#include <stdio.h>
#include <conio.h>
#include "gui.h"
#include "stage.h"

int main(void) {
	printf("Hello! This is Conway's Life Game!");

	ClgStage cs;

	cs.start();

	//ClgMap map(4, 4);
	//printMap(map);
	////printf("%d", map.saveData(SAVE_MAP_OVERLAY));
	//printf("%d", map.loadData());
	//printMap(map);

	getch();

	return 0;
}