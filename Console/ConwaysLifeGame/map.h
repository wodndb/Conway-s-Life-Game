//**************************************************************************
// Programmer Information
// Korea University of Technology and Education (South Korea)
// School of Computer Science and Engineering
// 2012136116 Jeong, Jaeu
// wodndb@koreatech.ac.kr
//**************************************************************************

//**************************************************************************
// file  :	map.h
// brief :	class ClgMap - that mean Conway's Life Game Map - is defined map
//			data for managing cell data and map memory, and so on.
//**************************************************************************

#ifndef CLG_MAP_H
#define CLG_MAP_H

//**************************************************************************
// MACRO SET
//**************************************************************************
#define SAVE_MAP_NORMAL		0x01
#define SAVE_MAP_OVERLAY	0x02

//**************************************************************************
// HEADER FILES
//**************************************************************************
#include <stdio.h>
#include <string.h>

// This class manage data about map and cells
class ClgMap {
private:
	char name[50];			// Name of map

	unsigned int width;		// Width of map
	unsigned int height;	// Height of map
	char** data;	// Map data have cell data that be or not be.

public:
	//**********************************************************************
	// Constructor Set
	//**********************************************************************

	// Defualt Constructor
	ClgMap() {
		sprintf_s(name, "noname");
		this->width = 0;
		this->height = 0;
		this->data = NULL;
	}

	// Constructor with width and height of map
	ClgMap(unsigned int _width, unsigned int _height):width(_width), height(_height) {
		sprintf_s(name, "noname");

		this->data = new char*[this->height];
		for(unsigned int i = 0; i < this->height; i++) {
			this->data[i] = new char[this->width];
		}
		this->clearData();
	}

	// Constructor with with, height, name of map
	ClgMap(char* _name, unsigned int _width, unsigned int _height):width(_width), height(_height) {
		if(strlen(_name) == 0) {
			printf("�̸��� ���̴� 0���� Ŀ�� �մϴ�. ������ ���� ����\n");
		}
		else {
			sprintf_s(name, "%s", _name);

			this->data = new char*[this->height];
			for(unsigned int i = 0; i < this->height; i++) {
				this->data[i] = new char[this->width];
			}
			this->clearData();
		}
	}

	// Copy Constructor
	ClgMap(const ClgMap &o) {
		// Exception handling about name (stirng) length
		if(strlen(o.name) == 0) {
			printf("�̸��� ���̴� 0���� Ŀ�� �մϴ�. ���� ������ ���� ����\n");
		}
		else {
			sprintf_s(name, "%s", o.name);
			this->width = o.width;
			this->height = o.height;

			this->data = new char*[this->height];
			for(unsigned int i = 0; i < this->height; i++) {
				this->data[i] = new char[this->width];
				for(unsigned int j = 0; j < this->width; j++) {
					((this->data[i])[j]) = ((o.data[i])[j]);
				}
			}
		}
	}

	//**********************************************************************
	// Destructor
	//**********************************************************************
	~ClgMap() {
		if(this->data != NULL) {
			for(unsigned int y = 0; y < this->height; y++) {
				delete[] this->data[y];
			}
			delete[] this->data;
		}
	}

	//**********************************************************************
	// Get function set
	//**********************************************************************
	char* getName(void) { return (char*)this->name; }
	unsigned int getWidth(void) { return this->width; }
	unsigned int getHeight(void) { return this->height; }
	char** getData(void) { return this->data; }

	//**********************************************************************
	// Set function set
	//**********************************************************************
	void setName(char* _name) {
		if(strlen(_name) == 0) {
			printf("�̸��� ���̴� 0���� Ŀ�� �մϴ�. set�Լ� ���� ����\n");
		}
		else {
			sprintf_s(this->name, "%s", _name);
		}
	}
	void setWidth(unsigned int _width) { this->width = _width; }
	void setHeight(unsigned int _height) { this->height = _height; }
	void setData(char** _data) { this->data = _data; }

	//**********************************************************************
	// General perpose function set
	//**********************************************************************
	void clearData(void);
	int saveData(int mode);
	int loadData(void);
};

#endif /*CLG_MAP_H*/