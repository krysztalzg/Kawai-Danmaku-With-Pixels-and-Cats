#pragma once
#include "State.h"
#include "FlyingObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Bonus.h"
#include "Collision.h"

enum gameTexts{ SCORE, SCORE_V, LIFE, LIFE_V, POWER, POWER_V, SPECIAL, SPECIAL_V, GRAZE, GRAZE_V };

class GameState : public State {
private:;
	vector<GameText*> gameTexts;

	TextureManager* texManager;

	float pos_x;
	float pos_y[3];
	float scrollSpeed;

	int gameTime;

	vector<FlyingObject*> objects;
	vector<Bullet*> bullets;

	void initTexts();
	void updateTexts();
	void initSprites(TextureManager*);

	void scrollBG();

public:
	void handleEvent(Event*, StateManager*);
	void update(StateManager*);
	void draw(RenderWindow*);

	GameState(Font, TextureManager*);
	virtual ~GameState();
};

