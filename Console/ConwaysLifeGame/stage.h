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

#include "map.h"

class ClgStage {
private:
	ClgMap initMap;
	ClgMap stageMapA;
	ClgMap stageMapB;
	int state;
	int count;

	ClgStage(void) {
		
	}

	void start(void);
	void stop(void);
	void update(void);
};

#endif /*CLG_STATE_H*/