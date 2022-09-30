#include "ScenMain.h"
#include "DxLib.h"
#include "game.h"

#include "player.h"
#include "car.h"

namespace
{
	// ’n–Ê‚Ì‚‚³
	constexpr int kFieldY = Game::kScreenHeight - 64;
}
ScenMain::ScenMain()
{
	m_hPlayer = -1;
	m_hCar = -1;
}

ScenMain::~ScenMain()
{

}

void ScenMain::init()
{
	m_hPlayer = LoadGraph("data/player.png");
	m_hCar = LoadGraph("data/car.png");

	m_player.setGraphic(m_hPlayer);
	m_player.setup(kFieldY);

	m_car.setGraphic(m_hCar);
	m_car.setup(kFieldY);
}

void ScenMain::end()
{
	DeleteGraph(m_hPlayer);
	DeleteGraph(m_hCar);
}

// ƒQ[ƒ€ˆ—
void ScenMain::update()
{
	m_player.update();
	m_car.update();

	// “–‚½‚è”»’è
	if (m_player.isCol(m_car))
	{
		m_player.setDead(true);
	}
	/*
	if (m_car.isRestart())
	{
		m_car.setup(kFieldY);
		m_player.setDead(false);
	}
	*/
}
// •`‰æ
void ScenMain::draw()
{
	// ’n–Ê‚Ì•`‰æ
	DrawLine(0, kFieldY, Game::kScreenWidth, kFieldY, GetColor(255, 255, 255));
	m_player.draw();
	m_car.draw();

}
