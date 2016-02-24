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
				printf("��");
			}
			else if(*(*(map.getData() + y) + x) == 0) {
				printf("��");
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
		printf("������ â�� ũ��� 0���� Ŀ�� �մϴ�.\n");
	}
}

char* guiInputString(char* message) {
	char buf[100];
	system("cls");
	printf("%s\n", message);
	printf(">");
	scanf("%s", buf);

	return buf;
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