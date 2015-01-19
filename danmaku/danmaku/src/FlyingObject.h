#pragma once
#include "Includes.h"
#include "Bullet.h"
#include "TextureManager.h"

class FlyingObject {
protected:
	Sprite sprite;
	TextureManager* texManager;

	bool live, shooting;

	char type;				//p - player, b - bonus, e - enemy
	int id;
	int life, power, score, graze, special;

	float pos_x, pos_y;
	float hitbox_pos_x, hitbox_pos_y, hitbox_r;
	float speed_x, speed_y;

	CircleShape hitbox;

	int fireTime, currentTime;

	virtual void shoot();
	virtual void move();

	vector<Bullet*>* bullets;
public:

	virtual void handleEvent(Event*);
	virtual int update();
	virtual void draw(RenderWindow*) = 0;

	float getPosX();
	float getPosY();
	float getHitboxPosX();
	float getHitboxPosY();
	float getHitboxR();

	bool getLive();
	void setLive(bool);

	bool getShooting();
	void setShooting(bool);

	void inreasePower();

	void setId(int);
	int getId();

	char getType();

	FlyingObject();
	virtual ~FlyingObject();
};

