#include "gui.h"
#include <Windows.h>

void gotoxy(int x, int y)
{
    COORD Cur;
    Cur.X = x;
    Cur.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void printMap(ClgMap &map) {
	system("cls");
	for(unsigned int y = 0; y < map.getHeight(); y++) {
		for(unsigned int x = 0; x < map.getWidth(); x++) {
			if(*(*(map.getData() + y) + x) == 1) {
				printf("■");
			}
			else if(*(*(map.getData() + y) + x) == 0) {
				printf("□");
			}
			else {
				printf("??");
			}
		}
		printf("\n");
	}
}

void changeWindowSize(int width, int height) {
	char cmdChar[100];
	if(width > 0 && height > 0) {
		sprintf(cmdChar, "mode con:cols=%d lines=%d", width, height);
		system(cmdChar);
	}
	else {
		printf("윈도우 창의 크기는 0보다 커야 합니다.\n");
	}
}

char* guiInputString(char* target, char* message) {
	if(target != NULL) {
		system("cls");
		printf("%s\n", message);
		printf(">");
		scanf("%s", target);
	}
	else {
		target = NULL;
	}

	return target;
}

int guiYNQuestion(char* message) {
	char yn;
	system("cls");
	printf("%s\n", message);
	printf(">");
	scanf("%c", &yn);

	if(yn == 'y' || yn == 'Y') {
		return ANSWER_YES;
	}
	else if(yn == 'n' || yn == 'N') {
		return ANSWER_NO;
	}
	else {
		return ANSWER_ERR;
	}
}