#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

#define PAUSE() {cout << "Press enter to continue ...";cin.get();}

enum states{ MAINMENU, GAME, CONNECT, QUIT };

using namespace std;
using namespace sf;

const int FLIMIT = 10;