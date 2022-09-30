#pragma once

#include "player.h"
#include "car.h"

class ScenMain
{
public:
	ScenMain();
	virtual ~ScenMain();

	// �����������A�I������
	void init();
	void end();

	// �Q�[������
	void update();
	// �`��
	void draw();

private:
	// �O���t�B�b�N�n���h��
	int m_hPlayer;
	int m_hCar;


	Player m_player;
	Car m_car;
};
