////
// Programmer Information
// Korea University of Technology and Education (South Korea)
// School of Computer Science and Engineering
// 2012136116 Jeong, Jaeu
// wodndb@koreatech.ac.kr

////
// file  :	map.h
// brief :	class ClgStage is defined Game stage.

#ifndef CLG_STAGE_H
#define CLG_STATE_H

////
//
// Stage Register Information
//
// 忙式式式式式式式忖
// 弛    state     弛
// 戍式式式式式式式扣
// 弛      0       弛
// 戍式式式式式式式扣
// 弛  Buffer ID   弛
// 戌式式式式式式式戎
//

#define STATE_MAP_BUFFER_ID 0x01

#include "map.h"
#include <deque>
#include <iostream>

using namespace std;

class ClgStage {
private:
	ClgMap initMap;
	ClgMap stageMapBuf[2];
	int state;
	deque<unsigned int> dqCoordCellX;
	deque<unsigned int> dqCoordCellY;

	int count;
	
public:
	ClgStage(void): initMap(32, 32) {
		this->stageMapBuf[0].setClgMap(32, 32);
		this->stageMapBuf[1].setClgMap(32, 32);
	}
	~ClgStage(void) {}

	int getState(void) {return this->state;}
	void setState(int _state) {this->state = _state;}

	void initStageState(void);

	int getMapBufferId(void);
	int getNextMapBufferId(void);
	void swapMapBufferId(void);

	void start(void);
	void scanCellData(ClgMap* mapData);

	void stop(void);
	void update(void);
};

#endif /*CLG_STATE_H*/