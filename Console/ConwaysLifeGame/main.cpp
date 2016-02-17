#include <stdio.h>
#include <conio.h>
#include "gui.h"

int main(void) {
	printf("Hello! This is Conway's Life Game!");
	ClgMap map(4, 4);
	printMap(map);
	//printf("%d", map.saveData(SAVE_MAP_OVERLAY));
	printf("%d", map.loadData());
	printMap(map);

	getch();

	return 0;
}