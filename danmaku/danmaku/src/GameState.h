#pragma once
#include "State.h"
#include "Player.h"
#include "GameText.h"

enum stats{ SCORE, SCORE_V, LIFE, LIFE_V, POWER, POWER_V, SPECIAL, SPECIAL_V, GRAZE, GRAZE_V };


class GameState : public State {
private:
	Font font, symbols;
	vector<GameText*> gameTexts;

	float pos_y1, pos_y2, pos_y3, pos_x;
	int bg1, bg2, bg3;

	Player* player;

	void initTexts();
	void updateTexts();
	void scrollBG();
public:
	void handleEvent(Event*, StateManager*);
	void update();
	void draw(RenderWindow*, vector<Sprite>*);

	GameState(Font);
	virtual ~GameState();
};

