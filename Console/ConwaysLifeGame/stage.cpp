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
				if(mapData->getData(x, y) && 0x01) {
					this->dqCoordCellX.push_back(x);
					this->dqCoordCellY.push_back(y);
				}
			}
		}
		printf("Scanning is finished!\n");
	}
}

void ClgStage::start(void) {
	//���� �ε��ϰ� �ʱ�ȭ�ϴ� �ܰ�
	
	char mapName[100];

	// �� ���� ���� �ʱ�ȭ
	this->initStageState();

	int openMapAns = guiYNQuestion("���� ���� �ҷ��ñ��?");

	if(openMapAns == ANSWER_YES) {		// ���� �� �ҷ�����
		printf("���� ���� �ҷ��ɴϴ�.");
		
		sscanf(mapName, "%s", guiYNQuestion("�� ���ϸ��� �Է����ּ���"));
		this->initMap.setName(mapName);			// �̸� ����
		this->initMap.clearData();				// �� ������ �ʱ�ȭ
		this->initMap.loadData();				// �� ������ �ҷ�����
		this->scanCellData(&(this->initMap));	// ����ִ� �� ��ĵ (ť)
	}
	else if(openMapAns == ANSWER_NO) {	// �ű� �� �ۼ�
		printf("�ű� ���� �ۼ��մϴ�.\n");
		fflush(stdin);
		guiInputString(mapName, "�ű� ���� �̸��� �Է����ּ���");
		this->initMap.setName(mapName);			// �̸� ����
		this->initMap.clearData();				// �� ������ �ʱ�ȭ
	}
	else {								// ����
		printf("�ý��ۿ� ������ �ֽ��ϴ�. ���α׷��� �����մϴ�. - Stage Initialize Error\n");
		exit(0);
	}

	// �� ���ۿ� ���� ���� �ʱ� ������ �ۼ�
	this->state = 0x01;
	for(int i = 0; i < 2; i++) {
		this->stageMapBuf[i].clearData();
	}

	// �� ũ�� ����
	changeWindowSize(66, 33);
	
	// �ʱ� �� ���
	printMap(this->initMap);
}

void ClgStage::stop(void) {
	// �������� ������ �ߴ��ϰ� ���� ����� �Ǵ� ���Ḧ �ϱ� ���� �غ� �ϴ� �ܰ�
}

void ClgStage::update(void) {
	// ������ �����ϴ� �ܰ�
	// ó������ Queue�� �־ for�� �ּ������� �ҷ��� �ߴµ�
	// ���� ���� ������ ���� �ľ��ؾ� �ؼ� Scan ����� ����������. ��ĵ�� �� �� �� �� �� �ֵ��� �ؾ��Ѵ�.
	// ���� ������Ʈ ���߿��� ������ üũ�� ���� ����ؾ� �ϴµ� �̰͵� ����� ���� �� �� ����.
	deque<unsigned int>::iterator iterCoordX = this->dqCoordCellX.begin();
	deque<unsigned int>::iterator iterCoordY = this->dqCoordCellY.begin();
	int cntLiveCell = 0;

	// ���� �߻�: ������ ���� ���� �ִ�.
	while(iterCoordX != this->dqCoordCellX.end() && iterCoordY != this->dqCoordCellY.end()) {
		cntLiveCell = 0;
		for(int y = *iterCoordY - 1; y <= *iterCoordY + 1; y++) {
			for(int x = *iterCoordX - 1; x <= *iterCoordX + 1; x++) {
				if(*iterCoordY >= 0 && *iterCoordX >= 0 && *iterCoordY < this->initMap.getHeight() && *iterCoordX < this->initMap.getWidth()) {
					cntLiveCell += (this->stageMapBuf[this->getMapBufferId()].getData(x, y) & 0x01);
				}
				cntLiveCell -= (this->stageMapBuf[this->getMapBufferId()].getData(*iterCoordX, *iterCoordY) & 0x01);
			}
		}
		if(this->stageMapBuf[this->getMapBufferId()].getData(*iterCoordX, *iterCoordY) & 0x01) {
			if(cntLiveCell == 2 || cntLiveCell == 2) {
				
			}
		}
	}
}