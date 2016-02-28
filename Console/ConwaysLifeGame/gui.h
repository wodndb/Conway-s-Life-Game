#ifndef CLG_GUI_H
#define CLG_GUI_H

#define ANSWER_YES	0x01
#define ANSWER_NO	0x02
#define ANSWER_ERR	-1

#include "map.h"

void gotoxy(int x, int y);
void printMap(ClgMap &map);
void changeWindowSize(int width, int height);
int guiYNQuestion(char* message);
char* guiInputString(char* target, char* message);

#endif /*CLG_GUI_H*/