#include "Player.h"

void Player::handleEvent(Event* event) {
	if (event->type == Event::KeyPressed)
		switch (event->key.code) {
		case Keyboard::W:
			speed_y = -5.f;
			break;
		case Keyboard::S:
			speed_y = 5.f;
			break;
		case Keyboard::A:
			speed_x = -5.f;
			break;
		case Keyboard::D:
			speed_x = 5.f;
			break;
	}
	if (event->type == Event::KeyReleased)
		switch (event->key.code) {
		case Keyboard::W:
			if (Keyboard::isKeyPressed(Keyboard::S))
				speed_y = 5.f;
			else
				speed_y = 0.f;
			break;
		case Keyboard::S:
			if (Keyboard::isKeyPressed(Keyboard::W))
				speed_y = 5.f;
			else
				speed_y = 0.f;
			break;
		case Keyboard::A:
			if (Keyboard::isKeyPressed(Keyboard::D))
				speed_x = 5.f;
			else
				speed_x = 0.f;
			break;
		case Keyboard::D:
			if (Keyboard::isKeyPressed(Keyboard::A))
				speed_x = -5.f;
			else
				speed_x = 0.f;
			break;

		case Keyboard::Equal:
			if (power < 3)power++;
			break;
		case Keyboard::Dash:
			if (power > 1)power--;
			break;
	}
}

int Player::update() {	
	if (currentTime > 60) {
		currentTime = 1;
		fireTime -= 60;
	}
	else
		currentTime++;

	move();

	if (Keyboard::isKeyPressed(Keyboard::Space) && fireTime < currentTime)
		shoot();

	/*for (unsigned int i = 0; i < bullets->size(); ++i)
		if ((*bullets)[i]->update())
			bullets->erase(bullets->begin() + i);*/

	return 0;
}

void Player::move() {
		pos_y += speed_y;
		pos_x += speed_x;

		if (pos_y < 0.f) pos_y = 0.f;
		if (pos_y > 670.f) pos_y = 670.f;
		if (pos_x < 188.f) pos_x = 188.f;
		if (pos_x > 833.f) pos_x = 833.f;
}

void Player::draw(RenderWindow* window) {
	sprite.setPosition(pos_x, pos_y);
	window->draw(sprite);

	/*hitbox.setRadius(hitbox_r);
	hitbox.setPosition(pos_x, pos_y);
	hitbox.setFillColor(Color::Red);
	window->draw(hitbox);*/

	/*for (auto b : bullets)
		b->draw(window);*/
}

void Player::shoot() {
	switch (power) {
	case 1:
		bullets->emplace_back(new Bullet(pos_x		 , pos_y - 10.f, 90.f , PLAYER, texManager));
		break;
	case 2:
		bullets->emplace_back(new Bullet(pos_x + 10.f, pos_y - 10.f, 90.f , PLAYER, texManager));
		bullets->emplace_back(new Bullet(pos_x - 10.f, pos_y - 10.f, 90.f , PLAYER, texManager));
		break;
	case 3:
		bullets->emplace_back(new Bullet(pos_x - 10.f, pos_y - 10.f, 70.f , PLAYER, texManager));
		bullets->emplace_back(new Bullet(pos_x		 , pos_y - 10.f, 90.f , PLAYER, texManager));
		bullets->emplace_back(new Bullet(pos_x + 10.f, pos_y - 10.f, 110.f, PLAYER, texManager));
		break;
	}

	fireTime = currentTime + 10;
}

Player::Player(TextureManager* tM, vector<Bullet*>* b, int i) {
	texManager = tM;

	sprite.setTexture(texManager->getTexture("player"));
	sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f);
	sprite.setColor(Color::Black);
	
	id = i;

	pos_x = 535.5f;
	pos_y = 650.f;
	life = 3;

	power = 1;
	special = 0;
	graze = 0;
	score = 0;

	fireTime = 0;
	currentTime = 0;	

	speed_x = 0.f;
	speed_y = 0.f;

	hitbox_r = 5.f;
	hitbox.setOrigin(hitbox_r, hitbox_r);
	hitbox_pos_x = sprite.getOrigin().x;
	hitbox_pos_y = sprite.getOrigin().y;

	bullets = b;
	
	live = true;
}


Player::~Player() {}
