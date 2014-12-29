#include "Application.h"


void Application::appMainLoop() {
	while (window->isOpen()) {
		appEvent();
		appDraw();
	}
}

void Application::appDraw() {}

void Application::appEvent() {
	Event event;

	while (window->pollEvent(event)) {
		if (event.type == Event::KeyReleased) {
			switch (event.key.code) {
			case Keyboard::Escape:
				window->close();
				break;
			case Keyboard::Return:
				window->clear(Color::Black);
				window->display();
				break;
			}
		}
	}
}


Application::Application() {
	stManager = new StateManager();
	texManager = new TextureManager();
	aniHandler = new AnimationHandler();

	/*camera = new View();
	camera->setCenter(Vector2f(1280.0f / 2.0f, 720.0f / 2.0f));
	camera->setSize(Vector2f(1280, 720));*/

	window = new RenderWindow();
	window->create(VideoMode(1280, 720), "Kawai Danmaku With Pixels and Cats");
	window->setFramerateLimit(60);
	//window->setView(*camera);
	
	Vector2i windowPos = window->getPosition();
	windowPos.y -= 15;
	window->setPosition(windowPos);

	/* 'animated' splash screen */
	Sprite sprite;
	sprite.setTexture(texManager->getTexture("splashin"));

	Uint8 light = 10;
	/*	fade in */
	while (light < 210) {
		sprite.setColor(Color(light, light, light));
		window->draw(sprite);
		window->display();
		sleep(seconds(0.01f));
		light += 1;
	}
	sleep(seconds(0.05f));

	/*	fade out */
	while (light > 0) {
		sprite.setColor(Color(light, light, light));
		window->draw(sprite);
		window->display();
		sleep(seconds(0.01f));
		light -= 1;
	}
	/*							*/


}


Application::~Application() {}
