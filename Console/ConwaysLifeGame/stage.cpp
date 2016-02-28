#include "stage.h"
#include "gui.h"
#include <Windows.h>

void ClgStage::start(void) {
	//맵을 로드하고 초기화하는 단계
	
	char mapName[100];
	int openMapAns = guiYNQuestion("기존 맵을 불러올까요?");
	if(openMapAns == ANSWER_YES) {
		printf("기존 맵을 불러옵니다.");
		
		sscanf(mapName, "%s", guiYNQuestion("맵 파일명을 입력해주세요"));
		this->initMap.setName(mapName);
		this->initMap.clearData();
		this->initMap.loadData();
	}
	else if(openMapAns == ANSWER_NO) {
		printf("신규 맵을 작성합니다.\n");
		fflush(stdin);
		guiInputString(mapName, "신규 맵의 이름을 입력해주세요");
		this->initMap.setName(mapName);
		this->initMap.clearData();
	}
	else {
		printf("시스템에 오류가 있습니다. 프로그램을 종료합니다. - Stage Initialize Error\n");
		exit(0);
	}

	// 맵 버퍼에 현재 맵의 초기 정보를 작성
	this->state = 0x01;

	changeWindowSize(66, 33);
	printMap(this->initMap);
	
}

void ClgStage::stop(void) {
	// 진행중인 게임을 중단하고 게임 재시작 또는 종료를 하기 위한 준비를 하는 단계
}

void ClgStage::update(void) {
	// 게임을 진행하는 단계
}