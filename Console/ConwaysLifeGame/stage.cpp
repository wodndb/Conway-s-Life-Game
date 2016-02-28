#include "stage.h"
#include "gui.h"
#include <Windows.h>

void ClgStage::start(void) {
	//���� �ε��ϰ� �ʱ�ȭ�ϴ� �ܰ�
	
	char mapName[100];
	int openMapAns = guiYNQuestion("���� ���� �ҷ��ñ��?");
	if(openMapAns == ANSWER_YES) {
		printf("���� ���� �ҷ��ɴϴ�.");
		
		sscanf(mapName, "%s", guiYNQuestion("�� ���ϸ��� �Է����ּ���"));
		this->initMap.setName(mapName);
		this->initMap.clearData();
		this->initMap.loadData();
	}
	else if(openMapAns == ANSWER_NO) {
		printf("�ű� ���� �ۼ��մϴ�.\n");
		fflush(stdin);
		guiInputString(mapName, "�ű� ���� �̸��� �Է����ּ���");
		this->initMap.setName(mapName);
		this->initMap.clearData();
	}
	else {
		printf("�ý��ۿ� ������ �ֽ��ϴ�. ���α׷��� �����մϴ�. - Stage Initialize Error\n");
		exit(0);
	}

	// �� ���ۿ� ���� ���� �ʱ� ������ �ۼ�
	this->state = 0x01;

	changeWindowSize(66, 33);
	printMap(this->initMap);
	
}

void ClgStage::stop(void) {
	// �������� ������ �ߴ��ϰ� ���� ����� �Ǵ� ���Ḧ �ϱ� ���� �غ� �ϴ� �ܰ�
}

void ClgStage::update(void) {
	// ������ �����ϴ� �ܰ�
}