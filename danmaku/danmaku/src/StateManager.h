#pragma once
#include "Includes.h"
#include "TextureManager.h"

#include "State.h"
#include "MenuState.h"
#include "GameState.h"
#include "ConnectState.h"
#include "QuitState.h"
#include "SplashState.h"

enum states{ MAINMENU, GAME, CONNECT, QUIT, SPLASH };


class StateManager {
private:
	State* activeState;
	vector<State*> states;
public:
	void setActiveState(State*);
	State* getActiveState();

	void newGame();

	State* getState(int);

	StateManager(Font, TextureManager*);
	virtual ~StateManager();
};

