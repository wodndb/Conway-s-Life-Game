#include "stage.h"
#include "gui.h"
#include <Windows.h>

void ClgStage::initStageState(void) {
	this->state = 0x00;
}

int ClgStage::getMapBufferId(void) {
	return this->getState() & STATE_MAP_BUFFER_ID;	// == & 0x01
}

int ClgStage::getNextMapBufferId(void) {
	// == & 0x01 ^ 0x01 --> 0 OR 1
	return ( this->getState() & STATE_MAP_BUFFER_ID ) ^ STATE_MAP_BUFFER_ID;
}

void ClgStage::swapMapBufferId(void) {
	this->setState(this->getState() ^ STATE_MAP_BUFFER_ID);	// Just toggle first bit of state
}

void ClgStage::scanCellData(ClgMap* mapData) {
	if(mapData == NULL) {
		printf("map data is null pointer, exit this program!\n");
		exit(0);
	}
	else {
		printf("Scanning cell data..\n");
		int width = mapData->getWidth();
		int height = mapData->getHeight();
		for(int y = 0; y < height; y++) {
			for(int x = 0; x < width; x++) {
				if(mapData->getData(x, y) == 1) {
					this->dqCoordCellX.push_back(x);
					this->dqCoordCellY.push_back(y);
				}
			}
		}
		printf("Scanning is finished!\n");
	}
}

void ClgStage::start(void) {
	//맵을 로드하고 초기화하는 단계
	
	char mapName[100];

	// 맵 상태 정보 초기화
	this->initStageState();

	int openMapAns = guiYNQuestion("기존 맵을 불러올까요?");

	if(openMapAns == ANSWER_YES) {		// 기존 맵 불러오기
		printf("기존 맵을 불러옵니다.");
		
		sscanf(mapName, "%s", guiYNQuestion("맵 파일명을 입력해주세요"));
		this->initMap.setName(mapName);			// 이름 저장
		this->initMap.clearData();				// 맵 데이터 초기화
		this->initMap.loadData();				// 맵 데이터 불러오기
		this->scanCellData(&(this->initMap));	// 살아있는 셀 스캔 (큐)
	}
	else if(openMapAns == ANSWER_NO) {	// 신규 맵 작성
		printf("신규 맵을 작성합니다.\n");
		fflush(stdin);
		guiInputString(mapName, "신규 맵의 이름을 입력해주세요");
		this->initMap.setName(mapName);			// 이름 저장
		this->initMap.clearData();				// 맵 데이터 초기화
	}
	else {								// 에러
		printf("시스템에 오류가 있습니다. 프로그램을 종료합니다. - Stage Initialize Error\n");
		exit(0);
	}

	// 맵 버퍼에 현재 맵의 초기 정보를 작성
	this->state = 0x01;
	for(int i = 0; i < 2; i++) {
		this->stageMapBuf[i].clearData();
	}

	// 맵 크기 변경
	changeWindowSize(66, 33);
	
	// 초기 맵 출력
	printMap(this->initMap);
}

void ClgStage::stop(void) {
	// 진행중인 게임을 중단하고 게임 재시작 또는 종료를 하기 위한 준비를 하는 단계
}

void ClgStage::update(void) {
	// 게임을 진행하는 단계
	deque<unsigned int>::iterator iterCoordX = this->dqCoordCellX.begin();
	deque<unsigned int>::iterator iterCoordY = this->dqCoordCellY.begin();

	// 문제 발생: 음수가 나올 수가 있다.
	while(iterCoordX != this->dqCoordCellX.end() && iterCoordY != this->dqCoordCellY.end()) {
		for(int y = *iterCoordY - 1; y <= *iterCoordY + 1; y++) {
			for(int x = *iterCoordX - 1; x <= *iterCoordX + 1; x++) {
				if(*iterCoordY >= 0 && *iterCoordX >= 0 && *iterCoordY < this->initMap.getHeight() && *iterCoordX < this->initMap.getWidth()) {
					
				}
			}
		}
	}
}