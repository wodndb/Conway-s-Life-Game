#ifndef CLG_GUI_H
#define CLG_GUI_H

#include "map.h"

void gotoxy(int x, int y);
void printMap(ClgMap &map);
void changeWindowSize(int width, int height);

#endif /*CLG_GUI_H*/