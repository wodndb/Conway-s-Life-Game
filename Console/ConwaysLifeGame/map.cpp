#include "map.h"

void ClgMap::clearData(void) {
	for(unsigned int y = 0; y < this->height; y++) {
		for(unsigned int x = 0; x < this->width; x++) {
			*(*(this->data + y) + x) = 0;
		}
	}
}

// 맵 데이터 저장
int ClgMap::saveData(int mode) {
	char fileName[55];
	FILE* fstream;
	sprintf(fileName, "%s.txt", this->name);
	fstream = fopen(fileName, "r");

	if(fstream == NULL || mode == SAVE_MAP_OVERLAY) {
		fstream = fopen(fileName, "w");
		fprintf(fstream, "%d %d\n", this->width, this->height);
		for(unsigned int y = 0; y < this->height; y++) {
			for(unsigned int x = 0; x < this->width; x++) {
				fprintf(fstream, "%d ", *(*(this->data + y) + x));
			}
			fprintf(fstream, "\n");
		}
	}

	else if(fstream != NULL) {
		return -1;
	}

	return 1;
}

int ClgMap::loadData(void) {
	char fileName[55];
	FILE* fstream;
	sprintf(fileName, "%s.txt", this->name);
	fstream = fopen(fileName, "r");
	if(fstream == NULL) {
		return -1;	// Fail roading data
	}
	else {
		fscanf(fstream, "%d %d", &this->width, &this->height);
		for(unsigned int y = 0; y < this->height; y++) {
			for(unsigned int x = 0; x < this->width; x++) {
				fscanf(fstream, "%d", (*(this->data + y) + x));
			}
		}
	}
}